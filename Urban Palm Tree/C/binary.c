#include <stdio.h>

// Function to convert a decimal number to binary
void decToBinary(int n) {
    int binaryNum[32];
    int i = 0;
    while (n > 0) {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--)
        printf("%d", binaryNum[j]);
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Binary representation of input: ");
    decToBinary(num);
    printf("\n");

    num = num << 5; // left shift operation

    printf("Number in Decimal :%d",num);

    printf("\nBinary representation after left shift: ");
    decToBinary(num);

    return 0;
}
