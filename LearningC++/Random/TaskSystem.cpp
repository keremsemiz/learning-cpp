#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

class Task {
private:
    std::string taskName;
    int priority;
    int duration; // mins ofc what is this seconds

public:
    Task(const std::string& name, int prio, int dur)
        : taskName(name), priority(prio), duration(dur) {}

    std::string getTaskName() const { return taskName; }
    int getPriority() const { return priority; }
    int getDuration() const { return duration; }

    void display() const {
        std::cout << "Task: " << taskName << ", Priority: " << priority << ", Duration: " << duration << " minutes" << std::endl;
    }
};

class TaskScheduler {
private:
    std::vector<Task> tasks;

public:
    void addTask(const std::string& name, int priority, int duration) {
        tasks.emplace_back(name, priority, duration);
    }

    void removeTask(const std::string& name) {
        tasks.erase(std::remove_if(tasks.begin(), tasks.end(), [&](const Task& task) {
            return task.getTaskName() == name;
        }), tasks.end());
    }

    void displayTasks() const {
        std::vector<Task> sortedTasks = tasks;
        std::sort(sortedTasks.begin(), sortedTasks.end(), [](const Task& a, const Task& b) {
            return a.getPriority() < b.getPriority();
        });

        for (const auto& task : sortedTasks) {
            task.display();
        }
    }
};

int main() {
    TaskScheduler scheduler;
    scheduler.addTask("Write report", 2, 120);
    scheduler.addTask("Attend meeting", 1, 60);
    scheduler.addTask("Code review", 3, 90);

    std::cout << "All Tasks:\n";
    scheduler.displayTasks();

    std::cout << "\nRemoving 'Code review'...\n";
    scheduler.removeTask("Code review");
    scheduler.displayTasks();

    return 0;
}
