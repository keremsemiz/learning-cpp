#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Song {
private:
    int songId;
    std::string title;
    std::string artist;
    int duration; // in seconds
    std::string genre;

public:
    Song(int id, const std::string& t, const std::string& a, int d, const std::string& g)
        : songId(id), title(t), artist(a), duration(d), genre(g) {}

    int getSongId() const { return songId; }
    std::string getTitle() const { return title; }
    std::string getArtist() const { return artist; }
    int getDuration() const { return duration; }
    std::string getGenre() const { return genre; }

    void display() const {
        std::cout << "Song ID: " << songId << ", Title: " << title << ", Artist: " << artist
                  << ", Duration: " << duration << "s, Genre: " << genre << std::endl;
    }
};

class Playlist {
private:
    int playlistId;
    std::string name;
    std::vector<int> songIds;

public:
    Playlist(int id, const std::string& n) : playlistId(id), name(n) {}

    int getPlaylistId() const { return playlistId; }
    std::string getName() const { return name; }

    void addSong(int songId) {
        songIds.push_back(songId);
    }

    void removeSong(int songId) {
        songIds.erase(std::remove(songIds.begin(), songIds.end(), songId), songIds.end());
    }

    void display() const {
        std::cout << "Playlist ID: " << playlistId << ", Name: " << name << "\nSongs: ";
        for (int songId : songIds) {
            std::cout << songId << " ";
        }
        std::cout << std::endl;
    }
};

class MusicManager {
private:
    std::vector<Song> songs;
    std::vector<Playlist> playlists;
    static int nextSongId;
    static int nextPlaylistId;

public:
    void addSong(const std::string& title, const std::string& artist, int duration, const std::string& genre) {
        songs.emplace_back(nextSongId++, title, artist, duration, genre);
    }

    void createPlaylist(const std::string& name) {
        playlists.emplace_back(nextPlaylistId++, name);
    }

    void addSongToPlaylist(int songId, int playlistId) {
        auto playlistIt = std::find_if(playlists.begin(), playlists.end(), [&](const Playlist& playlist) {
            return playlist.getPlaylistId() == playlistId;
        });

        if (playlistIt != playlists.end()) {
            playlistIt->addSong(songId);
            std::cout << "Song added to playlist successfully.\n";
        } else {
            std::cout << "Playlist not found.\n";
        }
    }

    void removeSongFromPlaylist(int songId, int playlistId) {
        auto playlistIt = std::find_if(playlists.begin(), playlists.end(), [&](const Playlist& playlist) {
            return playlist.getPlaylistId() == playlistId;
        });

        if (playlistIt != playlists.end()) {
            playlistIt->removeSong(songId);
            std::cout << "Song removed from playlist successfully.\n";
        } else {
            std::cout << "Playlist not found.\n";
        }
    }

    void displayPlaylists() const {
        std::cout << "Playlists:\n";
        for (const auto& playlist : playlists) {
            playlist.display();
        }
    }

    void displaySongDetails() const {
        std::cout << "Songs:\n";
        for (const auto& song : songs) {
            song.display();
        }
    }
};

int MusicManager::nextSongId = 1;
int MusicManager::nextPlaylistId = 1;

int main() {
    MusicManager manager;

    manager.addSong("Bohemian Rhapsody", "Queen", 354, "Rock");
    manager.addSong("Shape of You", "Ed Sheeran", 263, "Pop");

    manager.createPlaylist("My Favourites");
    manager.createPlaylist("Rock Classics");

    std::cout << "\nPlaylists:\n";
    manager.displayPlaylists();

    std::cout << "\nAdding songs to playlists...\n";
    manager.addSongToPlaylist(1, 1);
    manager.addSongToPlaylist(2, 1);
    manager.addSongToPlaylist(1, 2);

    std::cout << "\nPlaylists after adding songs:\n";
    manager.displayPlaylists();

    std::cout << "\nRemoving a song from 'My Favourites'...\n";
    manager.removeSongFromPlaylist(2, 1);

    std::cout << "\nPlaylists after removing a song:\n";
    manager.displayPlaylists();

    std::cout << "\nSong Details:\n";
    manager.displaySongDetails();

    return 0;
}
