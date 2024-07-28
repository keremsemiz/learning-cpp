#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Contact {
private:
    std::string name;
    std::string phone;
    std::string email;

public:
    Contact(const std::string& n, const std::string& p, const std::string& e)
        : name(n), phone(p), email(e) {}

    std::string getName() const { return name; }
    std::string getPhone() const { return phone; }
    std::string getEmail() const { return email; }

    void display() const {
        std::cout << "Name: " << name << ", Phone: " << phone << ", Email: " << email << std::endl;
    }
};

class Group {
private:
    std::string groupName;
    std::vector<Contact> contacts;

public:
    Group(const std::string& name) : groupName(name) {}

    std::string getGroupName() const { return groupName; }

    void addContact(const Contact& contact) {
        contacts.push_back(contact);
    }

    void removeContact(const std::string& contactName) {
        contacts.erase(std::remove_if(contacts.begin(), contacts.end(), [&](const Contact& contact) {
            return contact.getName() == contactName;
        }), contacts.end());
    }

    void listContacts() const {
        std::cout << "Group: " << groupName << "\nContacts:\n";
        for (const auto& contact : contacts) {
            contact.display();
        }
    }

    Contact* searchContact(const std::string& contactName) {
        auto it = std::find_if(contacts.begin(), contacts.end(), [&](const Contact& contact) {
            return contact.getName() == contactName;
        });
        return (it != contacts.end()) ? &(*it) : nullptr;
    }
};

class ContactManager {
private:
    std::vector<Group> groups;

public:
    void addGroup(const std::string& groupName) {
        groups.emplace_back(groupName);
    }

    void addContactToGroup(const std::string& groupName, const Contact& contact) {
        auto it = std::find_if(groups.begin(), groups.end(), [&](const Group& group) {
            return group.getGroupName() == groupName;
        });

        if (it != groups.end()) {
            it->addContact(contact);
        } else {
            std::cout << "Group not found." << std::endl;
        }
    }

    void removeContactFromGroup(const std::string& groupName, const std::string& contactName) {
        auto it = std::find_if(groups.begin(), groups.end(), [&](const Group& group) {
            return group.getGroupName() == groupName;
        });

        if (it != groups.end()) {
            it->removeContact(contactName);
        } else {
            std::cout << "Group not found." << std::endl;
        }
    }

    void listContactsInGroup(const std::string& groupName) const {
        auto it = std::find_if(groups.begin(), groups.end(), [&](const Group& group) {
            return group.getGroupName() == groupName;
        });

        if (it != groups.end()) {
            it->listContacts();
        } else {
            std::cout << "Group not found." << std::endl;
        }
    }

    void searchContactInGroup(const std::string& groupName, const std::string& contactName) const {
        auto it = std::find_if(groups.begin(), groups.end(), [&](const Group& group) {
            return group.getGroupName() == groupName;
        });

        if (it != groups.end()) {
            Contact* contact = it->searchContact(contactName);
            if (contact) {
                contact->display();
            } else {
                std::cout << "Contact not found." << std::endl;
            }
        } else {
            std::cout << "Group not found." << std::endl;
        }
    }

    void listAllGroups() const {
        std::cout << "Groups:\n";
        for (const auto& group : groups) {
            std::cout << "- " << group.getGroupName() << std::endl;
        }
    }
};

int main() {
    ContactManager manager;

    manager.addGroup("Family");
    manager.addGroup("Friends");
    manager.addGroup("Work");

    manager.addContactToGroup("Family", Contact("Alice", "123-456-7890", "alice@example.com"));
    manager.addContactToGroup("Friends", Contact("Bob", "234-567-8901", "bob@example.com"));
    manager.addContactToGroup("Work", Contact("Charlie", "345-678-9012", "charlie@example.com"));

    std::cout << "All Groups:\n";
    manager.listAllGroups();

    std::cout << "\nContacts in 'Family' group:\n";
    manager.listContactsInGroup("Family");

    std::cout << "\nSearching for 'Alice' in 'Family' group:\n";
    manager.searchContactInGroup("Family", "Alice");

    std::cout << "\nRemoving 'Alice' from 'Family' group...\n";
    manager.removeContactFromGroup("Family", "Alice");

    std::cout << "\nContacts in 'Family' group:\n";
    manager.listContactsInGroup("Family");

    return 0;
}
