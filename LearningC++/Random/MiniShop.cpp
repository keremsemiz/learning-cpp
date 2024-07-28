#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Product {
private:
    std::string name;
    double price;
    int stockQuantity;

public:
    Product(const std::string& n, double p, int s) : name(n), price(p), stockQuantity(s) {}

    std::string getName() const { return name; }
    double getPrice() const { return price; }
    int getStockQuantity() const { return stockQuantity; }

    void setStockQuantity(int quantity) { stockQuantity = quantity; }

    void display() const {
        std::cout << "Product: " << name << ", Price: $" << price << ", Stock: " << stockQuantity << std::endl;
    }
};

class CartItem {
private:
    Product product;
    int quantity;

public:
    CartItem(const Product& p, int q) : product(p), quantity(q) {}

    Product getProduct() const { return product; }
    int getQuantity() const { return quantity; }

    double getTotalPrice() const {
        return product.getPrice() * quantity;
    }

    void display() const {
        product.display();
        std::cout << "Quantity: " << quantity << ", Total: $" << getTotalPrice() << std::endl;
    }
};

class ShoppingCart {
private:
    std::vector<CartItem> items;

public:
    void addItem(const Product& product, int quantity) {
        items.emplace_back(product, quantity);
    }

    void removeItem(const std::string& productName) {
        items.erase(std::remove_if(items.begin(), items.end(), [&](const CartItem& item) {
            return item.getProduct().getName() == productName;
        }), items.end());
    }

    void listItems() const {
        for (const auto& item : items) {
            item.display();
        }
    }

    double calculateTotal() const {
        double total = 0.0;
        for (const auto& item : items) {
            total += item.getTotalPrice();
        }
        return total;
    }
};

class ECommerceSystem {
private:
    std::vector<Product> products;
    ShoppingCart cart;

public:
    void addProduct(const std::string& name, double price, int stockQuantity) {
        products.emplace_back(name, price, stockQuantity);
    }

    void browseProducts() const {
        for (const auto& product : products) {
            product.display();
        }
    }

    void addToCart(const std::string& productName, int quantity) {
        auto it = std::find_if(products.begin(), products.end(), [&](const Product& product) {
            return product.getName() == productName;
        });

        if (it != products.end() && it->getStockQuantity() >= quantity) {
            cart.addItem(*it, quantity);
            it->setStockQuantity(it->getStockQuantity() - quantity);
            std::cout << "Added " << quantity << " of " << productName << " to the cart." << std::endl;
        } else {
            std::cout << "Product not found or insufficient stock." << std::endl;
        }
    }

    void viewCart() const {
        cart.listItems();
        std::cout << "Total Cost: $" << cart.calculateTotal() << std::endl;
    }

    void checkout() {
        std::cout << "Checking out. Total cost: $" << cart.calculateTotal() << std::endl;
        cart = ShoppingCart(); // empty cart bruh
    }
};

int main() {
    ECommerceSystem system;

    system.addProduct("Laptop", 999.99, 10);
    system.addProduct("Smartphone", 699.99, 20);
    system.addProduct("Tablet", 299.99, 15);

    std::cout << "Available Products:\n";
    system.browseProducts();

    std::cout << "\nAdding items to the cart...\n";
    system.addToCart("Laptop", 1);
    system.addToCart("Smartphone", 2);

    std::cout << "\nViewing Cart:\n";
    system.viewCart();

    std::cout << "\nChecking out...\n";
    system.checkout();

    std::cout << "\nAvailable Products after checkout:\n";
    system.browseProducts();

    return 0;
}
