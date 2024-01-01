//to store 10 numbers in a array and find which is maximum and minimum
#include <stdio.h>
  int main() {
    int a[10];
    int i;
    int greatest,lowest;
    printf("Enter ten values:\n");
    //Store 10 numbers in an array
    for (i = 0; i < 10; i++) {
        scanf("%d", &a[i]);
    }
    //Assume that a[0] is greatest
    greatest = a[0];
    for (i = 0; i < 10; i++) {
        if (a[i] > greatest) {
        greatest = a[i];
    }
    }
    printf("Greatest of ten numbers is %d", greatest);
    printf("\n");
    lowest = a[0];
    for(i=0;i<10;i++)
    {
    	if(a[i] < lowest)
    	{
    		lowest = a[i];
		}
	}
	printf("Lowest of ten numbers is %d",lowest);
    return 0;
  }


