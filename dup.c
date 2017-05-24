#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char* argv[])
{
	int fd = open("./README.md", O_RDONLY);
	int fdflag = fcntl(fd, F_GETFD);
	printf("before dup, fd %d fflag = %d\n", fd, fdflag);

	// 复制一个新的文件描述符，新旧两人FD指向共享一个文件表项
	int newfd = dup(fd);

	fdflag = fcntl(fd, F_GETFD);
	int newfd_flag = fcntl(newfd, F_GETFD);

	printf("after dup, fd %d fflag = %d\n", fd, fdflag);
	printf("new fd %d fflag = %d\n", newfd, newfd_flag);

	close(fd);

	int oflag = fcntl(fd, F_GETFL);
	int new_oflag = fcntl(newfd, F_GETFL);
	printf("after close fd, fd oflag = %d\n", oflag);	// oflag为-1，fcntl函数只对已打开的文件有效，对close掉的文件失败
	printf("after close fd, newfd oflag = %d\n", new_oflag);

	close(newfd);

	return 0;
}