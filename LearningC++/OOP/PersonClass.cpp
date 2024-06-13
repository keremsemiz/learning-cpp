#include <iostream>
using namespace std;

class Person{
    public:
    string name;
    int age; 

    void greet(){
        cout << "Hey " << name << " you are " << age << " years old" << endl;
    }
};

int main(){
    Person john;
    john.name = "John";
    john.age = 25;
    john.greet();
}