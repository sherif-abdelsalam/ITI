
from project_ops.create_project import create_project
from system_methods import clear_screen


def main_menu(user_email: str):

    clear_screen()

    print('--------------------')
    print("1. Create a project ")
    print("2. View all projects")
    print("3. Edit your own projects")
    print("4. Delete your own projects")
    print("5. Search for a project (date)")
    print("6. Logout")
    print('--------------------')

    while True:
        choice = input("Enter your choice: ")

        if choice == '1':
            create_project(user_email)

        elif choice == '2':
            pass

        elif choice == '3':
            pass

        elif choice == '4':
            pass

        elif choice == '5':
            pass

        elif choice == '6':
            print("Logging out...")
            break

        else:
            print("Invalid Choice, Enter a number between 1-6")

