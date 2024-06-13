#include <iostream>
using namespace std;

class Employee{
    public:
    virtual void displayRole() {
        cout << "I'm an employee!" << endl;
    }

    virtual ~Employee() {}
};

class Manager : public Employee{
    public:
    string name;

    Manager(string n) : name(n) {}

    void displayRole() override{
        cout << "I'm a manager and my name is " << name << endl;
    }
};

class Engineer : public Employee{
    public:
    string name;

    Engineer(string n) : name(n) {}

    void displayRole() override{
        cout << "I'm an Engineer and my name is " << name << endl;
    }
};

int main(){
    Employee* person1 = new Manager("John");
    Employee* person2 = new Engineer("Mandy");

    person1->displayRole();
    person2->displayRole();

    delete person1;
    delete person2;

    return 0;
}