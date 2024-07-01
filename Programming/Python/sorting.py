import random as rnd
import time as tm

def sorting_num(num,start,end):
    random_num = [rnd.randint(start, end) for x in range(num)]
    sorted_num = sorted(random_num)
    return sorted_num

def main():
    start = tm.time()
    sorted_numbers = sorting_num(1000000000000000000,1,10000)
    end = tm.time()
    print(f"The sorting took {end - start} seconds")

if __name__ == "__main__":
    main()