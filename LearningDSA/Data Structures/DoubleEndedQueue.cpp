#include <iostream>

class Deque {
private:
    int* arr;
    int front, rear, size;
    int capacity;

public:
    Deque(int c) : capacity(c), size(0), front(0), rear(c - 1) {
        arr = new int[capacity];
    }

    ~Deque() {
        delete[] arr;
    }

    bool isFull() {
        return (size == capacity);
    }

    bool isEmpty() {
        return (size == 0);
    }

    void insertFront(int value) {
        if (isFull()) {
            std::cout << "Deque Overflow" << std::endl;
            return;
        }
        front = (front - 1 + capacity) % capacity;
        arr[front] = value;
        size++;
        std::cout << value << " inserted at front" << std::endl;
    }

    void insertRear(int value) {
        if (isFull()) {
            std::cout << "Deque Overflow" << std::endl;
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = value;
        size++;
        std::cout << value << " inserted at rear" << std::endl;
    }

    void deleteFront() {
        if (isEmpty()) {
            std::cout << "Deque Underflow" << std::endl;
            return;
        }
        front = (front + 1) % capacity;
        size--;
    }

    void deleteRear() {
        if (isEmpty()) {
            std::cout << "Deque Underflow" << std::endl;
            return;
        }
        rear = (rear - 1 + capacity) % capacity;
        size--;
    }

    int getFront() {
        if (isEmpty()) {
            std::cout << "Deque is Empty" << std::endl;
            return -1;
        }
        return arr[front];
    }

    int getRear() {
        if (isEmpty()) {
            std::cout << "Deque is Empty" << std::endl;
            return -1;
        }
        return arr[rear];
    }
};

int main() {
    Deque dq(5);
    dq.insertRear(5);
    dq.insertRear(10);
    dq.insertFront(15);
    dq.insertFront(20);
    dq.deleteRear();
    std::cout << "Front element: " << dq.getFront() << std::endl;
    std::cout << "Rear element: " << dq.getRear() << std::endl;
    return 0;
}