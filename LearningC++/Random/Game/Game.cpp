#include <iostream>
#include <vector>
#include <string>
#include <map>

class Room {
private:
    std::string description;
    std::vector<std::string> items;

public:
    Room(const std::string& desc) : description(desc) {}

    void addItem(const std::string& item) {
        items.push_back(item);
    }

    void removeItem(const std::string& item) {
        items.erase(std::remove(items.begin(), items.end(), item), items.end());
    }

    std::string getDescription() const {
        return description;
    }

    std::vector<std::string> getItems() const {
        return items;
    }

    void display() const {
        std::cout << description << "\nItems: ";
        for (const auto& item : items) {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }
};

class AdventureGame {
private:
    std::map<std::string, Room> rooms;
    std::string currentRoom;
    std::vector<std::string> inventory;

public:
    AdventureGame() {
        rooms["Forest"] = Room("You are in a dark forest. There is a path to the north.");
        rooms["Cave"] = Room("You are in a damp cave. The entrance is to the south.");
        rooms["Castle"] = Room("You are in a grand castle. There are exits to the east and west.");

        rooms["Forest"].addItem("Stick");
        rooms["Cave"].addItem("Torch");
        rooms["Castle"].addItem("Sword");

        currentRoom = "Forest";
    }

    void move(const std::string& direction) {
        if (currentRoom == "Forest" && direction == "north") {
            currentRoom = "Cave";
        } else if (currentRoom == "Cave" && direction == "south") {
            currentRoom = "Forest";
        } else if (currentRoom == "Castle" && (direction == "east" || direction == "west")) {
            currentRoom = "Forest";
        } else {
            std::cout << "You can't go that way." << std::endl;
        }
        rooms[currentRoom].display();
    }

    void pickUpItem(const std::string& item) {
        if (std::find(rooms[currentRoom].getItems().begin(), rooms[currentRoom].getItems().end(), item) != rooms[currentRoom].getItems().end()) {
            inventory.push_back(item);
            rooms[currentRoom].removeItem(item);
            std::cout << "Picked up " << item << "." << std::endl;
        } else {
            std::cout << "No such item here." << std::endl;
        }
    }

    void displayInventory() const {
        std::cout << "Inventory: ";
        for (const auto& item : inventory) {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }

    void play() {
        std::cout << "Welcome to the Adventure Game!" << std::endl;
        rooms[currentRoom].display();
        
        std::string command;
        while (true) {
            std::cout << "\n> ";
            std::cin >> command;
            if (command == "move") {
                std::string direction;
                std::cin >> direction;
                move(direction);
            } else if (command == "pickup") {
                std::string item;
                std::cin >> item;
                pickUpItem(item);
            } else if (command == "inventory") {
                displayInventory();
            } else if (command == "quit") {
                break;
            } else {
                std::cout << "Unknown command." << std::endl;
            }
        }
    }
};

int main() {
    AdventureGame game;
    game.play();
    return 0;
}
