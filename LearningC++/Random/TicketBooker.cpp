#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Ticket {
private:
    int ticketNumber;
    std::string event;
    double price;
    bool isSold;

public:
    Ticket(int number, const std::string& eventName, double ticketPrice)
        : ticketNumber(number), event(eventName), price(ticketPrice), isSold(false) {}

    int getTicketNumber() const { return ticketNumber; }
    std::string getEvent() const { return event; }
    double getPrice() const { return price; }
    bool getIsSold() const { return isSold; }

    void bookTicket() {
        if (!isSold) {
            isSold = true;
            std::cout << "Ticket " << ticketNumber << " for " << event << " has been booked." << std::endl;
        } else {
            std::cout << "Ticket is already sold." << std::endl;
        }
    }

    void cancelTicket() {
        if (isSold) {
            isSold = false;
            std::cout << "Ticket " << ticketNumber << " for " << event << " has been canceled." << std::endl;
        } else {
            std::cout << "Ticket is not sold yet." << std::endl;
        }
    }

    void display() const {
        std::cout << "Ticket Number: " << ticketNumber
                  << "\nEvent: " << event
                  << "\nPrice: $" << price
                  << "\nStatus: " << (isSold ? "Sold" : "Available") << std::endl;
    }
};

class TicketSystem {
private:
    std::vector<Ticket> tickets;

public:
    void addTicket(int number, const std::string& event, double price) {
        tickets.emplace_back(number, event, price);
    }

    void bookTicket(int number) {
        auto it = std::find_if(tickets.begin(), tickets.end(), [number](const Ticket& ticket) {
            return ticket.getTicketNumber() == number;
        });
        if (it != tickets.end()) {
            it->bookTicket();
        } else {
            std::cout << "Ticket not found." << std::endl;
        }
    }

    void cancelTicket(int number) {
        auto it = std::find_if(tickets.begin(), tickets.end(), [number](const Ticket& ticket) {
            return ticket.getTicketNumber() == number;
        });
        if (it != tickets.end()) {
            it->cancelTicket();
        } else {
            std::cout << "Ticket not found." << std::endl;
        }
    }

    void displayTickets() const {
        for (const auto& ticket : tickets) {
            ticket.display();
        }
    }
};

int main() {
    TicketSystem system;
    system.addTicket(1, "Concert", 50.0);
    system.addTicket(2, "Movie", 15.0);
    system.addTicket(3, "Play", 25.0);

    std::cout << "All Tickets:\n";
    system.displayTickets();

    std::cout << "\nBooking Ticket 1...\n";
    system.bookTicket(1);
    system.displayTickets();

    std::cout << "\nCanceling Ticket 1...\n";
    system.cancelTicket(1);
    system.displayTickets();

    return 0;
}
