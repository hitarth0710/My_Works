#include<stdio.h>
#include<stdlib.h>
#include<time.h>


//global variable declaration
#define SIZE 1000
#define NUM_SORTS 6

//Function Prototypes
double bubbleSort(int arr[], int n);
double selectionSort(int arr[], int n);
double insertionSort(int arr[], int n);
void mergeSort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void generate_sorted_array(int arr[], int n);

int main()
{
   int arr[SIZE];

   double ss[NUM_SORTS];

   //generates random numbers
   srand(time(0));
   for(int i = 0; i < SIZE; i++) {
      arr[i] = rand() % SIZE;
   }

   //perform sorting
   ss[1] = bubbleSort(arr, SIZE);
   printf("1. Bubble Sort took %f seconds to execute \n", ss[1]);

   ss[2] = selectionSort(arr, SIZE);
   printf("2. Selection Sort took %f seconds to execute \n", ss[2]);

   ss[3] = insertionSort(arr, SIZE);
   printf("3. Insertion Sort took %f seconds to execute \n", ss[3]);

   clock_t start, end;

   start = clock();
   mergeSort(arr, 0, SIZE - 1);
   end = clock();
   ss[4] = ((double) (end - start)) / CLOCKS_PER_SEC;
   printf("4. Merge Sort took %f seconds to execute \n", ss[4]);

   start = clock();
   quickSort(arr, 0, SIZE - 1);
   end = clock();
   ss[5]= ((double) (end - start)) / CLOCKS_PER_SEC;
   printf("5. Quick Sort took %f seconds to execute \n", ss[5]);

   //sort the times
   for(int i = 1; i < NUM_SORTS; i++) {
      for(int j = i + 1; j < NUM_SORTS; j++) {
         if(ss[i] > ss[j]) {
            double temp = ss[i];
            ss[i] = ss[j];
            ss[j] = temp;
         }
      }
   }
   //print the sorted times
   printf("\nSorted Times\n");
   for(int i = 1; i < NUM_SORTS; i++) {
      printf("%f\n",ss[i]);
   }
   //give sorted input in quicksort
   //give sorted input in quicksort
   generate_sorted_array(arr, SIZE);
   start = clock();
   quickSort(arr, 0, SIZE - 1);
   end = clock();
   double quickSortSortedTime = ((double) (end - start)) / CLOCKS_PER_SEC;
   printf("Quick Sort Time with sorted data: %f seconds\n", quickSortSortedTime);


   return 0;
}

// Bubble Sort
double bubbleSort(int arr[], int n) {

   clock_t start, end;
   double cpu_time_used;

   start = clock();

   for(int i = 0; i < n-1; i++) {
       for (int j = 0; j < n-i-1; j++) {
           if (arr[j] > arr[j+1]) {
              int temp = arr[j];
              arr[j] = arr[j+1];
              arr[j+1] = temp;
           }
       }
   }

   end = clock();
   cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
   return cpu_time_used;
}

// Selection Sort
double selectionSort(int arr[], int n) {

   clock_t start, end;
   double cpu_time_used;

   start = clock();

   for(int i = 0; i < n; i++) {
      int min = i;
      for(int j = i+1; j < n; j++)
         if(arr[j] < arr[min])
            min = j;
      int temp = arr[i];
      arr[i] = arr[min];
      arr[min] = temp;
   }

   end = clock();
   cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
   return cpu_time_used;
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

// Merge Sort
void merge(int arr[], int l, int m, int r) {
   int i, j, k;
   int n1 = m - l + 1;
   int n2 = r - m;
   int L[n1], R[n2];
   for (i = 0; i < n1; i++)
      L[i] = arr[l + i];
   for (j = 0; j < n2; j++)
      R[j] = arr[m + 1 + j];
   i = 0;
   j = 0;
   k = l;
   while (i < n1 && j < n2) {
      if (L[i] <= R[j]) {
         arr[k] = L[i];
         i++;
      } else {
         arr[k] = R[j];
         j++;
      }
      k++;
   }
   while (i < n1) {
      arr[k] = L[i];
      i++;
      k++;
   }
   while (j < n2) {
      arr[k] = R[j];
      j++;
      k++;
   }
}

void mergeSort(int arr[], int l, int r) {
   if (l < r) {
      int m = l + (r - l) / 2;
      mergeSort(arr, l, m);
      mergeSort(arr, m + 1, r);
      merge(arr, l, m, r);
   }
}

// Quick Sort
int partition(int arr[], int low, int high) {
   int pivot = arr[high];
   int i = (low - 1);
   for (int j = low; j <= high - 1; j++) {
      if (arr[j] < pivot) {
         i++;
         int temp = arr[i];
         arr[i] = arr[j];
         arr[j] = temp;
      }
   }
   int temp = arr[i + 1];
   arr[i + 1] = arr[high];
   arr[high] = temp;
   return (i + 1);
}

void quickSort(int arr[], int low, int high) {
   if (low < high) {
      int pi = partition(arr, low, high);
      quickSort(arr, low, pi - 1);
      quickSort(arr, pi + 1, high);
   }
}

void generate_sorted_array(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    arr[i] = i;
  }
}
