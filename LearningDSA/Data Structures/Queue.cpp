#include <iostream>

class Queue {
private:
    static const int MAX = 1000;
    int arr[MAX];
    int front, rear;

public:
    Queue() : front(0), rear(0) {}

    bool enqueue(int x) {
        if (rear == MAX) {
            std::cout << "Queue Overflow" << std::endl;
            return false;
        } else {
            arr[rear++] = x;
            std::cout << x << " enqueued into queue" << std::endl;
            return true;
        }
    }

    int dequeue() {
        if (front == rear) {
            std::cout << "Queue Underflow" << std::endl;
            return 0;
        } else {
            int x = arr[front++];
            return x;
        }
    }

    bool isEmpty() {
        return (front == rear);
    }

    int peek() {
        if (front == rear) {
            std::cout << "Queue is Empty" << std::endl;
            return 0;
        } else {
            int x = arr[front];
            return x;
        }
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    std::cout << q.dequeue() << " dequeued from queue\n";
    std::cout << "Front element is " << q.peek() << std::endl;
    std::cout << "Queue is empty: " << (q.isEmpty() ? "Yes" : "No") << std::endl;
    return 0;
}
