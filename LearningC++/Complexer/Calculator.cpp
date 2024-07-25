#include <iostream>
#include <cmath>

class Calculator {
public:
    double add(double a, double b) {
        return a + b;
    }

    double subtract(double a, double b) {
        return a - b;
    }

    double multiply(double a, double b) {
        return a * b;
    }

    double divide(double a, double b) {
        if (b != 0) {
            return a / b;
        }
        std::cerr << "Error: Division by zero" << std::endl;
        return 0;
    }
};

class ScientificCalculator : public Calculator {
public:
    double power(double base, double exponent) {
        return pow(base, exponent);
    }

    double squareRoot(double number) {
        return sqrt(number);
    }
};

int main() {
    ScientificCalculator sciCalc;

    double a = 10.0, b = 2.0;
    std::cout << "Addition: " << sciCalc.add(a, b) << std::endl;
    std::cout << "Subtraction: " << sciCalc.subtract(a, b) << std::endl;
    std::cout << "Multiplication: " << sciCalc.multiply(a, b) << std::endl;
    std::cout << "Division: " << sciCalc.divide(a, b) << std::endl;

    std::cout << "Power: " << sciCalc.power(a, b) << std::endl;
    std::cout << "Square Root of " << a << ": " << sciCalc.squareRoot(a) << std::endl;

    return 0;
}
