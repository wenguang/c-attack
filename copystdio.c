#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFSIZE 8192

// ！程序很奇怪，看不懂

int main(int argc, char* argv[])
{
	int n;
	char buf[BUFFSIZE];

	while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
	{
		if (write(STDOUT_FILENO, buf, n) != n)
			// 不会有输出的，因为STDOUT被重定向到/dev/null
			printf("! write error.");
		else
			printf("- copy %d bytes", n);
	}
	if (n < 0)
		printf("! read error.");
	exit(0);
}
