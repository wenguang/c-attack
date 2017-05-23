#include <stdio.h>
#include <unistd.h>

// 显示当前进程的实际用户ID、有效用户ID、保存的设置用户ID
int main (void)
{
#ifdef __linux__
	uid_t ruid, euid, suid;

	setuid(501);
	// mac没有getresuid函数定义
	getresuid(&ruid, &euid, &suid);
	printf("current process 3 uid :\nreal uid = %d\neffective uid = %d\nsaved uid = %d\n", ruid, euid, suid);
#endif
	return 0;
}