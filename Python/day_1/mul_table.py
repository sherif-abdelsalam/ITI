

num = input("Enter A number : ")
if(not num.isdigit()):
    print("Enter Avalid number")
else:
    num = int(num)
    ans = []
    for val in range(num):
        new_list = []
        for i in range(val+1):
            new_list.append((i+1)*(val+1))
        ans.append(new_list)

    print(ans)










