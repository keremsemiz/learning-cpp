// task - create a timer with conversion

#include <iostream>

class Timer {
private:
    int seconds;

public:
    void setSeconds(int s) {
        seconds = s;
    }

    int getSeconds() const {
        return seconds;
    }

    double toMinutes() const {
        return seconds / 60.0;
    }

    double toHours() const {
        return seconds / 3600.0;
    }

    void display() const {
        std::cout << "Seconds: " << seconds << "\nMinutes: " << toMinutes() << "\nHours: " << toHours() << std::endl;
    }
};

int main() {
    Timer timer;
    timer.setSeconds(3600);
    timer.display();
    return 0;
}
