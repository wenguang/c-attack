
// 参考：http://blog.csdn.net/seanyxie/article/details/5804974

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <signal.h>
#include <netinet/in.h>
#include <string.h>
#include <errno.h>
#include <ifaddrs.h>
#include <fcntl.h>
#include <map>
#include <iterator>

#ifdef __APPLE__
#include <arpa/inet.h>
#endif

struct conn
{
	int sockfd;
	struct sockaddr *addr;
};

typedef std::map<int, conn> Mapin_t;
std::map<int, conn> conn_map; 

int main(int argc, char* argv[])
{
	int i;
	for (i = 0; i < 10; ++i)
	{
		struct sockaddr_in addrin;
		addrin.sin_family = AF_INET;
#ifdef __APPLE__
		addrin.sin_addr.s_addr = inet_addr("loopback");
#elif __linux__
		addrin.sin_addr.s_addr = inet_pton("loopback");
#endif
		addrin.sin_port = htons(1000 + i);

		struct conn cnn;
		cnn.sockfd = i;
		cnn.addr = (struct sockaddr *)&addrin;

		conn_map[i] = cnn;
	}

	Mapin_t::iterator it = conn_map.find(5);
	if (it == conn_map.end()) 
	{
		printf("! not found.\n");
	}
	else
	{
		conn cn = it->second;
		struct sockaddr_in *sin = (struct sockaddr_in *)cn.addr;
		int port = ntohs(sin->sin_port);
		
		printf("- found port = %d.\n", port);

		// del
		conn_map.erase(it);
	}

	return 0;
}