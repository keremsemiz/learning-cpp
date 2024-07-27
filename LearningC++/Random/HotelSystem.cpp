#include <iostream>
#include <vector>
#include <string>

class Room {
private:
    int roomNumber;
    bool isAvailable;
    std::string guestName;

public:
    Room(int number) : roomNumber(number), isAvailable(true), guestName("") {}

    int getRoomNumber() const {
        return roomNumber;
    }

    bool getAvailability() const {
        return isAvailable;
    }

    std::string getGuestName() const {
        return guestName;
    }

    void checkIn(const std::string& guest) {
        if (isAvailable) {
            isAvailable = false;
            guestName = guest;
            std::cout << "Checked in " << guest << " to room " << roomNumber << std::endl;
        } else {
            std::cout << "Room " << roomNumber << " is not available.\n";
        }
    }

    void checkOut() {
        if (!isAvailable) {
            std::cout << "Checked out " << guestName << " from room " << roomNumber << std::endl;
            isAvailable = true;
            guestName = "";
        } else {
            std::cout << "Room " << roomNumber << " is already empty.\n";
        }
    }

    void displayStatus() const {
        std::cout << "Room " << roomNumber 
                  << " - " << (isAvailable ? "Available" : ("Occupied by " + guestName)) 
                  << std::endl;
    }
};

class Hotel {
private:
    std::vector<Room> rooms;

public:
    Hotel(int numberOfRooms) {
        for (int i = 1; i <= numberOfRooms; ++i) {
            rooms.emplace_back(i);
        }
    }

    void checkIn(int roomNumber, const std::string& guestName) {
        if (roomNumber > 0 && roomNumber <= rooms.size()) {
            rooms[roomNumber - 1].checkIn(guestName);
        } else {
            std::cout << "Invalid room number.\n";
        }
    }

    void checkOut(int roomNumber) {
        if (roomNumber > 0 && roomNumber <= rooms.size()) {
            rooms[roomNumber - 1].checkOut();
        } else {
            std::cout << "Invalid room number.\n";
        }
    }

    void displayStatus() const {
        for (const auto& room : rooms) {
            room.displayStatus();
        }
    }
};

int main() {
    Hotel hotel(5);
    hotel.displayStatus();

    std::cout << "\nChecking in guests...\n";
    hotel.checkIn(1, "John Doe");
    hotel.checkIn(2, "Jane Smith");

    std::cout << "\nCurrent status:\n";
    hotel.displayStatus();

    std::cout << "\nChecking out guest from room 1...\n";
    hotel.checkOut(1);

    std::cout << "\nCurrent status:\n";
    hotel.displayStatus();

    return 0;
}
