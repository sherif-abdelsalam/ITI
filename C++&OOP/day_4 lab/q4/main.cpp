#include <iostream>
#include <string>
using namespace std;

struct Employee {
    int id;
    string name;
    float salary;
    float bonus;
    float deduction;
};

struct Employee AddNewEmployee() {
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

int main() {
    Employee emp[2];

    for (int i = 0; i < 2; i++) {
        cout << "\nEnter data for Employee " << i + 1 << ":\n";
        emp[i] = AddNewEmployee();
    }

    cout << "\n\n=== Employees Data ===\n";
    for (int i = 0; i < 2; i++) {
        cout << "\nEmployee " << i + 1 << ":\n";
        DisplayEmployee(emp[i]);
    }

    return 0;
}
