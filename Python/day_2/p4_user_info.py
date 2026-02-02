import re


def is_valid_name(name):
    return name.isalpha() and len(name) > 0

def is_valid_email(email):
    email_validator = r'^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$'
    return re.match(email_validator, email)


if __name__ == "__main__":
    
    name = input("Enter your name: ")

    while not is_valid_name(name):
        print("Invalid Name. Name must be only letters.")
        name = input("Enter your name: ")

    email = input("Enter your email: ")


    while not is_valid_email(email):
        print("Invalid email address.")
        email = input("Enter your email: ")

    print(f"Name: {name}")
    print(f"Email: {email}")