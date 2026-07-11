#include <iostream>
using namespace std;

class Employee {
    private:
        int id;
        string name;
        float salary;

    public:
        Employee(int id, string name, float salary) {
            this->id = id;
            this->name = name;
            this->salary = salary;
            cout << "Employee instance created: " << this->name << endl;
        }

        void displayDetails() {
            cout << "ID: " << this->id << endl;
            cout << "Name: " << this->name << endl;
            cout << "Salary: " << this->salary << endl;
        }
};

// Single Inheritance
class Manager : public Employee {
    private:
        string department;

    public:
        Manager(int id, string name, float salary, string department) : Employee(id, name, salary) {
            this->department = department;
            cout << "Manager instance created: " << name << endl;
        }

        void displayManagerDetails() {
            displayDetails();
            cout << "Department: " << this->department << endl;
        }
};

// Multi-level Inheritance
class SeniorManager : public Manager {
    private:
        int teamSize;

    public:
        SeniorManager(int id, string name, float salary, string department, int teamSize) 
            : Manager(id, name, salary, department) {
            this->teamSize = teamSize;
            cout << "Senior Manager instance created: " << name << endl;
        }

        void displaySeniorManagerDetails() {
            displayManagerDetails();
            cout << "Team Size: " << this->teamSize << endl;
        }
};

// Hierarchical Inheritance
class Intern : public Employee {
    private:
        int duration; // in months

    public:
        Intern(int id, string name, float salary, int duration) : Employee(id, name, salary) {
            this->duration = duration;
            cout << "Intern instance created: " << name << endl;
        }

        void displayInternDetails() {
            displayDetails();
            cout << "Duration: " << this->duration << " months" << endl;
        }
};

// Multiple Inheritance
class Consultant {
    private:
        string expertise;

    public:
        Consultant(string expertise) {
            this->expertise = expertise;
            cout << "Consultant instance created with expertise: " << this->expertise << endl;
        }

        void displayConsultantDetails() {
            cout << "Expertise: " << this->expertise << endl;
        }
};

// hybrid Inheritance
class HybridManager : public Manager, public Consultant {
    public:
        HybridManager(int id, string name, float salary, string department, string expertise) 
            : Manager(id, name, salary, department), Consultant(expertise) {
            cout << "Hybrid Manager instance created: " << name << endl;
        }

        void displayHybridManagerDetails() {
            displayManagerDetails();
            displayConsultantDetails();
        }
};

int main() {
    Employee emp(1, "John Doe", 50000);
    emp.displayDetails();

    cout << endl;

    Manager mgr(2, "Jane Smith", 70000, "Sales");
    mgr.displayManagerDetails();

    cout << endl;

    SeniorManager smgr(3, "Alice Johnson", 90000, "Marketing", 10);
    smgr.displaySeniorManagerDetails();

    cout << endl;

    Intern intern(4, "Bob Brown", 20000, 6);
    intern.displayInternDetails();

    cout << endl;

    HybridManager hMgr(5, "Charlie Davis", 80000, "IT", "Software Development");
    hMgr.displayHybridManagerDetails();

    return 0;
}