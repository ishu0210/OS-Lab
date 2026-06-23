#include<stdio.h>

int main()
{
    FILE *fp;

    fp=fopen("sample.txt","w");

    fprintf(fp,"Operating Systems");

    fclose(fp);

    printf("File Created");

    return 0;
}