
def is_valid_title(title):
    return isinstance(title, str) and len(title) >= 3 and len(title) <= 20

def is_valid_details(details):
    return isinstance(details, str) and len(details) >= 10 and len(details) <= 100

def is_valid_total_target(total_target):
    if total_target.isnumeric():
        return int(total_target) > 0
    
    
def validate_title(title):
    title = title.strip()
    while not is_valid_title(title):
        print("Invalid title. Title must be between 3 and 20 characters.")
        title = input("Enter project title: ")
        title = title.strip()
    return title

def validate_details(details):
    details = details.strip()
    while not is_valid_details(details):
        print("Invalid details. Details must be between 10 and 100 characters.")
        details = input("Enter project details: ")
        details = details.strip()
    return details


def validate_total_target(total_target):
    while not is_valid_total_target(total_target):
        print("Invalid total target. It must be a positive number.")
        total_target = input("Enter total target amount: ")
    return total_target