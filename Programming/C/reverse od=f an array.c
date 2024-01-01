#include<stdio.h>
void main()
{
	int i,n,a[50];
	printf("Enter the Number of Elements :");
	scanf("%d",&n);
	printf("Enter elemnets:\n");
	
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Reveresed Elements: \n");
	for(i=n-1;i>=0;i--)
	{
		printf("%d\n",a[i]);
	}
	
}
