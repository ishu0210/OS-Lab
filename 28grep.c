#include<stdio.h>
#include<string.h>

int main()
{
    char str[100], word[20];

    printf("Enter sentence: ");
    gets(str);

    printf("Enter word: ");
    scanf("%s",word);

    if(strstr(str,word))
        printf("Word Found");
    else
        printf("Word Not Found");

    return 0;
}