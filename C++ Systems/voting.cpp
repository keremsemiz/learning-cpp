#include <iostream>
#include <vector>
#include <string>
#include <map>

class Candidate {
private:
    int candidateId;
    std::string name;
    std::string party;

public:
    Candidate(int id, const std::string& n, const std::string& p) : candidateId(id), name(n), party(p) {}

    int getCandidateId() const { return candidateId; }
    std::string getName() const { return name; }
    std::string getParty() const { return party; }

    void display() const {
        std::cout << "Candidate ID: " << candidateId << ", Name: " << name << ", Party: " << party << std::endl;
    }
};

class Voter {
private:
    int voterId;
    std::string name;
    bool hasVoted;

public:
    Voter(int id, const std::string& n) : voterId(id), name(n), hasVoted(false) {}

    int getVoterId() const { return voterId; }
    std::string getName() const { return name; }
    bool getHasVoted() const { return hasVoted; }

    void vote() { hasVoted = true; }

    void display() const {
        std::cout << "Voter ID: " << voterId << ", Name: " << name << ", Has Voted: " << (hasVoted ? "Yes" : "No") << std::endl;
    }
};

class Election {
private:
    std::vector<Candidate> candidates;
    std::vector<Voter> voters;
    std::map<int, int> votes; // number of votes
    static int nextCandidateId;
    static int nextVoterId;

public:
    void registerVoter(const std::string& name) {
        voters.emplace_back(nextVoterId++, name);
    }

    void addCandidate(const std::string& name, const std::string& party) {
        candidates.emplace_back(nextCandidateId++, name, party);
    }

    void castVote(int voterId, int candidateId) {
        auto voterIt = std::find_if(voters.begin(), voters.end(), [&](const Voter& voter) {
            return voter.getVoterId() == voterId;
        });

        auto candidateIt = std::find_if(candidates.begin(), candidates.end(), [&](const Candidate& candidate) {
            return candidate.getCandidateId() == candidateId;
        });

        if (voterIt != voters.end() && candidateIt != candidates.end()) {
            if (!voterIt->getHasVoted()) {
                voterIt->vote();
                votes[candidateId]++;
                std::cout << "Voter " << voterId << " voted for candidate " << candidateId << std::endl;
            } else {
                std::cout << "Voter has already voted.\n";
            }
        } else {
            std::cout << "Voter or candidate not found.\n";
        }
    }

    void displayCandidates() const {
        for (const auto& candidate : candidates) {
            candidate.display();
        }
    }

    void displayVoters() const {
        for (const auto& voter : voters) {
            voter.display();
        }
    }

    void displayResults() const {
        std::cout << "Election Results:\n";
        for (const auto& [candidateId, voteCount] : votes) {
            auto candidateIt = std::find_if(candidates.begin(), candidates.end(), [&](const Candidate& candidate) {
                return candidate.getCandidateId() == candidateId;
            });

            if (candidateIt != candidates.end()) {
                std::cout << "Candidate: " << candidateIt->getName() << ", Votes: " << voteCount << std::endl;
            }
        }
    }
};

int Election::nextCandidateId = 1;
int Election::nextVoterId = 1;

int main() {
    Election election;

    election.registerVoter("Alice");
    election.registerVoter("Bob");

    election.addCandidate("John Doe", "Party A");
    election.addCandidate("Jane Smith", "Party B");

    std::cout << "\nCandidates:\n";
    election.displayCandidates();

    std::cout << "\nVoters:\n";
    election.displayVoters();

    std::cout << "\nVoting...\n";
    election.castVote(1, 1);
    election.castVote(2, 2);

    std::cout << "\nElection Results:\n";
    election.displayResults();

    return 0;
}
