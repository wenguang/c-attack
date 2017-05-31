#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <ifaddrs.h>
#include <netinet/in.h>

//enp0s3

int getaddr(struct sockaddr *sa)
{
	struct ifaddrs *addrs;
        const struct ifaddrs *cursor;
        struct sockaddr sockaddr;

        if (getifaddrs(&addrs) < 0)
        {
                printf("! getifaddrs() failed.\n");
                exit(-1);
        }

        cursor = addrs;
        while(cursor)
        {
                //memcpy(&sockaddr, cursor->ifa_addr, (size_t)sizeof(sockaddr));
                //                //printf("- %s\n", cursor->ifa_name);
                //                                if (cursor->ifa_addr->sa_family == AF_INET)
                //                                                        printf("- %s\n", cursor->ifa_name);
                //                                                                        cursor = cursor->ifa_next;
                //                                                                                }
                //
                //                                                                                        free(addrs);	
}

int main(int argc, char* argv[])
{
	struct ifaddrs *addrs;
	const struct ifaddrs *cursor;
	struct sockaddr sockaddr;
	
	if (getifaddrs(&addrs) < 0)
	{
		printf("! getifaddrs() failed.\n");
		exit(-1);
	}

	cursor = addrs;
        while(cursor)
        {
		//memcpy(&sockaddr, cursor->ifa_addr, (size_t)sizeof(sockaddr));
        	//printf("- %s\n", cursor->ifa_name);
		if (cursor->ifa_addr->sa_family == AF_INET)
			printf("- %s\n", cursor->ifa_name);
      		cursor = cursor->ifa_next;
	}
	
	free(addrs);

	return 0;
}
