arr = []

while len(arr) < 5 :
    num = input("Enter a number: ")
    if num.isdigit():
        arr.append(int(num))
    else:
        print("Enter a valid numer")

arr.sort()
print(arr)
arr.reverse()
print(arr)