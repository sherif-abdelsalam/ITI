
from day_3.system_methods import pause_for_1_seconds
from day_3.user_ops_menu import main_menu
from day_3.validations.auth_validations import check_login_credentials, is_valid_email, is_valid_name


def get_login_data():
    email = input("Enter your email: ")
    while not is_valid_email(email):
        print("Invalid email address.")
        email = input("Enter your email: ")

    password = input("Enter your password: ")
    login_data = {
        "email": email,
        "password": password
    }
    return login_data

def login():
    login_data = get_login_data()
    
    while not check_login_credentials(login_data['email'], login_data['password']):
        print("Invalid email or password. Please try again.")
        login_data = get_login_data()
    
    print("\nLogin successful")
    pause_for_1_seconds()
    main_menu(login_data['email'])