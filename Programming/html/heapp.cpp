#include <iostream>
#include <ctime>
#include <cstdlib>
#define N 50000
using namespace std;
 
void heapify(long arr[], long i, long n)
{
	long left = 2 * i + 1;
	long right = 2 * i + 2;
	long largest;
    if (left < n && arr[left] > arr[i]) {
    	largest = left;
	} else {
    	largest = i;
	}
 
	if (right < n && arr[right] > arr[largest]) {
    	largest = right;
	}
 
	if (largest != i) {
    	swap(arr[i], arr[largest]);
    	heapify(arr, largest, n);
	}
}
 
void maxheap(long arr[], long n)
{
	for (long i = n / 2 - 1; i >= 0; i--) {
    	heapify(arr, i, n);
	}
}
 
void heapsort(long arr[], long n)
{
	maxheap(arr, n);
	for (long i = n - 1; i > 0; i--) {
    	swap(arr[i], arr[0]);
    	heapify(arr, 0, i);
	}
}
int main() {
	long num[N];
	clock_t start, end;
 
 
	for (long i = 0; i < N; i++) {
    	num[i] = N - i;
	}
	start = clock();
	heapsort(num, N);
	end = clock();
	double cpu_time_used1 = ((double) (end - start)) / CLOCKS_PER_SEC;
 
 
	for (long i = 0; i < N; i++) {
    	num[i] = i;
	}
	start = clock();
	heapsort(num, N);
	end = clock();
	double cpu_time_used2 = ((double) (end - start)) / CLOCKS_PER_SEC;
 
 
	for (long i = 0; i < N; i++) {
    	num[i] = rand();
	}
	start = clock();
	heapsort(num, N);
	end = clock();
	double cpu_time_used3 = ((double) (end - start)) / CLOCKS_PER_SEC;
 
 
	printf("Time taken to sort %d numbers using heap sort for Random Numbers Array: %f seconds\n", N, cpu_time_used3);
	printf("Time taken to sort %d numbers using heap sort for Sorted Array: %f seconds\n", N, cpu_time_used2);
	printf("Time taken to sort %d numbers using heap sort for Reverse Array: %f seconds\n", N, cpu_time_used1);
 
	return 0;
}
