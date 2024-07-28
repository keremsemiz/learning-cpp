#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Speaker {
private:
    std::string name;
    std::string topic;
    int duration;

public:
    Speaker(const std::string& n, const std::string& t, int d)
        : name(n), topic(t), duration(d) {}

    std::string getName() const { return name; }
    std::string getTopic() const { return topic; }
    int getDuration() const { return duration; }

    void display() const {
        std::cout << "Speaker: " << name << ", Topic: " << topic << ", Duration: " << duration << " minutes" << std::endl;
    }
};

class Session {
private:
    int sessionId;
    std::string sessionName;
    std::vector<Speaker> speakers;

public:
    Session(int id, const std::string& name) : sessionId(id), sessionName(name) {}

    int getSessionId() const { return sessionId; }
    std::string getSessionName() const { return sessionName; }

    void addSpeaker(const Speaker& speaker) {
        speakers.push_back(speaker);
    }

    void removeSpeaker(const std::string& speakerName) {
        speakers.erase(std::remove_if(speakers.begin(), speakers.end(), [&](const Speaker& speaker) {
            return speaker.getName() == speakerName;
        }), speakers.end());
    }

    void display() const {
        std::cout << "Session ID: " << sessionId << "\nSession Name: " << sessionName << "\nSpeakers:\n";
        for (const auto& speaker : speakers) {
            speaker.display();
        }
    }
};

class Conference {
private:
    std::vector<Session> sessions;
    static int nextSessionId;

public:
    void addSession(const std::string& sessionName) {
        sessions.emplace_back(nextSessionId++, sessionName);
    }

    void addSpeakerToSession(int sessionId, const Speaker& speaker) {
        auto it = std::find_if(sessions.begin(), sessions.end(), [&](const Session& session) {
            return session.getSessionId() == sessionId;
        });

        if (it != sessions.end()) {
            it->addSpeaker(speaker);
        } else {
            std::cout << "Session not found." << std::endl;
        }
    }

    void removeSpeakerFromSession(int sessionId, const std::string& speakerName) {
        auto it = std::find_if(sessions.begin(), sessions.end(), [&](const Session& session) {
            return session.getSessionId() == sessionId;
        });

        if (it != sessions.end()) {
            it->removeSpeaker(speakerName);
        } else {
            std::cout << "Session not found." << std::endl;
        }
    }

    void displaySchedule() const {
        for (const auto& session : sessions) {
            session.display();
        }
    }
};

int Conference::nextSessionId = 1;

int main() {
    Conference conference;

    conference.addSession("Opening Ceremony");
    conference.addSession("Technical Talks");
    conference.addSession("Closing Ceremony");

    conference.addSpeakerToSession(1, Speaker("Alice", "Welcome Speech", 15));
    conference.addSpeakerToSession(2, Speaker("Bob", "Deep Learning", 45));
    conference.addSpeakerToSession(2, Speaker("Charlie", "Blockchain", 30));
    conference.addSpeakerToSession(3, Speaker("David", "Farewell Address", 20));

    std::cout << "Conference Schedule:\n";
    conference.displaySchedule();

    std::cout << "\nRemoving Bob from 'Technical Talks'...\n";
    conference.removeSpeakerFromSession(2, "Bob");

    std::cout << "\nUpdated Conference Schedule:\n";
    conference.displaySchedule();

    return 0;
}
