def fizz_buzz(num: int):
    try:
        num = int(num)

        if num % 3 == 0 and num % 5 == 0:
            return "FizzBuzz"
        elif num % 3 == 0:
            return "Fizz"
        elif num % 5 == 0:
            return "Buzz"
        else:
            return f"Your Number {num} is not divisible by 3 or 5"

    except Exception as e:
        print("Not Valid Input, Enter an Integer")
    

print(fizz_buzz(2))
print(fizz_buzz(3))
print(fizz_buzz(5))
print(fizz_buzz(15))