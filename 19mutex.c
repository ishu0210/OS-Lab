#include<stdio.h>

int main()
{
    int lock=0;

    if(lock==0)
    {
        lock=1;
        printf("Resource Locked\n");

        lock=0;
        printf("Resource Released\n");
    }

    return 0;
}