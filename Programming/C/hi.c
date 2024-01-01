/*#include <stdio.h>

int main() {
   int n, pos, i;
   printf("Enter the number of elements in the array: ");
   scanf("%d", &n);

   int arr[n];

   printf("Enter %d elements in the array: \n", n);
   for (i = 0; i < n; i++) {
      scanf("%d", &arr[i]);
   }

   printf("Enter the position of the element to be deleted: ");
   scanf("%d", &pos);

   // Shift elements to the left from position to n
   for (i = pos - 1; i < n - 1; i++) {
      arr[i] = arr[i + 1];
   }

   n--; // Decrement the size of the array by 1

   printf("Resultant array is: \n");
   for (i = 0; i < n; i++) {
      printf("%d ", arr[i]);
   }

   return 0;
}
*/

#include <stdio.h>

int main()
 {
   char str1[100], str2[100], result[200];
   int i = 0, j = 0;

   printf("Enter the first string: ");
   scanf("%s", str1);

   printf("Enter the second string: ");
   scanf("%s", str2);

   // Copy str1 to result
   while (str1[i] != '\0') {
      result[j] = str1[i];
      i++;
      j++;
   }

   // Copy str2 to result
   i = 0;
   while (str2[i] != '\0') {
      result[j] = str2[i];
      i++;
      j++;
   }

   result[j] = '\0'; // Add null character at the end

   printf("Concatenated string: %s", result);

   /*for(i=0;str1[i]!='\0';i++)
   {
      for(j=0;str1[j]!='\0';j++)
      {
             result[j]=str1[i];
      }
   }

   for(i=0;str2[i]!='\0';i++)
   {
      for(j=0;str2[j]!='\0';j++)
      {
             result[j]=str2[i];
      }
   }
   result[j] = '\0'; // Add null character at the end

   printf("Concatenated string: %s", result[j]);*/
   return 0;
}
