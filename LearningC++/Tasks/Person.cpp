// task - define class person with age and features

#include <iostream>
#include <string>

class Person {
private:
    std::string name;
    int age;

public:
    void setName(const std::string& n) {
        name = n;
    }

    void setAge(int a) {
        age = a;
    }

    std::string getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

    bool isAdult() const {
        return age >= 18;
    }

    void display() const {
        std::cout << "Name: " << name << "\nAge: " << age << "\nAdult: " << (isAdult() ? "Yes" : "No") << std::endl;
    }
};

int main() {
    Person person;
    person.setName("Alice");
    person.setAge(20);
    person.display();
    return 0;
}
