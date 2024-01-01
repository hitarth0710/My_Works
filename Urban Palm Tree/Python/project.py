import timeit
import random

def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]

def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

def partition(arr, low, high):
    i = (low - 1)
    pivot = arr[high]
    for j in range(low, high):
        if arr[j] <= pivot:
            i = i + 1
            arr[i], arr[j] = arr[j], arr[i]
    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return (i + 1)

def quick_sort(arr, low, high):
    if len(arr) == 1:
        return arr
    if low < high:
        pi = partition(arr, low, high)
        quick_sort(arr, low, pi - 1)
        quick_sort(arr, pi + 1, high)

# Generate a random list
lst = random.sample(range(1, 100000), 50000)

# Calculate the time complexity of Bubble Sort
start = timeit.default_timer()
bubble_sort(lst.copy())
end = timeit.default_timer()
print(f"Bubble Sort: {end - start}")

# Calculate the time complexity of Insertion Sort
start = timeit.default_timer()
insertion_sort(lst.copy())
end = timeit.default_timer()
print(f"Insertion Sort: {end - start}")

# Calculate the time complexity of Quick Sort
start = timeit.default_timer()
quick_sort(lst.copy(), 0, len(lst) - 1)
end = timeit.default_timer()
print(f"Quick Sort: {end - start}")