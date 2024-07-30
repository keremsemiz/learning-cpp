#include <iostream>

class CircularQueue {
private:
    int *arr;
    int front, rear, size;
    int capacity;

public:
    CircularQueue(int c) : capacity(c) {
        arr = new int[capacity];
        front = size = 0;
        rear = capacity - 1;
    }

    ~CircularQueue() {
        delete[] arr;
    }

    bool isFull() {
        return (size == capacity);
    }

    bool isEmpty() {
        return (size == 0);
    }

    bool enqueue(int value) {
        if (isFull()) {
            std::cout << "Queue Overflow" << std::endl;
            return false;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = value;
        size++;
        std::cout << value << " enqueued into queue" << std::endl;
        return true;
    }

    int dequeue() {
        if (isEmpty()) {
            std::cout << "Queue Underflow" << std::endl;
            return -1;
        }
        int value = arr[front];
        front = (front + 1) % capacity;
        size--;
        return value;
    }

    int peek() {
        if (isEmpty()) {
            std::cout << "Queue is Empty" << std::endl;
            return -1;
        }
        return arr[front];
    }
};

int main() {
    CircularQueue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    std::cout << q.dequeue() << " dequeued from queue\n";
    std::cout << "Front element is " << q.peek() << std::endl;
    std::cout << "Queue is empty: " << (q.isEmpty() ? "Yes" : "No") << std::endl;
    std::cout << "Queue is full: " << (q.isFull() ? "Yes" : "No") << std::endl;
    return 
