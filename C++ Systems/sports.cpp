#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Team {
private:
    int teamId;
    std::string teamName;
    std::vector<std::string> players;
    int points;

public:
    Team(int id, const std::string& name) : teamId(id), teamName(name), points(0) {}

    int getTeamId() const { return teamId; }
    std::string getTeamName() const { return teamName; }
    int getPoints() const { return points; }

    void addPlayer(const std::string& player) {
        players.push_back(player);
    }

    void addPoints(int p) {
        points += p;
    }

    void display() const {
        std::cout << "Team ID: " << teamId << ", Name: " << teamName << ", Points: " << points << "\nPlayers: ";
        for (const auto& player : players) {
            std::cout << player << " ";
        }
        std::cout << std::endl;
    }
};

class Match {
private:
    int matchId;
    int team1Id;
    int team2Id;
    int scoreTeam1;
    int scoreTeam2;
    int winner;

public:
    Match(int id, int t1, int t2) : matchId(id), team1Id(t1), team2Id(t2), scoreTeam1(0), scoreTeam2(0), winner(0) {}

    int getMatchId() const { return matchId; }
    int getTeam1Id() const { return team1Id; }
    int getTeam2Id() const { return team2Id; }
    int getScoreTeam1() const { return scoreTeam1; }
    int getScoreTeam2() const { return scoreTeam2; }
    int getWinner() const { return winner; }

    void recordResult(int score1, int score2) {
        scoreTeam1 = score1;
        scoreTeam2 = score2;
        if (score1 > score2) {
            winner = 1;
        } else if (score1 < score2) {
            winner = 2;
        } else {
            winner = 0;
        }
    }

    void display() const {
        std::cout << "Match ID: " << matchId << ", Team 1 ID: " << team1Id << ", Team 2 ID: " << team2Id
                  << ", Score: " << scoreTeam1 << "-" << scoreTeam2
                  << ", Winner: " << (winner == 0 ? "Draw" : (winner == 1 ? "Team 1" : "Team 2")) << std::endl;
    }
};

class Tournament {
private:
    std::vector<Team> teams;
    std::vector<Match> matches;
    static int nextTeamId;
    static int nextMatchId;

public:
    void addTeam(const std::string& name) {
        teams.emplace_back(nextTeamId++, name);
    }

    void scheduleMatch(int team1Id, int team2Id) {
        matches.emplace_back(nextMatchId++, team1Id, team2Id);
    }

    void recordMatchResult(int matchId, int scoreTeam1, int scoreTeam2) {
        auto matchIt = std::find_if(matches.begin(), matches.end(), [&](const Match& match) {
            return match.getMatchId() == matchId;
        });

        if (matchIt != matches.end()) {
            matchIt->recordResult(scoreTeam1, scoreTeam2);
            if (matchIt->getWinner() == 1) {
                getTeam(matchIt->getTeam1Id())->addPoints(3);
            } else if (matchIt->getWinner() == 2) {
                getTeam(matchIt->getTeam2Id())->addPoints(3);
            } else {
                getTeam(matchIt->getTeam1Id())->addPoints(1);
                getTeam(matchIt->getTeam2Id())->addPoints(1);
            }
        } else {
            std::cout << "Match not found.\n";
        }
    }

    void displayStandings() const {
        std::cout << "Team Standings:\n";
        for (const auto& team : teams) {
            team.display();
        }
    }

    void displayMatchResults() const {
        std::cout << "Match Results:\n";
        for (const auto& match : matches) {
            match.display();
        }
    }

private:
    Team* getTeam(int teamId) {
        auto teamIt = std::find_if(teams.begin(), teams.end(), [&](const Team& team) {
            return team.getTeamId() == teamId;
        });
        return (teamIt != teams.end()) ? &(*teamIt) : nullptr;
    }
};

int Tournament::nextTeamId = 1;
int Tournament::nextMatchId = 1;

int main() {
    Tournament tournament;

    tournament.addTeam("Dragons");
    tournament.addTeam("Tigers");
    tournament.addTeam("Wolves");

    tournament.scheduleMatch(1, 2);
    tournament.scheduleMatch(1, 3);
    tournament.scheduleMatch(2, 3);

    std::cout << "\nRecording Results:\n";
    tournament.recordMatchResult(1, 3, 1);
    tournament.recordMatchResult(2, 2, 2);
    tournament.recordMatchResult(3, 0, 1);

    std::cout << "\nTeam Standings:\n";
    tournament.displayStandings();

    std::cout << "\nMatch Results:\n";
    tournament.displayMatchResults();

    return 0;
}
