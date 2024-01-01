#include <stdio.h>

int bsort(int n, int arr[n])
{
  int i, j, temp;

  int flag = 0;
  for (i = 0; i < n - 1; i++)
  {
    for (j = 0; j < n - 1 - i; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
  return arr[i];
}

int main()
{
  int i, n, arr[n];
  // int arr[10] = {8, 5, 6, 1, 3, 2, 9, 7, 4, 10};
  printf("Enter The Total: ");
  scanf("%d", &n);

  printf("Enter The Array Elements: ");
  for (i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }

  printf("\nThe Entered  Array is: \n");
  for (i = 0; i < n; i++)
    printf("\nA[%d] Element is: %d", i, arr[i]);
  bsort(n, arr);
  printf("\n\nThe Sorted Array is: \n");
  for (i = 0; i < n; i++)
    printf("\nA[%d] Element is: %d", i, arr[i]);
}
