//program for marking system
#include<stdio.h>

void main()
{
	float a;
	printf("Marking Grade Syatem\n\n");
	printf("Enter Your Marks :");
	scanf("%f",&a);
	
	if(a>=80 && a<=100)
	printf("Your Grade is DISTINCION");
	else if(a>=60 && a<=79)
	printf("Your Grade is FIRST CLASS");
	else if(a>=40 && a<=59)
	printf("Your Grade is SECOND CLASS");
	else if(a>=0 && a<40)
	printf("SORRY you are FAIL , BETTER LUCK NEXT TIME");
	else
	printf("ENTERED MARKS ARE INVALID");
}

