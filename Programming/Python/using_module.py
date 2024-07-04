import module as mod

mod.do_hello()
mod.MyCourse("Python for Everybody")
print("GREATEST COMMON DIVISOR")
a = int(input("Enter 1st Number: "))
b = int(input("Enter 2st Number: "))
c=mod.getGCD(a,b)
print(f"The GCD for {a} and {b} is {c}")
mod.findMaximum2(a,b)
res=mod.fibonacci(7)
print(res)


r = mod.Rectangle(5,5)
r.greet()
print(r.area())