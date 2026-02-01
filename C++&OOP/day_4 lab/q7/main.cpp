#include <iostream>
#include <MyLibrary.h>
#include <conio.h>
#include <string>
#include <stdlib.h>
using namespace std;

struct Employee {
    int id = -1;
    string name;
    float salary;
    float bonus;
    float deduction;
};

Employee emps[5];

Employee AddNewEmployee() {
    Employee e;
    cout << "Enter Employee Id: ";
    cin >> e.id;
    cout << "Enter Employee Name: ";
    cin >> e.name;
    cout << "Enter Employee Salary: ";
    cin >> e.salary;
    cout << "Enter Employee Bonus: ";
    cin >> e.bonus;
    cout << "Enter Employee Deduction: ";
    cin >> e.deduction;
    return e;
}

void DisplayEmployee(Employee e) {
    float netSalary = e.salary + e.bonus - e.deduction;
    cout << "ID: " << e.id << endl;
    cout << "Name: " << e.name << endl;
    cout << "Net Salary: " << netSalary << endl;
}

void DisplayEmployeeByIndex(int index) {
    if (index < 0 || index >= 5 || emps[index].id == -1) {
        cout << "\nOops! No employee at this index." << endl;
        return;
    }
    DisplayEmployee(emps[index]);
}

void DisplayAllEmployees() {
    bool hasEmployees = false;
    for (int i = 0; i < 5; i++) {
        if (emps[i].id != -1) {
            cout << "\nIndex " << i << ":\n";
            DisplayEmployee(emps[i]);
            cout << "===================================\n";
            hasEmployees = true;
        }
    }
    if (!hasEmployees) cout << "\nNo employees inserted yet.\n";
}

void DeleteEmployeeByIndex(int index) {
    if (index < 0 || index >= 5 || emps[index].id == -1) {
        cout << "\nNo employee at this index.\n";
        return;
    }
    emps[index].id = -1;
    cout << "\nEmployee deleted successfully.\n";
}

void DeleteAllEmployees() {
    for (int i = 0; i < 5; i++) emps[i].id = -1;
    cout << "\nAll employees have been deleted.\n";
}

int main() {

    string Emps_Operations[] = {
        "Add New Employee",
        "Display Employee",
        "Display All",
        "Delete Employee",
        "Delete All",
        "Exit"
    };

    int cur = 0;
    char ch;
    int ExitFlag = 1;
    int MenuSize = sizeof(Emps_Operations) / sizeof(Emps_Operations[0]);

    do {
        clrscr();
        gotoxy(45, 3);

        for (int i = 0; i < MenuSize; i++) {
            if (cur == i) textattr(0X03);
            else textattr(0X07);
            gotoxy(50, i * 3 + 7);
            cout << i + 1 << ". " << Emps_Operations[i];
        }

        ch = _getch();

        switch (ch) {
        case -32:
        case 0:
        case 224:
            ch = _getch();
            switch (ch) {
            case 72: cur--; if (cur < 0) cur = MenuSize - 1; break; // up
            case 80: cur++; if (cur >= MenuSize) cur = 0; break;   // down
            case 71: cur = 0; break; // home
            case 79: cur = MenuSize - 1; break; // end
            }
            break;

        case 13: // Enter
            clrscr();
            switch (cur) {
            case 0: {
                int index;
                cout << "Enter index to insert employee (0-4): ";
                cin >> index;
                if (index < 0 || index >= 5) {
                    cout << "Invalid index!\n";
                }
                else {
//                    if (emps[index].id != -1)
//                        cout << "Warning: Overwriting existing employee at index " << index << "\n";
                    emps[index] = AddNewEmployee();
                    cout << "\nEmployee added at index " << index << "!\n";
                }
                break;
            }

            case 1: {
                int index;
                cout << "Enter index of employee to display (0-4): ";
                cin >> index;
                DisplayEmployeeByIndex(index);
                break;
            }

            case 2: // Display all
                DisplayAllEmployees();
                break;

            case 3: { // Delete employee by index
                int index;
                cout << "Enter index of employee to delete (0-4): ";
                cin >> index;
                DeleteEmployeeByIndex(index);
                break;
            }

            case 4: // Delete all
                DeleteAllEmployees();
                break;

            case 5: // Exit
                ExitFlag = 0;
                textattr(0X07);
                cout << "\nExiting...";
                break;
            }

            cout << "\n\n(Press any key to return to menu)";
            _getch();
            break;

        case 27: // ESC
            ExitFlag = 0;
            textattr(0X07);
            cout << "\nExiting...";
            _getch();
            break;
        }

    } while (ExitFlag);

    return 0;
}
