#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Item {
private:
    int itemId;
    std::string itemName;
    int quantity;
    double pricePerUnit;

public:
    Item(int id, const std::string& name, int qty, double price)
        : itemId(id), itemName(name), quantity(qty), pricePerUnit(price) {}

    int getItemId() const { return itemId; }
    std::string getItemName() const { return itemName; }
    int getQuantity() const { return quantity; }
    double getPricePerUnit() const { return pricePerUnit; }

    void updateQuantity(int qty) { quantity = qty; }

    void display() const {
        std::cout << "Item ID: " << itemId
                  << ", Name: " << itemName
                  << ", Quantity: " << quantity
                  << ", Price per Unit: $" << pricePerUnit << std::endl;
    }
};

class Warehouse {
private:
    std::string warehouseName;
    std::vector<Item> items;
    static int nextItemId;

public:
    Warehouse(const std::string& name) : warehouseName(name) {}

    std::string getWarehouseName() const { return warehouseName; }

    void addItem(const std::string& name, int quantity, double price) {
        items.emplace_back(nextItemId++, name, quantity, price);
    }

    void removeItem(int itemId) {
        items.erase(std::remove_if(items.begin(), items.end(), [&](const Item& item) {
            return item.getItemId() == itemId;
        }), items.end());
    }

    void updateItemQuantity(int itemId, int quantity) {
        auto it = std::find_if(items.begin(), items.end(), [&](const Item& item) {
            return item.getItemId() == itemId;
        });

        if (it != items.end()) {
            it->updateQuantity(quantity);
        } else {
            std::cout << "Item not found.\n";
        }
    }

    void displayInventory() const {
        std::cout << "Warehouse: " << warehouseName << "\nItems:\n";
        for (const auto& item : items) {
            item.display();
        }
    }
};

int Warehouse::nextItemId = 1;

class WarehouseManager {
private:
    std::vector<Warehouse> warehouses;

public:
    void addWarehouse(const std::string& name) {
        warehouses.emplace_back(name);
    }

    void transferItem(int itemId, const std::string& fromWarehouse, const std::string& toWarehouse, int quantity) {
        Warehouse* source = nullptr;
        Warehouse* destination = nullptr;

        for (auto& warehouse : warehouses) {
            if (warehouse.getWarehouseName() == fromWarehouse) {
                source = &warehouse;
            }
            if (warehouse.getWarehouseName() == toWarehouse) {
                destination = &warehouse;
            }
        }

        if (source && destination) {
            auto it = std::find_if(source->items.begin(), source->items.end(), [&](const Item& item) {
                return item.getItemId() == itemId;
            });

            if (it != source->items.end() && it->getQuantity() >= quantity) {
                it->updateQuantity(it->getQuantity() - quantity);
                destination->addItem(it->getItemName(), quantity, it->getPricePerUnit());
                std::cout << "Transferred " << quantity << " of item ID " << itemId << " from " << fromWarehouse << " to " << toWarehouse << std::endl;
            } else {
                std::cout << "Insufficient quantity or item not found.\n";
            }
        } else {
            std::cout << "One or both warehouses not found.\n";
        }
    }

    void displayAllInventories() const {
        for (const auto& warehouse : warehouses) {
            warehouse.displayInventory();
        }
    }

    void searchItemInAllWarehouses(const std::string& itemName) const {
        std::cout << "Searching for item: " << itemName << "\n";
        for (const auto& warehouse : warehouses) {
            for (const auto& item : warehouse.items) {
                if (item.getItemName() == itemName) {
                    std::cout << "Found in " << warehouse.getWarehouseName() << ": ";
                    item.display();
                }
            }
        }
    }
};

int main() {
    WarehouseManager manager;

    manager.addWarehouse("Central Warehouse");
    manager.addWarehouse("East Warehouse");

    manager.warehouses[0].addItem("Laptop", 50, 1000.0);
    manager.warehouses[0].addItem("Phone", 100, 500.0);
    manager.warehouses[1].addItem("Tablet", 30, 300.0);

    std::cout << "All Inventories:\n";
    manager.displayAllInventories();

    std::cout << "\nTransferring 10 Laptops from Central to East Warehouse...\n";
    manager.transferItem(1, "Central Warehouse", "East Warehouse", 10);

    std::cout << "\nAll Inventories After Transfer:\n";
    manager.displayAllInventories();

    std::cout << "\nSearching for 'Phone':\n";
    manager.searchItemInAllWarehouses("Phone");

    return 0;
}
