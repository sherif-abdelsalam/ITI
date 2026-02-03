from auth.register import register


def show_auth_menu():
    print("--------------------")
    print("1. Register")
    print("2. Login")
    print("3. Exit")
    print("--------------------")

    while True:

        choice = input("Enter your choice: ")

        if choice == '1':
            register()

        elif choice == '2':
            pass

        elif choice == '3':
            print("Exiting...")
            break

        else:
            print("Invalid Choice, Enter only (1,2,3)")


if __name__ == "__main__":
    try:
        show_auth_menu()
    except Exception as e:
        print(f"Something wrong happened: {e}")

