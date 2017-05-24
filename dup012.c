#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char* argv[])
{
	// 以下open语句在dup.txt存在情况，mac上执行失败，linux上成功
	int fd = open("./dup.txt", O_RDWR | O_CREAT | O_TRUNC);
	if (fd < 0)
	{
		printf("- open file failed !\n");
		return -1;
	}

	//dup(0);
	dup2(fd, STDIN_FILENO);
	int a;
	scanf("%d", &a);

	// 把标准输出重定向到dup.txt上
	// 它实际上是让STDOUT_FILENO（即文件描述符1）指向fd所指向的文件表项
	// 在dup2之前，printf的内容输出到终端上，指向是这样的
	// printf －> stdout －> STDOUT_FILENO(1) －> 终端(tty)
	// tty也是一个文件：/dev/tty。  这符合Unix上一切皆文件的思想
	// 在dup2之前，printf的内容就输出到dup.txt上，指向变这样了
	// printf －> stdout －> STDOUT_FILENO(1) －> dup.txt
	dup2(fd, STDOUT_FILENO);
	printf("instead of displaying in tty, out to the file\n");

	close(fd);

	return 0;
}