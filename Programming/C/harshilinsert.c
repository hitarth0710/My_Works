#include<stdio.h>
void main()
{
    int i,n,op,ad,temp;
    printf("Enter the size of the Array: ");
    scanf("%d",&n);
    int a[n];

    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    for(i=0;i<n;i++)
        printf("Inserted Elements at A[%d] : %d\n",i+1,a[i]);
    
    printf("\n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    scanf("%d",&op);
    printf("\n");
    if(op==1)
    {
        printf("Enter the address of the array: ");
        scanf("%d",&ad);
        printf("Enter the number: ");
        scanf("%d",&a[ad-1]);
        printf("\nArray After Inserting\n");
        for(i=0;i<n;i++)
        {
            printf("Array is A[%d] : %d\n",i+1,a[i]);
        }
    }
    else if(op==2)
    {
        printf("Enter the address of the array: ");
        scanf("%d",&ad);
        for(i=ad;i<n;i++)
        {
            temp=a[i-1];
            a[i-1]=a[i];
            a[i]=temp;
        }
        printf("\nArray after Deleting\n");
        for(i=0;i<n-1;i++)
        {
            printf("Array is A[%d] : %d\n",i+1,a[i]);

        }

    }
    else
    {
        printf("Operation Invalid !");
    }
    
}
