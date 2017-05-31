#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <signal.h>
#include <netinet/in.h>
#include <string.h>
#include <errno.h>
#include <sys/epoll.h>
#include <ifaddrs.h>
#include <fcntl.h>

#include "errstr.h"

#define LISTEN_PORT 9001
#define EPOLL_SIZE  1024

int sockfd, epfd;
struct epoll_event *events;

int getaddr(struct sockaddr_in *sa)
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

}

int servsock(int port)
{
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
   	if (sockfd < 0)
    	{
        	printf("! servsock()-socket() failed.\n");
       	 	printerr();	
        	return -1;
    	}

    	int reuseOn = 1;
    	if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &reuseOn, sizeof(reuseOn)) < 0)
    	{
        	close(sockfd);
        	printf("! servsock()-setsockopt() failed.\n");
        	printerr();
        	return -1;
    	}

    	signal(SIGPIPE, SIG_IGN);
	
	
	struct sockaddr_in addr4;
	/*
	memset(&addr4, 0, (size_t)sizeof(addr4));
	addr4.sin_family = AF_INET;
	addr4.sin_port = htons(port);
	addr4.sin_addr.s_addr = inet_addr("127.0.0.1");//htonl(INADDR_ANY);
	*/

	getaddr(&addr4);
	addr4.sin_port = htons(port);

	if (bind(sockfd, (struct sockaddr *)&addr4, (socklen_t)sizeof(addr4)) < 0)
	{
		close(sockfd);
		printf("! servsock()-bind() failed.\n");
		printerr();
		return -1;
	}

	if (listen(sockfd, 1024) < 0)
	{
		close(sockfd);
		printf("! servsock()-listen() failed.\n");
		printerr();
		return -1;
	}

	return sockfd;
}

int add_to_epoll(int fd)
{
	if (epfd <= 0)
	{
		printf("! add_to_epoll() failed, epfd is null.\n");
		return -1;
	}

	struct epoll_event event;
	event.data.fd = fd;
	event.events = EPOLLIN | EPOLLERR | EPOLLET;

	if (epoll_ctl(epfd, EPOLL_CTL_ADD, fd, &event) < 0)
	{
		printf("! add_to_epoll()-epoll_ctl() failed.\n");
		printerr();
		return -1;
	}

	return 0;
}

int del_from_epoll(int fd)
{
	if (epfd <= 0)
        {
                printf("! del_from_epoll() failed, epfd is null.\n");
                return -1;
        }
	
	struct epoll_event event;
        event.data.fd = fd;
        event.events = EPOLLIN | EPOLLERR | EPOLLET;

	if (epoll_ctl(epfd, EPOLL_CTL_DEL, fd, &event) < 0)
        {
                printf("! del_from_epoll()-epoll_ctl() failed.\n");
                printerr();
                return -1;
        }

        return 0;
}

void clean()
{
	free(events);
	close(epfd);
	close(sockfd);
}

void stdout_to_file()
{
	int fd = open("server.out", O_CREAT | O_RDWR | O_APPEND);
	if (fd == -1)
	{
		printf("! open failed.\n");
		return;
	}
	if (dup2(fd, STDOUT_FILENO) == -1)
	{
		printf("! dup2 failed.\n");
		return;
	}
}

int main(int argc, char* argv[])
{
	//stdout_to_file();

	printf("\n-------------------  server  -------------------\n\n");	

	if ((epfd = epoll_create(EPOLL_SIZE)) < 0)
	{
		printf("! epoll_create() failed.\n");
		printerr();
		exit(-1);
	}

	if ((sockfd = servsock(LISTEN_PORT)) < 0)
	{
		exit(-1);
	}

	if (add_to_epoll(sockfd) < 0)
	{
		exit(-1);
	}
	
	struct epoll_event event;
	events = (struct epoll_event *)calloc(EPOLL_SIZE, sizeof(event));

	int nfds = 0;
	while(1)
	{
		if ((nfds = epoll_wait(epfd, events, EPOLL_SIZE, -1)) > 0)
		{
			printf("- epoll_wait() return %d events.\n", nfds);
			int i;
			for (i=0; i<nfds; i++)
			{
				
			}
		}
		else
		{
			printf("- epoll_wait() timeout.\n");
		}
	}

	clean();
	
    return 0;
}
