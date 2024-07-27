#include <iostream>
#include <vector>
#include <string>

class Record {
private:
    int ID;
    std::string Name;
    int Age;

public:
    Record(int id, const std::string& name, int age) : ID(id), Name(name), Age(age) {}

    int getID() const { return ID; }
    std::string getName() const { return Name; }
    int getAge() const { return Age; }

    void setName(const std::string& name) { Name = name; }
    void setAge(int age) { Age = age; }

    void display() const {
        std::cout << "ID: " << ID << ", Name: " << Name << ", Age: " << Age << std::endl;
    }
};

class Database {
private:
    std::vector<Record> records;

public:
    void addRecord(int id, const std::string& name, int age) {
        records.emplace_back(id, name, age);
    }

    void deleteRecord(int id) {
        auto it = std::remove_if(records.begin(), records.end(), [id](const Record& record) {
            return record.getID() == id;
        });
        if (it != records.end()) {
            records.erase(it, records.end());
        } else {
            std::cout << "Record not found.\n";
        }
    }

    void updateRecord(int id, const std::string& name, int age) {
        for (auto& record : records) {
            if (record.getID() == id) {
                record.setName(name);
                record.setAge(age);
                return;
            }
        }
        std::cout << "Record not found.\n";
    }

    void displayRecords() const {
        for (const auto& record : records) {
            record.display();
        }
    }
};

int main() {
    Database db;
    db.addRecord(1, "Alice", 30);
    db.addRecord(2, "Bob", 25);
    db.displayRecords();

    std::cout << "\nUpdating Bob's age...\n";
    db.updateRecord(2, "Bob", 26);
    db.displayRecords();

    std::cout << "\nDeleting Alice's record...\n";
    db.deleteRecord(1);
    db.displayRecords();

    return 0;
}
