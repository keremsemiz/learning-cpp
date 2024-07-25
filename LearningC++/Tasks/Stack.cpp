#include <iostream>

class Stack {
private:
    static const int MAX = 1000;
    int arr[MAX];
    int top;

public:
    Stack() : top(-1) {}

    bool push(int x) {
        if (top >= (MAX - 1)) {
            std::cout << "Stack Overflow\n";
            return false;
        } else {
            arr[++top] = x;
            return true;
        }
    }

    int pop() {
        if (top < 0) {
            std::cout << "Stack Underflow\n";
            return -1;
        } else {
            return arr[top--];
        }
    }

    bool isEmpty() {
        return (top < 0);
    }
};

int main() {
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    std::cout << "Popped from stack: " << stack.pop() << std::endl;
    std::cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << std::endl;
    return 0;
}
