

num = input("Enter A number : ")
if(not num.isdigit()):
    print("Enter Avalid number")
else:
    ans = ""
    num = int(num)
    for i in range(num):
        for spaces in range(num - i - 1):
            ans+=" "
        for stars in range(i+1):
            ans+="*"
        if i < num-1 : ans += "\n"
    print(ans)







