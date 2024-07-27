#include <iostream>
#include <vector>

class Polynomial {
private:
    std::vector<int> coefficients;

public:
    Polynomial(const std::vector<int>& coeffs) : coefficients(coeffs) {}

    Polynomial operator+(const Polynomial& other) const {
        size_t maxSize = std::max(coefficients.size(), other.coefficients.size());
        std::vector<int> result(maxSize, 0);
        
        for (size_t i = 0; i < maxSize; ++i) {
            if (i < coefficients.size()) result[i] += coefficients[i];
            if (i < other.coefficients.size()) result[i] += other.coefficients[i];
        }
        return Polynomial(result);
    }

    Polynomial operator-(const Polynomial& other) const {
        size_t maxSize = std::max(coefficients.size(), other.coefficients.size());
        std::vector<int> result(maxSize, 0);

        for (size_t i = 0; i < maxSize; ++i) {
            if (i < coefficients.size()) result[i] += coefficients[i];
            if (i < other.coefficients.size()) result[i] -= other.coefficients[i];
        }
        return Polynomial(result);
    }

    Polynomial operator*(const Polynomial& other) const {
        std::vector<int> result(coefficients.size() + other.coefficients.size() - 1, 0);

        for (size_t i = 0; i < coefficients.size(); ++i) {
            for (size_t j = 0; j < other.coefficients.size(); ++j) {
                result[i + j] += coefficients[i] * other.coefficients[j];
            }
        }
        return Polynomial(result);
    }

    int evaluate(int x) const {
        int result = 0;
        int xPower = 1;

        for (int coeff : coefficients) {
            result += coeff * xPower;
            xPower *= x;
        }
        return result;
    }

    void display() const {
        for (int i = coefficients.size() - 1; i >= 0; --i) {
            if (coefficients[i] != 0) {
                if (i != coefficients.size() - 1 && coefficients[i] > 0) std::cout << "+";
                if (i == 0) {
                    std::cout << coefficients[i];
                } else {
                    std::cout << coefficients[i] << "x^" << i;
                }
            }
        }
        std::cout << std::endl;
    }
};

int main() {
    Polynomial p1({1, 2, 3}); // 3x^2 + 2x + 1
    Polynomial p2({2, 1});    // x + 2

    Polynomial sum = p1 + p2;
    Polynomial diff = p1 - p2;
    Polynomial prod = p1 * p2;

    std::cout << "p1: ";
    p1.display();
    std::cout << "p2: ";
    p2.display();
    std::cout << "Sum: ";
    sum.display();
    std::cout << "Difference: ";
    diff.display();
    std::cout << "Product: ";
    prod.display();
    std::cout << "p1 evaluated at x=2: " << p1.evaluate(2) << std::endl;

    return 0;
}
