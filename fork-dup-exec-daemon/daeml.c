#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <signal.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		printf("! 缺少参数，没有指定daemon程序名字\n");
		return -1;
	}
	printf("\n");
	printf("- 启动 %s 作为守护进程......\n\n\n", argv[1]);

	// 1 fork 子进程，让父进程退出，确保可以创建新会话，因为只有非会话进程组长才能创建新会话
	switch(fork())
	{
		case -1 : return -1;
		case 0  : break;
		default : _exit(0);
	}
	//printf("1 fork 子进程，让父进程退出，确保可以创建新会话，因为只有非会话进程组长才能创建新会话\n\n\n");

	// 2 创建新会话，从父进程的所在会话的tty，这里子进程变成了新会话进程组长
	if (setsid() == -1)
	{
		//printf("! setsid() failed.\n");
		return -1;
	}
	//printf("2 创建新会话，从父进程的所在会话的tty，这里子进程变成了新会话进程组长\n\n\n");
	//while(1)
	//	printf("00000\n");
	// 若在这句就return掉，且关掉tty，还是会在活动进程中看到a.out，就说明了第2步后进程就脱离了tty的控制

	// if (setuid(1) < 0)
	// {
	// 	printf("! setuid failed.\n");
	// 	return -1;	
	// }
	
	// 3 fork 子进程，再脱离会话进程组长的角色，这就禁止了进程重新打开tty，因为只以会话进程组长才能重新打开tty，这步不是必须的
	switch(fork())
	{
		case -1 : return -1;
		case 0  : break;
		default : _exit(0);
	}
	//printf("3 fork 子进程，再脱离会话进程组长的角色，这就禁止了进程重新打开tty，因为只以会话进程组长才能重新打开tty\n\n\n");

	// 4 设置进程的当前工作目录为根目录，防止工作目录被删除
	// ！！！调用了chdir不能成功启动守护进程，注释掉就可以了，以root权限调用也不行
	/*if (chdir("/") == -1)
	{
		printf("! chdir() failed.\n\n\n");
		return -1;
	}
	//printf("4 设置进程的当前工作目录为根目录\n\n\n");
	*/	

	// 5 重设创建文件时权限屏蔽码
	umask(0);
	//printf("5 重设创建文件时权限屏蔽码\n\n\n");

	//printf("- 启动 %s 作为守护进程......\n\n\n", argv[1]);

	// 6 关闭不再需要的FD，这样让守护进程不再持有从父进程继承来的FD
	int limit = sysconf(_SC_OPEN_MAX);
	int fd = 0;
	while(fd < limit)
	{
		close(fd++);
	}
	// 这个步骤会把STDOUT_FILENO也关闭掉，所以下面就不要下面的输出了
	//printf("6 关闭不再需要的FD，这样让守护进程不再持有从父进程继承来的FD\n\n\n");

	// 7、忽略子进程的结束信号，让内核处理，避免僵尸进程浪费系统资源
	signal(SIGCHLD, SIG_IGN);
	//printf("7、忽略子进程的结束信号，让内核处理，避免僵尸进程浪费系统资源\n\n\n");

	// 8、调用新程序代换当前进程程序，exec并不创建新进程，调用成功后，后面的语句就不会执行
	//printf("- 启动 %s 作为守护进程......\n\n\n", argv[1]);
	execv(argv[1], argv + 1);

	printf("! 启动守护进程失败\n\n\n");
	exit(0);

	return 0;
}
