

#include<stdio.h>  
#include<stdlib.h> 





int globalVar = 42;    
float pi = 3.14159;    



void dummyFunction() {
    
    
    return; 
}


int anotherFunction(int x ) {
    
    int result = 0;  
    
    
    result = x + 1;  
    result = result * 2; 
    
    
    return result; 
}



int main() {
    
    int num1 = 10;     
    int num2 = 20;     
    int sum;           
    
    
    printf("Hello World!\n");  
    
    
    sum = num1 + num2;  
    
    
    printf("Sum is: %d\n", sum);  
    
    
    dummyFunction();  
    int result = anotherFunction(5);  
    
    
    printf("Function result: %d\n", result);  
    
    
    
    
    printf("Program ending...\n");  
    
    
    return 0;  
}


  


