#include<stdio.h>
#include<math.h>
void main()
{
	int n,i,rem,n1=0;
	float res=0.0;
	
	printf("Enter a number: ");
	scanf("%d",&n);
	i=n;
	for(i=n;i!=0;++i)
	{
		i/=10;
	}
	for(i=n;i!=0;i/=10)
	{
		rem=i%10;
		res+=pow(rem,n);
	}
	if ((int)res == n)
    printf("%d is an Armstrong number.",n);
    else
    printf("%d is not an Armstrong number.",n);
}

