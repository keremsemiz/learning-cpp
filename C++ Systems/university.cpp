#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Student;

class Course {
private:
    std::string courseCode;
    std::string courseName;
    int credits;
    std::vector<int> enrolledStudents;

public:
    Course(const std::string& code, const std::string& name, int cr)
        : courseCode(code), courseName(name), credits(cr) {}

    std::string getCourseCode() const { return courseCode; }
    std::string getCourseName() const { return courseName; }
    int getCredits() const { return credits; }

    void enrollStudent(int studentId) {
        enrolledStudents.push_back(studentId);
    }

    void dropStudent(int studentId) {
        enrolledStudents.erase(std::remove(enrolledStudents.begin(), enrolledStudents.end(), studentId), enrolledStudents.end());
    }

    void display() const {
        std::cout << "Course Code: " << courseCode << ", Name: " << courseName << ", Credits: " << credits << std::endl;
    }
};

class Student {
private:
    int studentId;
    std::string studentName;
    std::vector<std::string> enrolledCourses;

public:
    Student(int id, const std::string& name) : studentId(id), studentName(name) {}

    int getStudentId() const { return studentId; }
    std::string getStudentName() const { return studentName; }

    void enrollInCourse(const std::string& courseCode) {
        enrolledCourses.push_back(courseCode);
    }

    void dropCourse(const std::string& courseCode) {
        enrolledCourses.erase(std::remove(enrolledCourses.begin(), enrolledCourses.end(), courseCode), enrolledCourses.end());
    }

    void displayTranscript() const {
        std::cout << "Student ID: " << studentId << ", Name: " << studentName << "\nEnrolled Courses:\n";
        for (const auto& course : enrolledCourses) {
            std::cout << "- " << course << std::endl;
        }
    }
};

class University {
private:
    std::vector<Student> students;
    std::vector<Course> courses;

public:
    void registerStudent(const std::string& name) {
        static int nextStudentId = 1;
        students.emplace_back(nextStudentId++, name);
    }

    void addCourse(const std::string& code, const std::string& name, int credits) {
        courses.emplace_back(code, name, credits);
    }

    void enrollStudentInCourse(int studentId, const std::string& courseCode) {
        auto studentIt = std::find_if(students.begin(), students.end(), [&](const Student& student) {
            return student.getStudentId() == studentId;
        });

        auto courseIt = std::find_if(courses.begin(), courses.end(), [&](const Course& course) {
            return course.getCourseCode() == courseCode;
        });

        if (studentIt != students.end() && courseIt != courses.end()) {
            studentIt->enrollInCourse(courseCode);
            courseIt->enrollStudent(studentId);
            std::cout << "Student " << studentId << " enrolled in course " << courseCode << std::endl;
        } else {
            std::cout << "Student or course not found.\n";
        }
    }

    void dropStudentFromCourse(int studentId, const std::string& courseCode) {
        auto studentIt = std::find_if(students.begin(), students.end(), [&](const Student& student) {
            return student.getStudentId() == studentId;
        });

        auto courseIt = std::find_if(courses.begin(), courses.end(), [&](const Course& course) {
            return course.getCourseCode() == courseCode;
        });

        if (studentIt != students.end() && courseIt != courses.end()) {
            studentIt->dropCourse(courseCode);
            courseIt->dropStudent(studentId);
            std::cout << "Student " << studentId << " dropped from course " << courseCode << std::endl;
        } else {
            std::cout << "Student or course not found.\n";
        }
    }

    void displayStudentTranscript(int studentId) const {
        auto studentIt = std::find_if(students.begin(), students.end(), [&](const Student& student) {
            return student.getStudentId() == studentId;
        });

        if (studentIt != students.end()) {
            studentIt->displayTranscript();
        } else {
            std::cout << "Student not found.\n";
        }
    }
};

int main() {
    University university;

    university.registerStudent("Alice");
    university.registerStudent("Bob");

    university.addCourse("CS101", "Introduction to Computer Science", 3);
    university.addCourse("MATH101", "Calculus I", 4);

    university.enrollStudentInCourse(1, "CS101");
    university.enrollStudentInCourse(1, "MATH101");
    university.enrollStudentInCourse(2, "CS101");

    std::cout << "\nAlice's Transcript:\n";
    university.displayStudentTranscript(1);

    std::cout << "\nBob's Transcript:\n";
    university.displayStudentTranscript(2);

    std::cout << "\nDropping Alice from MATH101...\n";
    university.dropStudentFromCourse(1, "MATH101");

    std::cout << "\nAlice's Transcript After Dropping MATH101:\n";
    university.displayStudentTranscript(1);

    return 0;
}
