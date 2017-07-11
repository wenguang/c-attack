#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	printf("char 's len = %lu bits\n", sizeof(char) * 8);
	printf("unsigned char 's len = %lu bits\n", sizeof(unsigned char) * 8);
	printf("short 's len = %lu bits\n", sizeof(short) * 8);
	printf("unsigned short 's len = %lu bits\n", sizeof(unsigned short) * 8);
	printf("int 's len = %lu bits\n", sizeof(int) * 8);
	printf("unsigned int 's len = %lu bits\n", sizeof(unsigned int) * 8);
	printf("long 's len = %lu bits\n", sizeof(long) * 8);
	printf("unsigned long 's len = %lu bits\n", sizeof(unsigned long) * 8);
	printf("long long 's len = %lu bits\n", sizeof(long long) * 8);
	printf("unsigned long long 's len = %lu bits\n", sizeof(unsigned long long) * 8);

	return 0;
}