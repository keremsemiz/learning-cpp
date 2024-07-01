// task - define class circle with methods to get circumference & area

#include <iostream>

class Circle {
private:
    double radius;

public:
    void setRadius(double r) {
        radius = r;
    }

    double getRadius() const {
        return radius;
    }

    double area() const {
        return 3.14159 * radius * radius;
    }

    double circumference() const {
        return 2 * 3.14159 * radius;
    }

    void display() const {
        std::cout << "Radius: " << radius << "\nArea: " << area() << "\nCircumference: " << circumference() << std::endl;
    }
};

int main() {
    Circle circle;
    circle.setRadius(5.0);
    circle.display();
    return 0;
}
