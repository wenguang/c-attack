#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#include "errstr.h"

#define SERVER_PORT 9001


int main(int argc, char* argv[])
{
	signal(SIGPIPE, SIG_IGN);

	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
   	if (sockfd < 0)
	{
    		printf("! socket() failed.\n");
   		printerr();
    		exit(-1);
	}

	int reuseOn = 1;
	if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &reuseOn, sizeof(reuseOn)) < 0)
	{
    		close(sockfd);
    		printf("! setsockopt() failed.\n");
    		printerr();
    		exit(-1);
	}
	
	struct sockaddr_in sockaddr;
	memset(&sockaddr, 0, (size_t)sizeof(sockaddr));
	sockaddr.sin_family = AF_INET;
	sockaddr.sin_port = htons(SERVER_PORT);
	inet_pton(AF_INET, "192.168.1.104", &sockaddr.sin_addr);
	
	if (connect(sockfd, (struct sockaddr *)&sockaddr, (socklen_t)sizeof(sockaddr)) < 0)
	{
		close(sockfd);
    		printf("! connect() failed.\n");
    		printerr();
    		exit(-1);
	}
	printf("- connected.\n");

	int flags = fcntl(sockfd, F_GETFL);
	flags |= O_NONBLOCK;
	if (fcntl(sockfd, F_SETFL, flags) < 0)
	{
		close(sockfd);
		printf("! fcntl() failed.\n");
		printerr();
		exit(-1);
	}

	while(1){}

	close(sockfd);

	return 0;
}
