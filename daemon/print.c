#include <stdio.h>
#include <fcntl.h>
#include <time.h>
#include <unistd.h>

int main()
{
	int fd = open("print.txt", O_CREAT | O_RDWR | O_APPEND);
	if (fd == -1)
	{
		printf("! open failed.\n");
		return -1;
	}
	if (dup2(fd, STDOUT_FILENO) == -1)
	{
		printf("! dup2 failed.\n");
		return -1;
	}

	int i = 0;
	printf("\n-----------  %s  -----------\n\n", asctime(NULL));
	for (i = 0; i < 3; ++i)
	{
		printf("- daemon print message line %d\n", i);
	}
	return 0;
}
