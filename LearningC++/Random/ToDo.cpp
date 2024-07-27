#include <iostream>
#include <vector>
#include <string>

class Task {
private:
    std::string description;
    bool isCompleted;
    int priority;

public:
    Task(const std::string& desc, int prio)
        : description(desc), isCompleted(false), priority(prio) {}

    void markCompleted() {
        isCompleted = true;
    }

    std::string getDescription() const {
        return description;
    }

    bool getStatus() const {
        return isCompleted;
    }

    int getPriority() const {
        return priority;
    }

    void display() const {
        std::cout << "Task: " << description 
                  << " | Priority: " << priority 
                  << " | Status: " << (isCompleted ? "Completed" : "Incomplete") 
                  << std::endl;
    }
};

class ToDoList {
private:
    std::vector<Task> tasks;

public:
    void addTask(const std::string& description, int priority) {
        tasks.emplace_back(description, priority);
    }

    void markTaskCompleted(const std::string& description) {
        for (auto& task : tasks) {
            if (task.getDescription() == description) {
                task.markCompleted();
                return;
            }
        }
        std::cout << "Task not found.\n";
    }

    void removeTask(const std::string& description) {
        tasks.erase(
            std::remove_if(tasks.begin(), tasks.end(), [&](const Task& task) {
                return task.getDescription() == description;
            }), tasks.end());
    }

    void displayTasks() const {
        for (const auto& task : tasks) {
            task.display();
        }
    }
};

int main() {
    ToDoList todoList;
    todoList.addTask("Buy groceries", 2);
    todoList.addTask("Finish C++ project", 1);
    todoList.addTask("Call Alice", 3);

    std::cout << "To-Do List:\n";
    todoList.displayTasks();

    std::cout << "\nMarking 'Finish C++ project' as completed...\n";
    todoList.markTaskCompleted("Finish C++ project");
    todoList.displayTasks();

    std::cout << "\nRemoving 'Call Alice' from the list...\n";
    todoList.removeTask("Call Alice");
    todoList.displayTasks();

    return 0;
}
