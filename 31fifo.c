#include<stdio.h>

int main()
{
    int pages[]={1,2,3,4,1};
    int frames[3]={-1,-1,-1};

    int faults=0,index=0;

    for(int i=0;i<5;i++)
    {
        frames[index]=pages[i];
        index=(index+1)%3;
        faults++;
    }

    printf("Page Faults=%d",faults);

    return 0;
}