#include <iostream>
#include <vector>
#include <string>

class Student {
private:
    std::string name;
    std::vector<int> grades;

public:
    Student(const std::string& studentName) : name(studentName) {}

    void addGrade(int grade) {
        grades.push_back(grade);
    }

    double getAverageGrade() const {
        if (grades.empty()) return 0.0;
        int sum = 0;
        for (int grade : grades) {
            sum += grade;
        }
        return static_cast<double>(sum) / grades.size();
    }

    std::string getName() const {
        return name;
    }

    void display() const {
        std::cout << "Student: " << name << "\nGrades: ";
        for (int grade : grades) {
            std::cout << grade << " ";
        }
        std::cout << "\nAverage Grade: " << getAverageGrade() << std::endl;
    }
};

class GradeManager {
private:
    std::vector<Student> students;

public:
    void addStudent(const std::string& name) {
        students.emplace_back(name);
    }

    void addGrade(const std::string& name, int grade) {
        for (auto& student : students) {
            if (student.getName() == name) {
                student.addGrade(grade);
                return;
            }
        }
        std::cout << "Student not found." << std::endl;
    }

    void displayStudents() const {
        for (const auto& student : students) {
            student.display();
        }
    }
};

int main() {
    GradeManager manager;
    manager.addStudent("Alice");
    manager.addStudent("Bob");

    manager.addGrade("Alice", 90);
    manager.addGrade("Alice", 85);
    manager.addGrade("Bob", 78);

    std::cout << "Student Details:\n";
    manager.displayStudents();

    return 0;
}
