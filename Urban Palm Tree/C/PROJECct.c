#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000

// Timer function
double get_time() {
  struct timespec ts;
  clock_gettime(CLOCK_REALTIME, &ts);
  return (double)ts.tv_sec + (double)ts.tv_nsec / 1e9;
}

// Sorting functions with time measurement
double bubble_sort(int arr[], int n) {
  double start_time = get_time();
  int i, j;
  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
  double end_time = get_time();
  return end_time - start_time;
}

double selection_sort(int arr[], int n) {
  double start_time = get_time();
  int i, j, min_idx;
  for (i = 0; i < n - 1; i++) {
    min_idx = i;
    for (j = i + 1; j < n; j++) {
      if (arr[j] < arr[min_idx]) {
        min_idx = j;
      }
    }
    if (min_idx != i) {
      int temp = arr[i];
      arr[i] = arr[min_idx];
      arr[min_idx] = temp;
    }
  }
  double end_time = get_time();
  return end_time - start_time;
}

double insertion_sort(int arr[], int n) {
  double start_time = get_time();
  int i, j, key;
  for (i = 1; i < n; i++) {
    key = arr[i];
    j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
  double end_time = get_time();
  return end_time - start_time;
}
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

double mergeSort(int arr[], int l, int r) {
    double start_time = get_time();
   if (l < r) {
      int m = l + (r - l) / 2;
      mergeSort(arr, l, m);
      mergeSort(arr, m + 1, r);
      merge(arr, l, m, r);
   }
    double end_time = get_time();
    return end_time - start_time;
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

double quickSort(int arr[], int low, int high) {
    double start_time = get_time();
   if (low < high) {
      int pi = partition(arr, low, high);
      quickSort(arr, low, pi - 1);
      quickSort(arr, pi + 1, high);
   }
    double end_time = get_time();
    return end_time - start_time;
}

// Generate random array
void generate_random_array(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    arr[i] = rand() % 1000;
  }
}
void generate_sorted_array(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    arr[i] = i;
  }
}

// Print array
void print_array(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main() {
  int arr[ARRAY_SIZE];

  // Generate random data
  generate_random_array(arr, ARRAY_SIZE);

  // Measure and print execution times
  printf("Array size: %d\n", ARRAY_SIZE);
  printf("Bubble Sort Time: %f seconds\n", bubble_sort(arr, ARRAY_SIZE));
  generate_random_array(arr, ARRAY_SIZE); // Re-randomize for next sort
  printf("Selection Sort Time: %f seconds\n", selection_sort(arr, ARRAY_SIZE));
  generate_random_array(arr, ARRAY_SIZE); // Re-randomize for next sort
  printf("Insertion Sort Time: %f seconds\n", insertion_sort(arr, ARRAY_SIZE));
  generate_random_array(arr, ARRAY_SIZE); // Re-randomize for next sort
  printf("Merge Sort Time: %f seconds\n", mergeSort(arr, 0 , ARRAY_SIZE));
  generate_random_array(arr, ARRAY_SIZE); // Re-randomize for next sort
  printf("Quick Sort Time: %f seconds\n", quickSort(arr,0 , ARRAY_SIZE));


// Generate sorted data
  generate_sorted_array(arr, ARRAY_SIZE);
  // Measure and print execution time for quick sort with sorted data
  printf("Quick Sort Time with sorted data: %f seconds\n", quickSort(arr,0 , ARRAY_SIZE));

  return 0;
}
