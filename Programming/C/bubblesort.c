#include<stdio.h>
int main()

{
	int a[10],i,n,j,temp;
	printf("Enter the number of elements :");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1;j++)
	    {
		    if(a[j]>a[j+1])
		    {
		    	temp=a[j];
		    	a[j]=a[j+1];
		    	a[j+1]=temp;
			}
	    }
	}
	printf("The Sorted Elements are\n");
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
	return 0;
	
}
