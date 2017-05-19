#include <unistd.h>  
#include <stdio.h>   
int main ()   
{   
    pid_t fpid;
    int count=0;  
    fpid=fork();   
    if (fpid < 0)   
        printf("error in fork!\n");   
    else if (fpid == 0)
    {  
        printf("child process, pid = %d\n",getpid());     
        count++;  
    }  
    else 
    {  
        printf("parent process, pid = %d\n",getpid());     
        count++;  
    }  
    printf("count: %d\n",count);  
    return 0;  
}  
