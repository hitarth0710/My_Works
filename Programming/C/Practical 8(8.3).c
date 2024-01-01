#include<stdio.h>
void main()
{
	int arr[50],pos,c,n,value;
	printf("Enter the number of elements in array :");
	scanf("%d",&n);
	
	printf("Enter %d elements : \n",n);
	for(c=0;c<n;c++)
	{
		scanf("%d",&arr[n]);
	}
	int i;
	for(i=0;i<n;i++)
	printf("Element Inserted is A[%d] : %d",i,arr);
	printf("Enter the position you want to insert the array :");
	scanf("%d",&pos);
	printf("\n");
	printf("Enter the value :");
	scanf("%d",&value);
	for(c=n-1;c>=pos;c--)
	{
		arr[c+1]=arr[c];
		arr[pos - 1]=value;
		printf("Resultant array is \n");
		for(c=0;c<n;c++)
		{
			printf("%d\t",arr[c]);
		}
	}
}
