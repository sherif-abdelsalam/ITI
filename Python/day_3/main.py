from auth.register import register
from auth.login import login
from system_methods import clear_screen, pause_for_1_seconds

def show_auth_menu():
    while True:
        clear_screen()
        print("--------------------")
        print("1. Register")
        print("2. Login")
        print("3. Exit")
        print("--------------------")

        choice = input("Enter your choice: ")

        if choice == '1':
            register()

        elif choice == '2':
            login()

        elif choice == '3':
            print("Exiting...")
            break

        else:
            print("Invalid Choice, Enter only (1,2,3)")
            pause_for_1_seconds()


if __name__ == "__main__":
    try:
        show_auth_menu()
    except Exception as e:
        print(f"Something wrong happened: {e}")
