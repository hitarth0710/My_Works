#include<stdio.h>

void main()
{
	int i,j,n,k;
	printf("Enter a number of rows of pattern : ");
	scanf("%d",&n);
		
	for(i=1;i<=n;i++)
	{
		for(j=(n+2)-i;j<=n;j++)
		{
			printf(" ");
		}
		for(k=i;k<=n;k++)
		{
			printf("%d",k);
		}
		printf("\n");
	}
}

