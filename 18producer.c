#include<stdio.h>

int main()
{
    int buffer=0, item;

    printf("Enter item to produce: ");
    scanf("%d",&item);

    buffer=item;

    printf("Produced: %d\n",buffer);

    printf("Consumed: %d\n",buffer);

    return 0;
}