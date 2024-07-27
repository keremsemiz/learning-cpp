#include <iostream>
#include <vector>
#include <string>

class Book {
private:
    std::string title;
    std::string author;
    std::string ISBN;
    bool isAvailable;

public:
    Book(const std::string& t, const std::string& a, const std::string& i)
        : title(t), author(a), ISBN(i), isAvailable(true) {}

    std::string getTitle() const {
        return title;
    }

    std::string getAuthor() const {
        return author;
    }

    std::string getISBN() const {
        return ISBN;
    }

    bool checkAvailability() const {
        return isAvailable;
    }

    void checkOut() {
        if (isAvailable) {
            isAvailable = false;
        } else {
            std::cout << "Book is already checked out.\n";
        }
    }

    void returnBook() {
        isAvailable = true;
    }

    void display() const {
        std::cout << "Title: " << title 
                  << " | Author: " << author 
                  << " | ISBN: " << ISBN 
                  << " | Status: " << (isAvailable ? "Available" : "Checked Out") 
                  << std::endl;
    }
};

class Library {
private:
    std::vector<Book> books;

public:
    void addBook(const std::string& title, const std::string& author, const std::string& ISBN) {
        books.emplace_back(title, author, ISBN);
    }

    void checkOutBook(const std::string& ISBN) {
        for (auto& book : books) {
            if (book.getISBN() == ISBN) {
                book.checkOut();
                return;
            }
        }
        std::cout << "Book not found.\n";
    }

    void returnBook(const std::string& ISBN) {
        for (auto& book : books) {
            if (book.getISBN() == ISBN) {
                book.returnBook();
                return;
            }
        }
        std::cout << "Book not found.\n";
    }

    void displayBooks() const {
        for (const auto& book : books) {
            book.display();
        }
    }
};

int main() {
    Library library;
    library.addBook("1984", "George Orwell", "123456789");
    library.addBook("To Kill a Mockingbird", "Harper Lee", "987654321");

    std::cout << "Library Inventory:\n";
    library.displayBooks();

    std::cout << "\nChecking out '1984'...\n";
    library.checkOutBook("123456789");
    library.displayBooks();

    std::cout << "\nReturning '1984'...\n";
    library.returnBook("123456789");
    library.displayBooks();

    return 0;
}
