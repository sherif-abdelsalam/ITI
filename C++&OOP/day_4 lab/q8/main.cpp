#include <iostream>
using namespace std;

struct Employee {
    int id;
    string name;
    float salary;
    float bonus;
    float deduction;
};

struct Dept {
    int deptId;
    string deptName;
    Employee e[5];
    int empCount = 0;
};

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
    cout << "ID: " << e.id << ", ";
    cout << "Name: " << e.name << ", " ;
    cout << "Net Salary: " << netSalary << endl;
}


int main() {
    Dept dep;

    cout << "Enter Department ID: ";
    cin >> dep.deptId;

    cout << "Enter Department Name: ";
    cin >> dep.deptName;

    cout << "Enter Number of Employees (max 5): ";
    cin >> dep.empCount;


    for(int i = 0; i < dep.empCount; i++) {
        cout << "\nEmployee " << i + 1 << " Details:\n";
        dep.e[i] = AddNewEmployee();
    }
    cout<<endl<<endl;
    cout<<"==============================================="<<endl;
    cout << "\nDepartment ID: " << dep.deptId << endl;
    cout << "Department Name: " << dep.deptName << endl;
    cout << "Employees:\n";
    for(int i = 0; i < dep.empCount; i++) {
        cout << "Employee " << i + 1 << ": ";
        DisplayEmployee(dep.e[i]);

    }
    cout<<"===============================================/n"<<endl;

    return 0;
}
