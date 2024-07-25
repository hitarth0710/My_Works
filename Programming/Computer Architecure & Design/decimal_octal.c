#include<stdio.h>

void dectooct(int );

int main(){
    int num;
    printf("Enter the Number: ");
    scanf("%d",&num);
    dectooct(num);
    return 0;
}

void dectooct(int num){
    int octnum[32];
    int i = 0;
    while(num > 0){
        octnum[i] = num % 8;
        num = num / 8;
        i++;
    }
    printf("Your hexademical number is : 0");
      for(int j = i - 1;j >= 0;j--){
        printf("%d",octnum[j]);
    }

}