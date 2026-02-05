from validations.auth_validations import compare_passwords, is_email_already_existed, is_valid_email, is_valid_name, is_valid_phone_number
from system_methods import clear_screen, pause_for_1_seconds
from user_ops_menu import main_menu
from data_ops import load, save

def get_user_data():

    clear_screen()

    first_name = input("Enter your first name: ")
    while not is_valid_name(first_name):
        print("Invalid Name. Name must be only letters.")
        first_name = input("Enter your first name: ")

    last_name = input("Enter your last name: ")
    while not is_valid_name(last_name):
        print("Invalid Name. Name must be only letters.")
        last_name = input("Enter your last name: ")
    
    email = input("Enter your email: ")
    while not is_valid_email(email):
        print("Invalid email address.")
        email = input("Enter your email: ")

    password = input("Enter your password: ")
    confirm_password = input("Confirm your password: ")

    while not compare_passwords(password, confirm_password):
        print("Passwords do not match. Please try again.")
        password = input("Enter your password: ")
        confirm_password = input("Confirm your password: ")

    phone_number = input("Enter your phone number: ")

    while not is_valid_phone_number(phone_number):
        print("Invalid phone number.")
        phone_number = input("Enter your phone number: ")


    user_data = {
        "first_name": first_name,
        "last_name": last_name,
        "email": email, 
        "password": password,
        "phone_number": phone_number
    }
    return user_data    


def register():

    users = load("users")

    user_data = get_user_data()

    while is_email_already_existed(user_data["email"]):
        print("Email already exists.")
        pause_for_1_seconds()
        user_data = get_user_data()

    users.append(user_data)

    save("users", users)

    print("\nUser registered successfully") 

    pause_for_1_seconds()
    main_menu(user_data['email'])




