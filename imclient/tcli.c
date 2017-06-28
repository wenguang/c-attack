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
#include <sys/stat.h>


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
	inet_pton(AF_INET, "113.65.129.37", &sockaddr.sin_addr);
	
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
	printf("- non-block mode\n");
	
	int sndbufsize;
	int sbflen = sizeof(int);
	getsockopt(sockfd, SOL_SOCKET, SO_SNDBUF, &sndbufsize, (socklen_t *)&sbflen);
	printf("- snd buf size = %d\n", sndbufsize);

	int bufsize = 4096;
	int len = sizeof(bufsize);
	setsockopt(sockfd, SOL_SOCKET, SO_SNDBUF, &bufsize, (socklen_t)len);
	printf("- setting snd buf size...\n");

	getsockopt(sockfd, SOL_SOCKET, SO_SNDBUF, &sndbufsize, (socklen_t *)&sbflen);
	printf("- snd buf size = %d\n", sndbufsize);


	char input;
	while (1)
	{
		char msg[161];
		fgets(msg, 161, stdin);
		// replace '\n' with '\0'
		char *tmp = strchr(msg, '\n');
		if (tmp) *tmp = '\0';

		if (send(sockfd, &msg, sizeof(msg), 0))
		{
			printf("- send %s\n", msg);
		}
		else
		{
			printf("! send failed.\n");
		}
	} 

/*
int i = 0;
for (i = 0; i < 1; ++i)
{
	int fd = open("./tt.txt", O_RDONLY);
	struct stat sta;
	fstat(fd, &sta);
	int fsize = sta.st_size;
	printf("- file size = %d bytes\n", fsize);
	char buf[fsize];
	int rlen = read(fd, &buf, fsize);
	//printf("- read size = %d\n", rlen);
	int slen = send(sockfd, &buf, rlen, 0);
	printf("- send size = %d\n", slen);
	if (slen == -1)
	{
		 if (errno == EAGAIN || errno == EWOULDBLOCK)
		 {
		 	printf("! EAGAIN or EWOULDBLOCK\n");
		 }
	}
	close(fd);	

	//sleep(3);
}
*/

	close(sockfd);
	//shutdown(sockfd, 0);
	printf("- socket close\n");

	while(1){}

	return 0;
}


