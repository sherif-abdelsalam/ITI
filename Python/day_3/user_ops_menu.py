
from project_ops.delete_my_project import delete_my_project
from project_ops.edit_user_project import edit_user_project
from project_ops.search_by_date import search_by_date
from project_ops.view_all_project import view_all_projects
from project_ops.create_project import create_project
from system_methods import clear_screen, pause_for_1_seconds


def main_menu(user_email: str):

    while True:
        clear_screen()

        print('--------------------')
        print("1. Create a project ")
        print("2. View all projects")
        print("3. Edit your own projects")
        print("4. Delete your own projects")
        print("5. Search for a project (date)")
        print("6. Logout")
        print('--------------------')

        choice = input("Enter your choice: ")

        if choice == '1':
            create_project(user_email)

        elif choice == '2':
            view_all_projects() 

        elif choice == '3':
            edit_user_project(user_email)

        elif choice == '4':
            delete_my_project(user_email)

        elif choice == '5':
            search_by_date()

        elif choice == '6':
            print("Logging out...")
            pause_for_1_seconds()
            break

        else:
            print("Invalid Choice, Enter a number between 1-6")
            pause_for_1_seconds()

