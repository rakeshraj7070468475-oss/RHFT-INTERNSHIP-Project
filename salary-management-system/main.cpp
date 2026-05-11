#include <iostream>
#include <vector>
#include <memory>
#include <iomanip>

using namespace std;

// ================= BASE CLASS =================

class Employee {
protected:
    int id;
    string name;

public:
    Employee(int empId, string empName)
        : id(empId), name(empName) {}

    // Pure virtual function
    virtual double calculateSalary() = 0;

    // Virtual display function
    virtual void display() {
        cout << "Employee ID   : " << id << endl;
        cout << "Employee Name : " << name << endl;
    }

    // Virtual destructor
    virtual ~Employee() {}
};

// ================= FULL TIME EMPLOYEE =================

class FullTimeEmployee : public Employee {
private:
    double monthlySalary;
    double bonus;

public:
    FullTimeEmployee(int empId,
                     string empName,
                     double salary,
                     double empBonus)
        : Employee(empId, empName),
          monthlySalary(salary),
          bonus(empBonus) {}

    double calculateSalary() override {
        return monthlySalary + bonus;
    }

    void display() override {
        Employee::display();

        cout << "Employee Type : Full Time" << endl;
        cout << "Monthly Salary: " << monthlySalary << endl;
        cout << "Bonus         : " << bonus << endl;
        cout << "Total Salary  : "
             << calculateSalary() << endl;
    }
};

// ================= PART TIME EMPLOYEE =================

class PartTimeEmployee : public Employee {
private:
    int hoursWorked;
    double hourlyRate;

public:
    PartTimeEmployee(int empId,
                     string empName,
                     int hours,
                     double rate)
        : Employee(empId, empName),
          hoursWorked(hours),
          hourlyRate(rate) {}

    double calculateSalary() override {
        return hoursWorked * hourlyRate;
    }

    void display() override {
        Employee::display();

        cout << "Employee Type : Part Time" << endl;
        cout << "Hours Worked  : " << hoursWorked << endl;
        cout << "Hourly Rate   : " << hourlyRate << endl;
        cout << "Total Salary  : "
             << calculateSalary() << endl;
    }
};

// ================= MAIN FUNCTION =================

int main() {

    // Using smart pointers (Modern C++)
    vector<unique_ptr<Employee>> employees;

    // Adding employees
    employees.push_back(
        make_unique<FullTimeEmployee>(
            101,
            "Alice",
            50000,
            10000
        )
    );

    employees.push_back(
        make_unique<PartTimeEmployee>(
            102,
            "Bob",
            120,
            250
        )
    );

    employees.push_back(
        make_unique<FullTimeEmployee>(
            103,
            "Charlie",
            70000,
            15000
        )
    );

    employees.push_back(
        make_unique<PartTimeEmployee>(
            104,
            "David",
            100,
            300
        )
    );

    cout << fixed << setprecision(2);

    cout << "========== EMPLOYEE SALARY SYSTEM ==========\n\n";

    // Display all employee details
    for (const auto& emp : employees) {

        emp->display();

        cout << "----------------------------------------\n";
    }

    // Find highest paid employee
    Employee* highestPaid = employees[0].get();

    for (const auto& emp : employees) {

        if (emp->calculateSalary() >
            highestPaid->calculateSalary()) {

            highestPaid = emp.get();
        }
    }

    cout << "\n========== HIGHEST PAID EMPLOYEE ==========\n\n";

    highestPaid->display();

    return 0;
}