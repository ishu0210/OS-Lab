#include<stdio.h>

int main()
{
    int block[3]={100,500,200};
    int process=150;

    for(int i=0;i<3;i++)
    {
        if(block[i]>=process)
        {
            printf("Allocated to block %d",
                    i+1);
            break;
        }
    }

    return 0;
}