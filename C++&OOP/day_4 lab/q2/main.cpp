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

int main()
{
    Employee emp;

    cout << "Enter Employee Id: ";
    cin >> emp.id;

    cout << "Enter Employee Name: ";
    cin >> emp.name;

    cout << "Enter Employee Salary: ";
    cin >> emp.salary;

    cout << "Enter Employee Bonus: ";
    cin >> emp.bonus;

    cout << "Enter Employee Deduction: ";
    cin >> emp.deduction;

    float netSalary = emp.salary + emp.bonus - emp.deduction;

    cout << "\n--- Employee Data ---\n";
    cout << "ID: " << emp.id << endl;
    cout << "Name: " << emp.name << endl;
    cout << "Net Salary: " << netSalary << endl;

    return 0;
}
