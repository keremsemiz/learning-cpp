#include <iostream>
#include <vector>
#include <string>
#include <memory>

class File {
private:
    std::string name;
    std::string content;

public:
    File(const std::string& name, const std::string& content) 
        : name(name), content(content) {}

    std::string getName() const {
        return name;
    }

    std::string getContent() const {
        return content;
    }

    void display() const {
        std::cout << "File: " << name << "\nContent: " << content << std::endl;
    }
};

class Directory {
private:
    std::string name;
    std::vector<std::shared_ptr<File>> files;
    std::vector<std::shared_ptr<Directory>> subdirectories;

public:
    Directory(const std::string& name) : name(name) {}

    std::string getName() const {
        return name;
    }

    void addFile(const std::shared_ptr<File>& file) {
        files.push_back(file);
    }

    void addSubdirectory(const std::shared_ptr<Directory>& subdirectory) {
        subdirectories.push_back(subdirectory);
    }

    void listContents() const {
        std::cout << "Directory: " << name << "\nFiles:\n";
        for (const auto& file : files) {
            std::cout << "  " << file->getName() << std::endl;
        }
        std::cout << "Subdirectories:\n";
        for (const auto& subdir : subdirectories) {
            std::cout << "  " << subdir->getName() << std::endl;
        }
    }

    std::shared_ptr<File> findFile(const std::string& fileName) const {
        for (const auto& file : files) {
            if (file->getName() == fileName) {
                return file;
            }
        }
        return nullptr;
    }
};

int main() {
    auto root = std::make_shared<Directory>("root");
    auto home = std::make_shared<Directory>("home");
    auto user = std::make_shared<Directory>("user");
    auto file1 = std::make_shared<File>("file1.txt", "This is file 1.");
    auto file2 = std::make_shared<File>("file2.txt", "This is file 2.");

    root->addSubdirectory(home);
    home->addSubdirectory(user);
    user->addFile(file1);
    user->addFile(file2);

    std::cout << "Contents of root directory:\n";
    root->listContents();
    std::cout << "\nContents of home directory:\n";
    home->listContents();
    std::cout << "\nContents of user directory:\n";
    user->listContents();

    std::cout << "\nSearching for file1.txt in user directory:\n";
    auto foundFile = user->findFile("file1.txt");
    if (foundFile) {
        foundFile->display();
    } else {
        std::cout << "File not found.\n";
    }

    return 0;
}
