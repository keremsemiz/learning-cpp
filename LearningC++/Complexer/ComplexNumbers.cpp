#include <iostream>
#include <cmath>

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    Complex operator*(const Complex& other) const {
        return Complex(real * other.real - imag * other.imag,
                       real * other.imag + imag * other.real);
    }

    Complex operator/(const Complex& other) const {
        double denom = other.real * other.real + other.imag * other.imag;
        return Complex((real * other.real + imag * other.imag) / denom,
                       (imag * other.real - real * other.imag) / denom);
    }

    double magnitude() const {
        return sqrt(real * real + imag * imag);
    }

    double phase() const {
        return atan2(imag, real);
    }

    void display() const {
        std::cout << real << " + " << imag << "i" << std::endl;
    }
};

int main() {
    Complex c1(3, 4);
    Complex c2(1, -2);

    Complex sum = c1 + c2;
    Complex diff = c1 - c2;
    Complex prod = c1 * c2;
    Complex quot = c1 / c2;

    std::cout << "c1: ";
    c1.display();
    std::cout << "c2: ";
    c2.display();
    std::cout << "Sum: ";
    sum.display();
    std::cout << "Difference: ";
    diff.display();
    std::cout << "Product: ";
    prod.display();
    std::cout << "Quotient: ";
    quot.display();

    std::cout << "Magnitude of c1: " << c1.magnitude() << std::endl;
    std::cout << "Phase of c1: " << c1.phase() << " radians" << std::endl;

    return 0;
}
