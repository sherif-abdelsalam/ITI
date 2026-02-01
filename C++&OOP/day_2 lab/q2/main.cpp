#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    int choice;

    while (true) {

        system("cls");
        cout << "---- Simple Menu ----\n";
        cout << "1. Orange Juice\n";
        cout << "2. Mango Juice\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";

        cin >> choice;
        system("cls");

        switch (choice) {
            case 1:
                cout << "You chose Orange Juice\n";
                break;
            case 2:
                cout << "You chose Mango Juice\n";
                break;
            case 3:
                cout << "Exiting...\n";
                exit(0);
            default:
                cout << "Invalid choice! Please enter again.\n";
                break;
        }

        if(choice != 3){
            cout << "\nPress Enter to return to the menu...";
            cin.ignore();
            cin.get();
        }
    }

    return 0;
}
