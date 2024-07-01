// task - calculate factorial

#include <iostream>

int factorial(int num) {
    if (num == 0) return 1;
    int fact = 1;
    for (int i = 1; i <= num; ++i) {
        fact *= i;
    }
    return fact;
}

int main() {
    int num = 5;
    std::cout << "Factorial of " << num << " is " << factorial(num) << std::endl;
    return 0;
}
