#include <iostream>
#include <MyLibrary.h>
#include <conio.h>
#include <string>

using namespace std;

struct Employee {
    int id;
    string name;
    float salary;
    float bonus;
    float deduction;
};

Employee emps[5];
int EmployeesInsertedIndex = 0;

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

void DisplayEmployee(struct Employee e) {
    float netSalary = e.salary + e.bonus - e.deduction;
    cout << "ID: " << e.id << endl;
    cout << "Name: " << e.name << endl;
    cout << "Net Salary: " << netSalary << endl;
}

void DisplayEmployeeById(int empId) {
    for (int i = 0; i < EmployeesInsertedIndex; i++) {
        if (emps[i].id == empId) {
            DisplayEmployee(emps[i]);
            return;
        }
    }
    cout << "\nOops! No employee with this ID." << endl;
}

void DisplayAllEmployees() {
    if (EmployeesInsertedIndex == 0) {
        cout << "\nNo employees inserted yet.\n";
        return;
    }

    for (int i = 0; i < EmployeesInsertedIndex; i++) {
        DisplayEmployee(emps[i]);
        cout<<"===================================\n";
    }
}

void DeleteEmployee(int empId) {
    for (int i = 0; i < EmployeesInsertedIndex; i++) {
        if (emps[i].id == empId) {

            /// Shift array left
            for (int j = i; j < EmployeesInsertedIndex - 1; j++) {
                emps[j] = emps[j + 1];
            }

            EmployeesInsertedIndex--;
            cout << "\nEmployee deleted successfully." << endl;
            return;
        }
    }
    cout << "\nEmployee not found.\n";
}

void DeleteAllEmployees() {
    EmployeesInsertedIndex = 0;
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

        // Draw the menu
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
            case 72: /// up
                cur--;
                if (cur < 0) cur = MenuSize - 1;
                break;

            case 80: /// down
                cur++;
                if (cur >= MenuSize) cur = 0;
                break;

            case 71: /// home
                cur = 0;
                break;

            case 79: /// end
                cur = MenuSize - 1;
                break;
            }
            break;

        case 13: /// Enter
            clrscr();
            switch (cur) {

            case 0: /// Add new employee
                if (EmployeesInsertedIndex < 5)
                    emps[EmployeesInsertedIndex++] = AddNewEmployee();
                else
                    cout << "\nEmployee list is FULL!";
                break;

            case 1: { /// Display employee
                int id;
                cout << "Enter employee ID: ";
                cin >> id;
                DisplayEmployeeById(id);
                break;
            }

            case 2: /// Display all
                DisplayAllEmployees();
                break;

            case 3: { /// Delete employee
                int id;
                cout << "Enter employee ID to delete: ";
                cin >> id;
                DeleteEmployee(id);
                break;
            }

            case 4: /// Delete all
                DeleteAllEmployees();
                break;

            case 5: /// Exit
                ExitFlag = 0;
                textattr(0X07);
                cout << "\nExiting...";
                break;
            }

            cout << "\n\n(Press any key to return to menu)";
            _getch();
            break;

        case 27: /// ESC
            ExitFlag = 0;
            textattr(0X07);

            cout << "\nExiting...";
            _getch();
            break;
        }

    } while (ExitFlag);

    return 0;
}
