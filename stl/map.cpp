#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <map>
#include <iterator>

struct conn
{
	int sockfd;
	struct sockaddr addr;
};

typedef std::map<int, int> Mapin_t;

std::map<int, int> in_map;
//std::map<int, conn> conn_map; 

int main(int argc, char* argv[])
{
	int i;
	for (i = 0; i < 10; ++i)
	{
		in_map[i] = i*10;
	}

	Mapin_t::iterator it = in_map.find(5);
	if (it == in_map.end()) 
	{
		printf("! not found.\n");
	}
	else
	{
		int v = it->second;
		printf("- %d\n", v);
	}

	return 0;
}