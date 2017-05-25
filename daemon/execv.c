#include <unistd.h>

int main(int argc, char* argv[])
{
	//char *argv[] = {"ls", "-al", "/etc/passwd", (char*)NULL};
	execv(argv[1], argv + 1);
	return 0;
} 