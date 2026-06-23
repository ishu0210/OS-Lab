#include<stdio.h>

int main()
{
    int block[3]={100,500,200};
    int process=150;
    int largest=0;

    for(int i=1;i<3;i++)
    {
        if(block[i]>block[largest])
            largest=i;
    }

    printf("Process allocated to block %d",
            largest+1);

    return 0;
}