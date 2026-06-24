#include<stdio.h>
#include<dirent.h>

int main()
{
    struct dirent *d;
    DIR *dir=opendir(".");

    while((d=readdir(dir))!=NULL)
        printf("%s\n",d->d_name);

    closedir(dir);

    return 0;
}