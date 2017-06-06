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

#ifdef __APPLE__
#include <arpa/inet.h>
#endif


// #include "errstr.h"

#define SERVER_PORT 9001


int main(int argc, char* argv[])
{
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
   	if (sockfd < 0)
	{
    		printf("! socket() failed.\n");
   		// printerr();
    		exit(-1);
	}

	int reuseOn = 1;
	if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &reuseOn, sizeof(reuseOn)) < 0)
	{
    		close(sockfd);
    		printf("! setsockopt() failed.\n");
    		// printerr();
    		exit(-1);
	}

	signal(SIGPIPE, SIG_IGN);
	
	struct sockaddr_in sockaddr;
	memset(&sockaddr, 0, (size_t)sizeof(sockaddr));
	sockaddr.sin_family = AF_INET;
	sockaddr.sin_port = htons(SERVER_PORT);
	inet_pton(AF_INET, "192.168.1.104", &sockaddr.sin_addr);
	
	if (connect(sockfd, (struct sockaddr *)&sockaddr, (socklen_t)sizeof(sockaddr)) < 0)
	{
		close(sockfd);
    		printf("! connect() failed.\n");
    		// printerr();
    		exit(-1);
	}
	printf("- connected.\n");

	int flags = fcntl(sockfd, F_GETFL);
	flags |= O_NONBLOCK;
	fcntl(sockfd, F_SETFL, flags);


	char input;
	while (1)
	{
		scanf("%c", &input);
		if (input == 'q')
			break;

		char *msg = "hello world"
		if (write(sockfd, &msg, sizeof(msg))
		{
			printf("- send %s\n", msg);
		}
		else
		{
			printf("! send failed.\n");
		}
	} 

	close(sockfd);
	//shutdown(sockfd, 0);

	printf("x call close.\n");

	while(1){}

	return 0;
}
