#include<stdio.h.>

void main()
{
	int i,j,k,n;
	printf("Enter the number of rows: ");
	scanf("%d",&n);
	
	for(i=1;i<=n;i++)
	{
		
		for(j=n-i;j>=1;j--)
		{
			printf(" ");
		}
		for(k=1;k<=i;k++)
		{
			printf("*");
		}
		printf("\n");
	}
}
