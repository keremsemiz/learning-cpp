#include <iostream>

class Fraction {
private:
    int numerator;
    int denominator;

public:
    Fraction(int num = 0, int denom = 1) : numerator(num), denominator(denom) {
        if (denom == 0) {
            std::cerr << "Error: Denominator cannot be zero." << std::endl;
            denominator = 1;
        }
    }

    Fraction operator+(const Fraction& other) const {
        return Fraction(numerator * other.denominator + other.numerator * denominator, denominator * other.denominator);
    }

    Fraction operator-(const Fraction& other) const {
        return Fraction(numerator * other.denominator - other.numerator * denominator, denominator * other.denominator);
    }

    Fraction operator*(const Fraction& other) const {
        return Fraction(numerator * other.numerator, denominator * other.denominator);
    }

    Fraction operator/(const Fraction& other) const {
        return Fraction(numerator * other.denominator, denominator * other.numerator);
    }

    void display() const {
        std::cout << numerator << "/" << denominator << std::endl;
    }
};

int main() {
    Fraction f1(1, 2), f2(3, 4);
    Fraction result;

    result = f1 + f2;
    std::cout << "Addition: ";
    result.display();

    result = f1 - f2;
    std::cout << "Subtraction: ";
    result.display();

    result = f1 * f2;
    std::cout << "Multiplication: ";
    result.display();

    result = f1 / f2;
    std::cout << "Division: ";
    result.display();

    return 0;
}
