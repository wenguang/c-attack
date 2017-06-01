#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <ifaddrs.h>
#include <string.h>
#include <netinet/in.h>

int getaddr(struct sockaddr *sa)
{
    struct ifaddrs *addrs;
    const struct ifaddrs *cursor;
    
    if (getifaddrs(&addrs) < 0)
    {
        printf("! getifaddrs() failed.\n");
        exit(-1);
    }

    cursor = addrs;
    while(cursor)
    {
        char* enp0s3 = "enp0s3";
        if (cursor->ifa_addr->sa_family == AF_INET && strcmp(cursor->ifa_name, enp0s3) == 0)
        {
            memcpy(sa, cursor->ifa_addr, (size_t)sizeof(sa));
            printf("- %s\n", cursor->ifa_name);
	    break;
        }
        cursor = cursor->ifa_next;
    }
    
    free(addrs);

}

int main(int argc, char* argv[])
{

    struct sockaddr sa;
    getaddr(&sa);

	// struct ifaddrs *addrs;
	// const struct ifaddrs *cursor;
	// struct sockaddr sockaddr;
	
	// if (getifaddrs(&addrs) < 0)
	// {
	// 	printf("! getifaddrs() failed.\n");
	// 	exit(-1);
	// }

	// cursor = addrs;
 //        while(cursor)
 //        {
	// 	//memcpy(&sockaddr, cursor->ifa_addr, (size_t)sizeof(sockaddr));
 //        	//printf("- %s\n", cursor->ifa_name);
	// 	if (cursor->ifa_addr->sa_family == AF_INET)
	// 		printf("- %s\n", cursor->ifa_name);
 //      		cursor = cursor->ifa_next;
	// }
	
	// free(addrs);

	return 0;
}
