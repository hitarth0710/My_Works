def division(a, b):
    try:
        res = a/b
    except ZeroDivisionError:
        print("Error: Division by zero is not allowed.")
        return None
    except Exception as e:
        print("Unexpected error generated ",e)
        return None
    else:
        return res
    finally:
        print("Execution is complete.")

a = int(input("Enter a: "))
b = int(input("Enter b: "))
div = division(a, b)
print(f"The result of division of {a} and {b} is {div}.")

#assertion

def calculate_sqrt(x):
    assert x >= 0, "Input must be non-negative"
    return x ** 0.5

sqr = int(input("Enter a integer to make it's square root: "))
sqt = calculate_sqrt(sqr)
print(f"The square root of the {sqr} is {sqt}.")