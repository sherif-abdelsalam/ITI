
def get_reverse_string():
    val = input("Enter your string to reverse: ")
    val = val[::-1]
    return val

res = get_reverse_string()
print(res)