#include<stdio.h>
#include<math.h>
#include<string.h>

void bintodec(char []);

int main()
{
    char num[32];
    printf("Enter the Number: ");
    scanf("%s",&num);
    bintodec(num);
    return 0;
}

void bintodec(char* n)
{
    int num = 0;
    int i = 0;
    int len = strlen(n);
    for(i;i <= len ;i++){
        if(n[i] == '1'){
            num = num + pow(2,len - i - 1);
        }
    }
    printf("Your Decimal Number is: %d\n",num);
}