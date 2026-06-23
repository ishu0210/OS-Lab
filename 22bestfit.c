#include<stdio.h>

int main()
{
    int block[3]={100,500,200};
    int process=150;
    int best=1;

    for(int i=0;i<3;i++)
    {
        if(block[i]>=process &&
           block[i]<block[best])
            best=i;
    }

    printf("Process allocated to block %d",
            best+1);

    return 0;
}