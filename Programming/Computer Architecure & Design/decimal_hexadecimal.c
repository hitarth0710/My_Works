#include<stdio.h>

void dectohex(int );

int main(){
    int num;
    printf("Enter the Number: ");
    scanf("%d",&num);
    dectohex(num);
    return 0;
}

void dectohex(int n){
    int i = 0;
    int temp;
    char hexanum[32];
    while(n > 0){
        temp = n % 16;
        if(temp < 10){
            hexanum[i] = temp + '0';
        }else{
            hexanum[i] = temp + 55;
        }
        n = n / 16;
        i++;
    }

    printf("Your hexademical number is : 0x");
    for(int j = i - 1;j >= 0;j--){
        printf("%c",hexanum[j]);
    }
}