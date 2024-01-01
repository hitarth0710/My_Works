#include<stdio.h>
void main()
{
	int a[50],b[50],c[50];
	int i,n;
	
	printf("enter the Number of elements:");
	scanf("%d",&n);
	
	printf("Enter the values of a\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
		printf("Enter the values of b\n");

	for(i=0;i<n;i++)
	{
		scanf("%d",&b[i]);
	}
	
	printf("The addition of your entered arrays a and b are\n c:");
	for(i=0;i<n;i++)
	{
		c[i]=a[i]+b[i];
	}
	for(i=0;i<n;i++)
	{
		printf("\n%d",c[i]);
	}
	
}
