#include <iostream>
#include <vector>
#include <string>

class Player {
private:
    std::string name;
    int score;

public:
    Player(const std::string& n, int s) : name(n), score(s) {}

    void setName(const std::string& n) {
        name = n;
    }

    void setScore(int s) {
        score = s;
    }

    std::string getName() const {
        return name;
    }

    int getScore() const {
        return score;
    }

    void updateScore(int points) {
        score += points;
    }

    void display() const {
        std::cout << "Name: " << name << ", Score: " << score << std::endl;
    }
};

class ScoreTracker {
private:
    std::vector<Player> players;

public:
    void addPlayer(const std::string& name, int score) {
        players.emplace_back(name, score);
    }

    void updatePlayerScore(const std::string& name, int points) {
        for (auto& player : players) {
            if (player.getName() == name) {
                player.updateScore(points);
                return;
            }
        }
        std::cout << "Player not found.\n";
    }

    void displayPlayers() const {
        for (const auto& player : players) {
            player.display();
        }
    }
};

int main() {
    ScoreTracker tracker;
    tracker.addPlayer("Alice", 100);
    tracker.addPlayer("Bob", 200);

    std::cout << "All Players:\n";
    tracker.displayPlayers();

    std::cout << "\nUpdating Alice's score...\n";
    tracker.updatePlayerScore("Alice", 50);
    tracker.displayPlayers();

    return 0;
}
