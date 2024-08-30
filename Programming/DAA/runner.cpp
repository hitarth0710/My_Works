#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int binarySearch(int arr[], int x, int low, int high) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    clock_t start, end;
    int n, key;
    cout << "Enter the number of elements: ";
    cin >> n;
    int *arr = new int[n];


    for (int i = 0; i < n; ++i) {
        arr[i] = i;
    }
   key = arr[n / 2];
    start = clock();
    binarySearch(arr, key, 0, n - 1);
    end = clock();
    cout << "Best Case Time: " << double(end - start) / CLOCKS_PER_SEC * 1e6 << " microseconds" << endl;


    key = -1;
    start = clock();
    binarySearch(arr, key, 0, n - 1);
    end = clock();
    cout << "Worst Case Time: " << double(end - start) / CLOCKS_PER_SEC * 1e6 << " microseconds" << endl;


    srand(time(0));
    key = arr[rand() % n];
    start = clock();
    binarySearch(arr, key, 0, n - 1);
    end = clock();
    cout << "Average Case Time: " << double(end - start) / CLOCKS_PER_SEC * 1e6 << " microseconds" << endl;

    
    return 0;
}
