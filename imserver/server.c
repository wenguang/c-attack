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

#include "errstr.h"

#define LISTEN_PORT 9001
#define EPOLL_SIZE  1024

int sockfd, epfd;
struct epoll_event *events;

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
	/*
	int nosigpipe = 1;
	if (setsockopt(sockfd, SOL_SOCKET, SO_NOSIGPIPE, &nosigpipe, sizeof(nosigpipe)) < 0)
	{
		close(sockfd);
		printf("! setsockopt() nosigpipe failed.\n");
		return -1;
	}
	*/
	
	struct sockaddr_in sockaddr;
	memset(&sockaddr, 0, (size_t)sizeof(sockaddr));
	sockaddr.sin_family = AF_INET;
	sockaddr.sin_port = htons(port);
	sockaddr.sin_addr.s_addr = inet_addr("127.0.0.1");//htonl(INADDR_ANY);

	if (bind(sockfd, (struct sockaddr *)&sockaddr, (socklen_t)sizeof(sockaddr)) < 0)
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

int main(int argc, char* argv[])
{
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