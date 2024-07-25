#include<stdio.h>
#include<string.h>

void onescomp(char []);
void twoscomp(char []);

int main()
{
    char binary[32];
    int c;
    printf("Enter the Number: ");
    scanf("%s",binary);
    printf("1. One's complement\n");
    printf("2. Two's complement\n");
    printf("3. Exit\n");
    printf("Enter the choice :");
    scanf("%d",&c);
    switch(c){
        case 1:
            onescomp(binary);
            break;
        case 2:
            twoscomp(binary);
            break;
        case 3:
            break;
        default:
            printf("Invalid choice.");
            break;

    }
    return 0;
}

void onescomp(char* n)
{
    int len = strlen(n);
    int i;
    for(i=0;i<=len;i++){
        if(n[i] == '1'){
            n[i] = '0';
        }
        else if(n[i] == '0'){
            n[i] = '1';
        }
    }
    printf("One's complement: %s\n", n); // Optionally print the result

}

void twoscomp(char* n)
{
    int len = strlen(n);
    int carry = 1;

    onescomp(n);

    for(int i = (len - 1); i >= 0 ; i--)
    {
        if(n[i] == '1' && carry == 1){
            n[i] = '0';
        }
        else if(n[i] == '0' && carry == 1){
            n[i] = '1';
            carry=0;
        }
    }

    printf("Two's complement: %s\n", n); // Optionally print the result
}