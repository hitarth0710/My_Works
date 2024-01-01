#include<stdio.h>
void main()
{
	int m,n,rev,sum=0;
	scanf("%d",&m);
	
	
	while(m!=0)
	{
		rev=m%10;
		sum=(sum*10) + rev;
		m=m/10;
	
	}
	printf("%d",sum);
}
