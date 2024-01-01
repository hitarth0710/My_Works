#include<stdio.h>
#include<string.h>
void main()
{
    char s1[50],s2[50];
    gets(s1);
    strcpy(s2,s1);
    strrev(s1);
    if(strcmp(s1,s2)==0)
    {
        printf("its");
    }
    else
    {
        printf("not");
    }
}
