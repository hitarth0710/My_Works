
def Hello():
    p = "Hello World"
    print("\"" + p + "\"")

def max3():
    a = int(input("Enter 1st number: "))
    b = int(input("Enter 2nd number: "))
    c = int(input("Enter 3rd number: "))

    if (a > b):
        if (a > c):
            print(a, " is the greatest.")
        else:
            print(c, " is the greatest.")
    else:
        if (b > c):
            print(b, " is the greatest.")
        else:
            print(c, " is the greatest.")

def swap2():
    d = int(input("Enter 1st for swapping number: "))
    e = int(input("Enter 2nd for swapping number: "))

    d = d - e
    e = d + e
    d = e - d
    print(d)
    print(e)

def calc():
    print("Here is your simple calculator.")
    a = int(input("Enter a: "))
    b = int(input("Enter b: "))
    c = input("Which operation you want to perform +,-,*,/,%: ")
    if(c == '+'):
        print(f"Addition of {a} and {b} is ",(a+b))
    elif(c == '-'):
        print(f"Subtraction of {a} and {b} is ",(a-b))
    elif(c == '*'):
        print(f"Multiplication of {a} and {b} is ",(a*b))
    elif(c == '/'):
        print(f"Division of {a} and {b} is ",(a/b))
    elif(c == '%'):
        print(f"Modulo of {a} and {b} is ", (a%b))
    else:
        print("Enter the valid choice of operation")

def sumint():
    num2 = num = int(input("Enter the integer: "))
    n = len(str(num))
    sum = 0
    for i in range(n):
        n = num % 10
        sum = sum + n
        num = num // 10

    print(f"The sum of {num2} is {sum}.")

def sentence():
    str = input("Enter any sentence: ")
    print("Length of your sentence is ",len(str))

    digits = 0
    letters = 0
    uppercase = 0
    lowercase = 0
    spaces = 0

    for i in str:
        if i.isdigit():
            digits = digits + 1
        elif i.isalpha():
            letters = letters + 1
            if i.isupper():
                uppercase = uppercase + 1
            elif i.islower():
                lowercase = lowercase + 1
        elif i.isspace():
            spaces = spaces + 1

    print(f"Digits: {digits}")
    print(f"Letters: {letters}")
    print(f"Uppercase letters: {uppercase}")
    print(f"Lowercase letters: {lowercase}")
    print(f"Spaces: {spaces}")

import math
def is_prime(n):
    if n<=1:
        return False
    for i in range(2,int(math.sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True

def primes():
    start = int(input("Enter the starting range: "))
    end = int(input("Enter the ending range: "))

    for i in range(start,end + 1):
        if is_prime(i):
            print(i)

def amstrong_num():
    num2 = num = int(input("Enter a number: "))
    n = len(str(num))
    sum = 0
    for i in range(n):
        n = num % 10
        sum = sum + n**3
        num = num // 10

    if sum == num2:
        print(f"{num2} is Amstrong number.")
    else:
        print(f"{num2} is not a Amstrong Number.")


if __name__ == "__main__":
    amstrong_num()

