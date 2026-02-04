
import json
import re

def is_valid_name(name):
    return name.isalpha() and len(name) > 3 

def is_valid_email(email):
    email_validator = r'^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$'
    return re.match(email_validator, email)

def compare_passwords(password, confirm_password):
    return password == confirm_password


def is_valid_phone_number(phone_number):
    phone_validator = r'^01[0-2,5]{1}[0-9]{8}$'
    return re.match(phone_validator, phone_number)

def is_email_already_existed(email):
    users_file = "file_storage/users.json"
    try:
        with open(users_file, "r") as file:
            users = json.load(file)
            for user in users:
                if user['email'] == email:
                    return True
            return False
    except FileNotFoundError:
        return False
    


def check_login_credentials(email, password):
    users_file = "file_storage/users.json"
    try:
        with open(users_file, "r") as file:
            users = json.load(file)
            for user in users:
                if user['email'] == email and user['password'] == password:
                    return True
            return False
    except FileNotFoundError:
        return False