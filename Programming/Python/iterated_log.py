# Recursive Python3 program to find value of
# Iterated Logarithm
import math
 
def _log(x, base):
 
    return (int)(math.log(x) / math.log(base))
 
def recursiveLogStar(n, b):
 
    if(n > 1.0):
        return 1.0 + recursiveLogStar(_log(n, b), b)
    else:
        return 0
 
 
# Driver code
if __name__=='__main__':
    n = 100
    base = 5
    print("Log*(", n, ") = ", recursiveLogStar(n, base))