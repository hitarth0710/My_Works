
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

//global variable declaration
#define SIZE 100000
#define NUM_SORTS 6
double insertionSort(int arr[], int n);

int main()
{
   int arr[SIZE];

   double ss[NUM_SORTS];

   //generates random numbers
   srand(time(0));
   for(int i = 0; i < SIZE; i++) {
      arr[i] = rand() % SIZE;
   }



   ss[0] = insertionSort(arr, SIZE);
   printf("Insertion Sort took %f seconds to execute \n", ss[0]);

}
// Insertion Sort
double insertionSort(int arr[], int n) {
   int key, j;

   clock_t start, end;
   double cpu_time_used;

   start = clock();

   for(int i = 1; i < n; i++) {
      key = arr[i];
      j = i - 1;
      while(j >= 0 && arr[j] > key) {
         arr[j+1] = arr[j];
         j--;
      }
      arr[j+1] = key;
   }

   end = clock();
   cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
   return cpu_time_used;
}
