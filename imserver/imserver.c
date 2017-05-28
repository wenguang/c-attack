#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <signal.h>
#include <netinet/in.h>
#include <string.h>
#include <errno.h>

#include "errstr.h"

int servsock(int port)
{
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
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

int main(int argc, char* argv[])
{
	int sockfd = servsock(9001);
	if (sockfd < 0)
	{
		exit(-1);
	}

	close(sockfd);
	
    return 0;
}
