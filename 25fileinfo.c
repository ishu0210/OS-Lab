#include<stdio.h>
#include<sys/stat.h>

int main()
{
    struct stat s;

    stat("sample.txt",&s);

    printf("File Size = %ld bytes",
           s.st_size);

    return 0;
}