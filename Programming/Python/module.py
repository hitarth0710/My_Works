import math

def MyCourse(name):
    print(f"Name of your course is "+name)

def do_hello():
    print("Hello Programmer !!")

def getGCD(a,b):
    return math.gcd(a,b)
    
def findMaximum2(x, y):
    if(x>y):
        print(f"{x} is graeter than {y}")
    else:
        print(f"{y} is greater than {x}")

def fibonacci(n):
    if n <= 0:
        return "Input must be a positive integer"
    elif n == 1:
        return 0
    elif n == 2:
        return 1
    else:
        a, b = 0, 1
        for i in range(2, n):
            a, b = b, a + b
        return b
    
class Rectangle:

    def __init__(self,length,breadth):
        self.length = length
        self.breadth = breadth

    def greet(self):
        print("The length of Rectangle is %f" % self.length)
        print("The breadth of Rectangle is %f" % self.breadth)

    def area(self):
        res = self.length * self.breadth
        return res
    
