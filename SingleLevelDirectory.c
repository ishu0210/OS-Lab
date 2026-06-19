#include <stdio.h>

int main()
{
    FILE *fp;

    fp = fopen("sample.txt","w");

    if(fp==NULL)
    {
        printf("File creation failed");
        return 1;
    }

    printf("File created successfully\n");

    fclose(fp);

    return 0;
}