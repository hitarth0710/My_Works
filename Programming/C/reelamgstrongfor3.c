#include<stdio.h>
void main()
{
	int n,n1,i,sum=0,res;
	printf("Enter a 3 digit number: ");
	scanf("%d",&n);
	n1=n;
	while(n1!=0)
	{
		res=n1%10;
		sum+=res*res*res;
		n1=n1/10;
	}
	if(sum==n)
	{
		printf("The given %d number is a amgstrong number",n);
	}
	else
	{
		printf("The given %d number is not a amgstrong number",n);
	}
}
