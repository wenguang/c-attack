#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <signal.h>
#include <netinet/in.h>
#include <errno.h>
#include <ifaddrs.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include <netinet/tcp.h>
#include <string.h>

#define LISTEN_PORT 9001
#define EPOLL_SIZE  1024

static int psockfd, epfd;

int getifaddr(struct sockaddr_in *sa)
{
    struct ifaddrs *addrs;
    const struct ifaddrs *cursor;
    
    if (getifaddrs(&addrs) < 0)
    {
        printf("! getifaddrs() failed.\n");
        exit(-1);
    }

    cursor = addrs;
    while(cursor)
    {
        char* enp0s3 = "enp0s3";
        if (cursor->ifa_addr->sa_family == AF_INET && strcmp(cursor->ifa_name, enp0s3) == 0)
        {
            memcpy(sa, cursor->ifa_addr, (size_t)sizeof(sa));
            printf("- %s\n", cursor->ifa_name);
	    break;
        }
        cursor = cursor->ifa_next;
    }
    
    free(addrs);
    return 0;
}

int servsock(int port)
{
	psockfd = socket(AF_INET, SOCK_STREAM, 0);
   	if (psockfd < 0)
	{
    	printf("! servsock()-socket() failed.\n");
    	return -1;
	}

	int reuseOn = 1;
	if (setsockopt(psockfd, SOL_SOCKET, SO_REUSEADDR, &reuseOn, sizeof(reuseOn)) < 0)
	{
    	close(psockfd);
    	printf("! servsock()-setsockopt() failed.\n");
    	return -1;
	}

	int flags;
	if ((flags = fcntl(psockfd, F_GETFL)) < 0)
	{
		printf("! servsock()-fcntl() get failed.\n");
		return -1;
	}
	flags |= O_NONBLOCK;
	if (fcntl(psockfd, F_SETFL, flags) < 0)
	{
		printf("! servsock()-fcntl() set failed.\n");
		return -1;	
	}

	struct sockaddr_in addr4;
	memset(&addr4, 0, (size_t)sizeof(addr4));
	getifaddr(&addr4);
	addr4.sin_port = htons(port);

	if (bind(psockfd, (struct sockaddr *)&addr4, (socklen_t)sizeof(addr4)) < 0)
	{
		close(psockfd);
		printf("! servsock()-bind() failed.\n");
		return -1;
	}

	if (listen(psockfd, 1024) < 0)
	{
		close(psockfd);
		printf("! servsock()-listen() failed.\n");
		return -1;
	}

	return psockfd;
}

int accept_connd(struct sockaddr *addr)
{
	int csockfd;
	socklen_t addrlen = sizeof(*addr);
	if ((csockfd = accept(psockfd, addr, &addrlen)) < 0)
	{
		if (errno == EAGAIN || errno == EWOULDBLOCK)
		{
			// 已经没有在等待的连接了
			return 0;
		}

		printf("! accept_connd()-accept() failed.\n");
		return -1;
	}

	int flags;
	if ((flags = fcntl(csockfd, F_GETFL)) < 0)
	{
		printf("! accept_connd()-fcntl() get failed.\n");
		return -1;
	}
	flags |= O_NONBLOCK;
	if (fcntl(csockfd, F_SETFL, flags) < 0)
	{
		printf("! accept_connd()-fcntl() set failed.\n");
		return -1;	
	}


	printf("- new conn accepted, sockfd = %d.\n", csockfd);

	struct sockaddr_in *acceptaddr4 = (struct sockaddr_in *)addr;
	char acceptaddr4ip[16];
	inet_ntop(AF_INET, &acceptaddr4->sin_addr, acceptaddr4ip, (socklen_t)sizeof(acceptaddr4ip));
	printf("- new conn from %s:%d\n", acceptaddr4ip, ntohs(acceptaddr4->sin_port));

// The address getting from accept func is not the same one getting from getpeername func.
/*
	struct sockaddr *localaddr;
	socklen_t llen = (socklen_t)sizeof(*localaddr);
	getsockname(csockfd, localaddr, &llen);
	struct sockaddr_in *localaddr4 = (struct sockaddr_in *)localaddr;
	char localaddr4ip[16];
	inet_ntop(AF_INET, &localaddr4->sin_addr, localaddr4ip, (socklen_t)sizeof(localaddr4ip));
	printf("- new conn 's local addr is %s:%d\n", localaddr4ip, ntohs(localaddr4->sin_port));

	struct sockaddr *peeraddr;
	socklen_t plen = (socklen_t)sizeof(*peeraddr);
	if (getpeername(csockfd, peeraddr, &plen) < 0)
	{
		printf("! accept_connd()-getpeername() failed.\n");
		printerr();
	} 
	else
	{
		struct sockaddr_in *peeraddr4 = (struct sockaddr_in *)peeraddr;
		char peeraddr4ip[16];
		inet_ntop(AF_INET, &peeraddr4->sin_addr, peeraddr4ip, (socklen_t)sizeof(peeraddr4ip));
		printf("- new conn 's peer addr is %s:%d\n", peeraddr4ip, ntohs(peeraddr4->sin_port));
	}
*/

	return csockfd;
}

void clean()
{
	close(psockfd);
}

int main(int argc, char* argv[])
{

	printf("\n-------------------  server  -------------------\n");	

	signal(SIGPIPE, SIG_IGN);

	if ((psockfd = servsock(LISTEN_PORT)) < 0)
	{
		exit(-1);
	}
	
	while(1)
	{
		struct sockaddr addr;
		accept_connd(&addr);
	}

	clean();
	
    return 0;
}
