#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

class Book {
private:
    std::string title;
    std::string author;
    std::string ISBN;
    bool isAvailable;

public:
    Book(const std::string& t, const std::string& a, const std::string& i)
        : title(t), author(a), ISBN(i), isAvailable(true) {}

    std::string getTitle() const { return title; }
    std::string getAuthor() const { return author; }
    std::string getISBN() const { return ISBN; }
    bool getAvailability() const { return isAvailable; }

    void borrowBook() { isAvailable = false; }
    void returnBook() { isAvailable = true; }

    void display() const {
        std::cout << "Title: " << title << "\nAuthor: " << author
                  << "\nISBN: " << ISBN << "\nAvailable: " << (isAvailable ? "Yes" : "No") << std::endl;
    }
};

class Member {
private:
    std::string name;
    std::vector<std::string> borrowedBooks; // Stores ISBNs of borrowed books

public:
    Member(const std::string& n) : name(n) {}

    std::string getName() const { return name; }

    void borrowBook(const std::string& ISBN) {
        borrowedBooks.push_back(ISBN);
    }

    void returnBook(const std::string& ISBN) {
        borrowedBooks.erase(std::remove(borrowedBooks.begin(), borrowedBooks.end(), ISBN), borrowedBooks.end());
    }

    void display() const {
        std::cout << "Member: " << name << "\nBorrowed Books: ";
        for (const auto& isbn : borrowedBooks) {
            std::cout << isbn << " ";
        }
        std::cout << std::endl;
    }
};

class Library {
private:
    std::unordered_map<std::string, Book> books; // Key: ISBN
    std::unordered_map<std::string, Member> members; // Key: Member name

public:
    void addBook(const std::string& title, const std::string& author, const std::string& ISBN) {
        books[ISBN] = Book(title, author, ISBN);
    }

    void registerMember(const std::string& name) {
        members[name] = Member(name);
    }

    void lendBook(const std::string& ISBN, const std::string& memberName) {
        if (books.find(ISBN) != books.end() && members.find(memberName) != members.end()) {
            if (books[ISBN].getAvailability()) {
                books[ISBN].borrowBook();
                members[memberName].borrowBook(ISBN);
                std::cout << memberName << " has borrowed " << books[ISBN].getTitle() << std::endl;
            } else {
                std::cout << "Book is not available.\n";
            }
        } else {
            std::cout << "Invalid book ISBN or member name.\n";
        }
    }

    void returnBook(const std::string& ISBN, const std::string& memberName) {
        if (books.find(ISBN) != books.end() && members.find(memberName) != members.end()) {
            books[ISBN].returnBook();
            members[memberName].returnBook(ISBN);
            std::cout << memberName << " has returned " << books[ISBN].getTitle() << std::endl;
        } else {
            std::cout << "Invalid book ISBN or member name.\n";
        }
    }

    void displayBooks() const {
        for (const auto& pair : books) {
            pair.second.display();
        }
    }

    void displayMembers() const {
        for (const auto& pair : members) {
            pair.second.display();
        }
    }
};

int main() {
    Library library;
    library.addBook("1984", "George Orwell", "123456789");
    library.addBook("To Kill a Mockingbird", "Harper Lee", "987654321");
    library.registerMember("Alice Johnson");
    library.registerMember("Bob Smith");

    std::cout << "Library Books:\n";
    library.displayBooks();

    std::cout << "\nLibrary Members:\n";
    library.displayMembers();

    std::cout << "\nLending '1984' to Alice...\n";
    library.lendBook("123456789", "Alice Johnson");
    library.displayBooks();
    library.displayMembers();

    std::cout << "\nReturning '1984' from Alice...\n";
    library.returnBook("123456789", "Alice Johnson");
    library.displayBooks();
    library.displayMembers();

    return 0;
}
