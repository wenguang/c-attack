#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// 该函数一定要写在pthread_create前面
void * pmethod(void * arg)
{
	//若不想main线程被阻塞，就调用这句把tid分离出来，让tid线程和main线程可以并行执行
	pthread_detach(pthread_self());

	for (int i = 0; i < 10; ++i)
	{
		printf("A thread count : %d\n", i);
	}
	return (void *)9999;
}

int main()
{
	pthread_t tid;
	//错误：只允许在 C99 模式下使用‘for’循环初始化声明  使用 -std=c99 或 -std=gnu99 来编译
	for (int i = 0; i < 10; ++i)
	{
		printf("main thread count : %d\n", i);
		if (i == 2)
		{
			pthread_create(&tid, NULL, pmethod, NULL);

			//调用了pthread_join后，会阻塞main线程，等tid线程执行完才能回到main
			void *ret;
			pthread_join(tid, &ret);

			//在linux警告：将一个指针转换为大小不同的整数 [-Wpointer-to-int-cast] TODO:待解决
			//printf("A thread return %d\n", (int)ret);
		}
	}

	//调用了pthread_exit函数，只是使主线程退出，tid线程会继续执行完，若只是调用return，则会退出所有线程
	pthread_exit((void *)0);
	return 0;
}

/*
// 编译命令
// osx：gcc -join.c -o join
// centos: gcc -std=c99 join.c -o join -lpthread
//
// mac和centos上安装的gcc还是不一样的

centos: 
gcc (GCC) 4.8.5 20150623 (Red Hat 4.8.5-11)

osx:
Configured with: --prefix=/Applications/Xcode.app/Contents/Developer/usr --with-gxx-include-dir=/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.12.sdk/usr/include/c++/4.2.1
Apple LLVM version 8.0.0 (clang-800.0.42.1)
Target: x86_64-apple-darwin16.4.0
Thread model: posix
InstalledDir: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin
*/
