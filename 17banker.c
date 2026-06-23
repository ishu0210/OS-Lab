#include<stdio.h>

int main()
{
    int available[3]={3,3,2};
    int request[3];

    printf("Enter Request A B C: ");
    scanf("%d%d%d",&request[0],
                  &request[1],
                  &request[2]);

    if(request[0]<=available[0] &&
       request[1]<=available[1] &&
       request[2]<=available[2])
        printf("Request Granted");
    else
        printf("Request Denied");

    return 0;
}