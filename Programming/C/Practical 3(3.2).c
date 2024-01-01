//program to convert celsius to fahrenheit

#include<stdio.h>

void main()
{
	float F,C;
	printf("Enter the Value of Centrigrade : ");
	scanf("%f",&C);
	F=(1.8*C)+32;
	printf("The Fahrenheit Value is %.2f\n",F);
}
