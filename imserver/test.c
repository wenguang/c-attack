#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <ifaddrs.h>
#include <string.h>
#include <netinet/in.h>
#include <cstring>
#include <map>
#include <iterator>
#include <queue>
#include <vector>
#include <stdint.h>
#include <string>

struct stu
{
	int in;
	struct sockaddr addr;
};

int main(int argc, char* argv[])
{
	std::map<int, stu> mapSt; 
	return 0;
}
