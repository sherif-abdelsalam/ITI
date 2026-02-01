#include <iostream>
#include <string>

using namespace std;

#define EMPS_SIZE 3


struct Employee {
    int id;
    string name;
    float salary;
    float bonus;
    float deduction;
};

int main()
{
    Employee emp[EMPS_SIZE];

    for (int i = 0; i < EMPS_SIZE; i++) {
        cout << "\nEnter data for Employee " << i + 1 << ":\n";

        cout << "Enter Employee Id: ";
        cin >> emp[i].id;

        cout << "Enter Employee Name: ";
        cin >> emp[i].name;

        cout << "Enter Employee Salary: ";
        cin >> emp[i].salary;

        cout << "Enter Employee Bonus: ";
        cin >> emp[i].bonus;

        cout << "Enter Employee Deduction: ";
        cin >> emp[i].deduction;
    }

    cout << "\n\n=== Employees Data ===\n";
    for (int i = 0; i < EMPS_SIZE; i++) {
        float netSalary = emp[i].salary + emp[i].bonus - emp[i].deduction;
        cout << "\nEmployee " << i + 1 << ":\n";
        cout << "ID: " << emp[i].id << endl;
        cout << "Name: " << emp[i].name << endl;
        cout << "Net Salary: " << netSalary << endl;
    }

    return 0;
}
