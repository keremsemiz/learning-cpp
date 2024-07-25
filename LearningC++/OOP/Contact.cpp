#include <iostream>
#include <vector>
#include <string>

class Contact {
private:
    std::string name;
    std::string phoneNumber;

public:
    Contact(std::string n, std::string p) : name(n), phoneNumber(p) {}

    std::string getName() const {
        return name;
    }

    std::string getPhoneNumber() const {
        return phoneNumber;
    }

    void display() const {
        std::cout << "Name: " << name << ", Phone Number: " << phoneNumber << std::endl;
    }
};

class ContactBook {
private:
    std::vector<Contact> contacts;

public:
    void addContact(const std::string& name, const std::string& phoneNumber) {
        contacts.push_back(Contact(name, phoneNumber));
    }

    void displayContacts() const {
        for (const auto& contact : contacts) {
            contact.display();
        }
    }

    void searchContact(const std::string& name) const {
        for (const auto& contact : contacts) {
            if (contact.getName() == name) {
                contact.display();
                return;
            }
        }
        std::cout << "Contact not found.\n";
    }
};

int main() {
    ContactBook book;
    book.addContact("Alice", "123-456-7890");
    book.addContact("Bob", "987-654-3210");

    std::cout << "All Contacts:\n";
    book.displayContacts();

    std::cout << "\nSearch for Alice:\n";
    book.searchContact("Alice");

    return 0;
}
