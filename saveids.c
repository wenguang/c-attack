#include <stdio.h>
#include <unistd.h>

// 验证是否支持"保存的设置用户ID"这个功能
int main(void)
{
    if(sysconf(_SC_SAVED_IDS) > 0)
    {
        printf("_POSIX_SAVED_IDS effective!\n");
    }
    else
    {
       printf("_POSIX_SAVED_IDS NOT effective!\n");
    }

    return 0;
}
