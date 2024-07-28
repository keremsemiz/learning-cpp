#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Post {
private:
    int postId;
    std::string author;
    std::string content;
    int likes;

public:
    Post(int id, const std::string& auth, const std::string& cont)
        : postId(id), author(auth), content(cont), likes(0) {}

    int getPostId() const { return postId; }
    std::string getAuthor() const { return author; }
    std::string getContent() const { return content; }
    int getLikes() const { return likes; }

    void like() { ++likes; }

    void display() const {
        std::cout << "Post ID: " << postId << "\nAuthor: " << author << "\nContent: " << content << "\nLikes: " << likes << std::endl;
    }
};

class User {
private:
    std::string username;
    std::vector<Post> posts;
    static int nextPostId;

public:
    User(const std::string& name) : username(name) {}

    std::string getUsername() const { return username; }

    void createPost(const std::string& content) {
        posts.emplace_back(nextPostId++, username, content);
    }

    void likePost(int postId) {
        auto it = std::find_if(posts.begin(), posts.end(), [&](const Post& post) {
            return post.getPostId() == postId;
        });

        if (it != posts.end()) {
            it->like();
            std::cout << "Post liked." << std::endl;
        } else {
            std::cout << "Post not found." << std::endl;
        }
    }

    void displayPosts() const {
        std::cout << "Posts by " << username << ":\n";
        for (const auto& post : posts) {
            post.display();
        }
    }
};

int User::nextPostId = 1;

class SocialMediaPlatform {
private:
    std::vector<User> users;

public:
    void registerUser(const std::string& username) {
        users.emplace_back(username);
    }

    void displayUsers() const {
        std::cout << "Registered Users:\n";
        for (const auto& user : users) {
            std::cout << "- " << user.getUsername() << std::endl;
        }
    }

    void displayAllPosts() const {
        for (const auto& user : users) {
            user.displayPosts();
        }
    }

    void searchPostsByContent(const std::string& keyword) const {
        std::cout << "Posts containing \"" << keyword << "\":\n";
        for (const auto& user : users) {
            for (const auto& post : user.getPosts()) {
                if (post.getContent().find(keyword) != std::string::npos) {
                    post.display();
                }
            }
        }
    }
};

int main() {
    SocialMediaPlatform platform;

    platform.registerUser("Alice");
    platform.registerUser("Bob");

    platform.getUser("Alice").createPost("Hello, world!");
    platform.getUser("Alice").createPost("Learning C++ is fun!");
    platform.getUser("Bob").createPost("This is my first post.");

    std::cout << "\nAll Posts:\n";
    platform.displayAllPosts();

    std::cout << "\nAlice likes her first post...\n";
    platform.getUser("Alice").likePost(1);

    std::cout << "\nAll Posts:\n";
    platform.displayAllPosts();

    std::cout << "\nSearching for posts containing 'C++':\n";
    platform.searchPostsByContent("C++");

    return 0;
}
