#include<stdio.h>

void dectobin(int );

int main(){
    int num;
    printf("Enter the Number: ");
    scanf("%d",&num);
    dectobin(num);
    return 0;
}

void dectobin(int num){
    int binarynum[32];
    int i = 0;
    while(num > 0){
        binarynum[i] = num % 2;
        num = num / 2;
        i++;
    }
    printf("Your binary number is: ");
    for(int j = i - 1;j >= 0;j--){
        printf("%d",binarynum[j]);
    }

}

