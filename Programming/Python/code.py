

s = int(input("Enter your Starting number: "))
l = int(input("Enter your last number: "))
sum = 0
while s <= l:
    if s % 2 == 0:
        sum += s
    s += 1
print("The sum of all the even numbers is", sum)
