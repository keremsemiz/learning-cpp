// task - make a book class with private sub-classes

#include <iostream>
#include <string>

class Book {
private:
    std::string title;
    std::string author;
    double price;

public:
    void setTitle(const std::string& t) {
        title = t;
    }

    void setAuthor(const std::string& a) {
        author = a;
    }

    void setPrice(double p) {
        price = p;
    }

    std::string getTitle() const {
        return title;
    }

    std::string getAuthor() const {
        return author;
    }

    double getPrice() const {
        return price;
    }

    void display() const {
        std::cout << "Title: " << title << "\nAuthor: " << author << "\nPrice: $" << price << std::endl;
    }
};

int main() {
    Book myBook;
    myBook.setTitle("The Catcher in the Rye");
    myBook.setAuthor("J.D. Salinger");
    myBook.setPrice(10.99);
    myBook.display();
    return 0;
}
