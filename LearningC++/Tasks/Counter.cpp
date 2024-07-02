// task - design a simple counter like a react element

#include <iostream>

class Counter {
private:
    int count;

public:
    Counter() : count(0) {}

    void increment() {
        ++count;
    }

    void decrement() {
        --count;
    }

    int getCount() const {
        return count;
    }

    void display() const {
        std::cout << "Count: " << count << std::endl;
    }
};

int main() {
    Counter counter;
    counter.increment();
    counter.increment();
    counter.display();
    counter.decrement();
    counter.display();
    return 0;
}
