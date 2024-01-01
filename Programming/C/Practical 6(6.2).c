#include<stdio.h>
void main()
{
	int n1=0,n2=1,i,n,n3;
	printf("Enter Number : ");
	scanf("%d",&n);
	
	printf("%d",n1);
	
	for(i=2;i<n;i++)
	{
		n3=n1+n2;
		printf("%d",n3);
		n1=n2;
		n2=n3;
	}
}
