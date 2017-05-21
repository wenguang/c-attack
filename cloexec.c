#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
	// O_CLOEXEC
	int fd0 = open("./README.md", O_CREAT | O_RDONLY | O_CLOEXEC);
	if (fd0 < 0)
	{
		printf("! open file failed.");
		exit(-1);
	}
	close(fd0);

	// FD_CLOEXEC
	int fd1 = open("./README.md", O_CREAT | O_RDONLY);
	if (fd1 < 0)
	{
		printf("! open file failed.");
                exit(-1);
	}
	
	int flags = fcntl(fd1, F_GETFD);
	flags |= FD_CLOEXEC;
	fcntl(fd1, F_SETFD, flags);

	close(fd1);

	return 0;
}
