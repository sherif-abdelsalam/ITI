def get_max_alph(val: str) -> str:
    if not val:
        return ""

    ans = ""       
    tmp = val[0]   
    i = 1

    while i < len(val):
        if val[i] > val[i - 1]:
            tmp += val[i]  
        else:
            tmp = val[i]   
        if len(tmp) > len(ans):
            ans = tmp
        i += 1

    return ans

print(get_max_alph("abdulabcdersrahman"))
