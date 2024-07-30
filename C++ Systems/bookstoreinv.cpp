#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Book {
private:
    std::string ISBN;
    std::string title;
    std::string author;
    double price;
    int stock;

public:
    Book(const std::string& isbn, const std::string& t, const std::string& a, double p, int s)
        : ISBN(isbn), title(t), author(a), price(p), stock(s) {}

    std::string getISBN() const { return ISBN; }
    std::string getTitle() const { return title; }
    std::string getAuthor() const { return author; }
    double getPrice() const { return price; }
    int getStock() const { return stock; }

    void restock(int amount) { stock += amount; }
    void sell(int amount) { if (stock >= amount) stock -= amount; }

    void display() const {
        std::cout << "ISBN: " << ISBN << ", Title: " << title << ", Author: " << author
                  << ", Price: $" << price << ", Stock: " << stock << std::endl;
    }
};

class Customer {
private:
    int customerId;
    std::string name;
    std::vector<std::string> purchasedBooks;

public:
    Customer(int id, const std::string& n) : customerId(id), name(n) {}

    int getCustomerId() const { return customerId; }
    std::string getName() const { return name; }

    void purchaseBook(const std::string& ISBN) {
        purchasedBooks.push_back(ISBN);
    }

    void display() const {
        std::cout << "Customer ID: " << customerId << ", Name: " << name << "\nPurchased Books: ";
        for (const auto& isbn : purchasedBooks) {
            std::cout << isbn << " ";
        }
        std::cout << std::endl;
    }
};

class Bookstore {
private:
    std::vector<Book> books;
    std::vector<Customer> customers;
    static int nextCustomerId;

public:
    void addBook(const std::string& ISBN, const std::string& title, const std::string& author, double price, int stock) {
        books.emplace_back(ISBN, title, author, price, stock);
    }

    void registerCustomer(const std::string& name) {
        customers.emplace_back(nextCustomerId++, name);
    }

    void sellBook(const std::string& ISBN, int customerId) {
        auto bookIt = std::find_if(books.begin(), books.end(), [&](const Book& book) {
            return book.getISBN() == ISBN;
        });

        auto customerIt = std::find_if(customers.begin(), customers.end(), [&](const Customer& customer) {
            return customer.getCustomerId() == customerId;
        });

        if (bookIt != books.end() && customerIt != customers.end()) {
            if (bookIt->getStock() > 0) {
                bookIt->sell(1);
                customerIt->purchaseBook(ISBN);
                std::cout << "Book sold successfully.\n";
            } else {
                std::cout << "Book out of stock.\n";
            }
        } else {
            std::cout << "Book or customer not found.\n";
        }
    }

    void restockBook(const std::string& ISBN, int amount) {
        auto bookIt = std::find_if(books.begin(), books.end(), [&](const Book& book) {
            return book.getISBN() == ISBN;
        });

        if (bookIt != books.end()) {
            bookIt->restock(amount);
            std::cout << "Book restocked successfully.\n";
        } else {
            std::cout << "Book not found.\n";
        }
    }

    void displayInventory() const {
        std::cout << "Bookstore Inventory:\n";
        for (const auto& book : books) {
            book.display();
        }
    }

    void displayCustomerRecords() const {
        std::cout << "Customer Records:\n";
        for (const auto& customer : customers) {
            customer.display();
        }
    }
};

int Bookstore::nextCustomerId = 1;

int main() {
    Bookstore bookstore;

    bookstore.addBook("978-0143127550", "The Art of War", "Sun Tzu", 10.99, 5);
    bookstore.addBook("978-0385545969", "The Nickel Boys", "Colson Whitehead", 16.99, 3);

    bookstore.registerCustomer("Alice");
    bookstore.registerCustomer("Bob");

    std::cout << "\nBookstore Inventory:\n";
    bookstore.displayInventory();

    std::cout << "\nCustomer Records:\n";
    bookstore.displayCustomerRecords();

    std::cout << "\nAlice buys 'The Art of War'...\n";
    bookstore.sellBook("978-0143127550", 1);

    std::cout << "\nBookstore Inventory:\n";
    bookstore.displayInventory();

    std::cout << "\nAlice's Record:\n";
    bookstore.displayCustomerRecords();

    std::cout << "\nRestocking 'The Nickel Boys'...\n";
    bookstore.restockBook("978-0385545969", 2);

    std::cout << "\nBookstore Inventory:\n";
    bookstore.displayInventory();

    return 0;
}
