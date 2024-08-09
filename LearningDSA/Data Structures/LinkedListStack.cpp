#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedListStack {
private:
    Node* top;

public:
    LinkedListStack() : top(nullptr) {}

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        std::cout << value << " pushed onto stack" << std::endl;
    }

    int pop() {
        if (isEmpty()) {
            std::cout << "Stack Underflow" << std::endl;
            return -1;
        }
        int poppedValue = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return poppedValue;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    int peek() {
        if (!isEmpty())
            return top->data;
        else
            std::cout << "Stack is empty" << std::endl;
        return -1;
    }
};

int main() {
    LinkedListStack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    std::cout << stack.pop() << " popped from stack\n";
    std::cout << "Top element is " << stack.peek() << std::endl;
    std::cout << "Stack is empty: " << (stack.isEmpty() ? "Yes" : "No") << std::endl;
    return 0;
}