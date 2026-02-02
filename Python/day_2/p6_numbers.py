total = 0
count = 0
while True:
    inp = input("Enter a number or 'done' to finish: ")
    if inp == 'done':
        break
    try:
        num = int(inp)
        total += num
        count += 1
    except ValueError:
        print("Invalid input. enter a valid number.")


if count > 0:
    print("count:", count)
    print("total:", total)
    print("average:", total / count)
else:
    print("No numbers entered.")