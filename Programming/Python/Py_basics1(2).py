def duplicate(lu):
    l = []
    for i in range(len(lu) - 1):
        if lu[i] == lu[i + 1]:
            continue
        l.append(lu[i])
    l.append(lu[-1])
    return l

def sorting(lu):
    for i in range(1, len(lu)):
        key = lu[i]
        j = i - 1
        while (j > 0 and lu[j] > key):
            lu[j+1] = lu[j]
            j = j - 1
        lu[j + 1] = key
    return lu

def maxmintuple():
    tuple_list = [(1, 'a'), (2, 'b'), (3, 'c'), (4, 'd'), (5, 'e')]
    firstele = [t[0] for t in tuple_list]
    maxele = max(firstele)
    minele = min(firstele)
    print("Max value is ",maxele)
    print("Min value is ",minele)


def removetuple(tu, element):
    index = tu.index(element)
    return tu[:index] + tu[index+1:]

def elementcheck(tu, element):
    for i in tu:
        if i == element:
            flag = True
            break
        else:
            flag = False

    if flag==True:
        print("Element exists.")
    else:
        print("Element does not exists.")


def dict():
    dict1 = {}
    a = int(input("Enter The number of fields: "))

    for i in range(a):
        key = int(input("Enter the key :"))
        value = input("Enter the value :")
        dict1[key] = value

    print(dict1)

def sumdict(dic):
    sum = 0
    for value in dic.values():
        sum = sum + value
    print("Sum of the values dictionary is ",sum)

def concatedic(dic1, dic2):
    dic1.update(dic2)
    print(dic1)

def factorial(n):
    if n==0 or n==1:
        return 1
    else:
        return n * factorial(n-1)

def occurence(str, word):
    count = 0
    for c in str:
        if c == word:
            count = count + 1
        elif c.upper() == word:
            count = count + 1


    print(f'The occurence of word {word} in string {str} is {count}')


def fibonacci(n, a=0, b=1):
    if n>0:
        print(f"{a}\n")
        fibonacci(n-1, b, a+b)
    #996 is the limit

if __name__ == "__main__":
    str = "Madam"
    occurence(str, 'm')



