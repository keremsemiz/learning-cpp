// task - define a class car with private member vars

#include <iostream>
#include <string>

class Car {
private:
    std::string make;
    std::string model;
    int year;

public:
    void setMake(const std::string& m) {
        make = m;
    }

    void setModel(const std::string& m) {
        model = m;
    }

    void setYear(int y) {
        year = y;
    }

    std::string getMake() const {
        return make;
    }

    std::string getModel() const {
        return model;
    }

    int getYear() const {
        return year;
    }

    void display() const {
        std::cout << "Make: " << make << "\nModel: " << model << "\nYear: " << year << std::endl;
    }
};

int main() {
    Car car;
    car.setMake("Toyota");
    car.setModel("Corolla");
    car.setYear(2020);
    car.display();
    return 0;
}
