#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

//const int SIZE = 10;

void bubbleSort(int [], int);

int main(){
    int SIZE;
    cout<<"The Bubble sort."<<endl;
    cout<<"Enter the number of elements you wan to sort: ";
    cin>>SIZE;
    int* arr = new int[SIZE];
    double res;

    srand(time(0));
    for(int i=0;i<SIZE;i++){
        arr[i] = rand() % SIZE;
    }
    bubbleSort(arr,SIZE);
    /*
    for(int i=0;i<SIZE;i++){
        cout<<arr[i]<<""<<endl;
    }
    */

       
    delete[] arr;
    return 0;
}

void bubbleSort(int arr[], int n)
{
    clock_t start,end;
    double cpu_time;

    start = clock();
    int temp;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    end = clock();

    cpu_time = ((double)(end - start))/CLOCKS_PER_SEC;
    cout<<"Time taken by Bubble Sort: "<<cpu_time;
}