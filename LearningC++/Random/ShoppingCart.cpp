#include <iostream>
#include <vector>
#include <string>

class Item {
private:
    std::string name;
    double price;
    int quantity;

public:
    Item(const std::string& name, double price, int quantity)
        : name(name), price(price), quantity(quantity) {}

    std::string getName() const {
        return name;
    }

    double getPrice() const {
        return price;
    }

    int getQuantity() const {
        return quantity;
    }

    double getTotalPrice() const {
        return price * quantity;
    }

    void display() const {
        std::cout << "Item: " << name << ", Price: $" << price << ", Quantity: " << quantity << std::endl;
    }
};

class ShoppingCart {
private:
    std::vector<Item> items;

public:
    void addItem(const std::string& name, double price, int quantity) {
        items.emplace_back(name, price, quantity);
    }

    void removeItem(const std::string& name) {
        items.erase(
            std::remove_if(items.begin(), items.end(), [&](const Item& item) {
                return item.getName() == name;
            }), items.end());
    }

    double calculateTotal() const {
        double total = 0.0;
        for (const auto& item : items) {
            total += item.getTotalPrice();
        }
        return total;
    }

    void displayCart() const {
        std::cout << "Shopping Cart:\n";
        for (const auto& item : items) {
            item.display();
        }
        std::cout << "Total Cost: $" << calculateTotal() << std::endl;
    }
};

int main() {
    ShoppingCart cart;
    cart.addItem("Apple", 0.99, 5);
    cart.addItem("Bread", 2.49, 2);
    cart.addItem("Milk", 3.99, 1);

    cart.displayCart();

    std::cout << "\nRemoving Bread from the cart...\n";
    cart.removeItem("Bread");
    cart.displayCart();

    return 0;
}
