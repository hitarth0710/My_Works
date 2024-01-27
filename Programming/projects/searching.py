import random
import time
from typing import List

def linear_search(arr: List[int], x: int) -> int:
    for i in range(len(arr)):
        if arr[i] == x:
            return i
    return -1

def binary_search(arr: List[int], x: int) -> int:
    low = 0
    high = len(arr) - 1
    mid = 0

    while low <= high:
        mid = (high + low) // 2
        if arr[mid] < x:
            low = mid + 1
        elif arr[mid] > x:
            high = mid - 1
        else:
            return mid
    return -1

# Generate 100000 random numbers and write them to a file
with open('numbers.txt', 'w') as f:
    for _ in range(100000):
        f.write(str(random.randint(1, 100000)) + '\n')

# Read the numbers back into an array
numbers = []
with open('numbers.txt', 'r') as f:
    for line in f:
        numbers.append(int(line.strip()))

# Ask the user for the number they want to search for
search_number = int(input("Enter the number you want to search for: "))

# Perform linear search and measure time
start_time = time.time()
print(linear_search(numbers, search_number))
end_time = time.time()
print(f"Linear search took {end_time - start_time} seconds")

# Sort the array for binary search
numbers.sort()

# Perform binary search and measure time
start_time = time.time()
print(binary_search(numbers, search_number))
end_time = time.time()
print(f"Binary search took {end_time - start_time} seconds")