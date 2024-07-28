#include <iostream>
#include <vector>
#include <string>
#include <sstream>

class File {
private:
    std::string fileName;
    std::string content;

public:
    File(const std::string& name, const std::string& content) : fileName(name), content(content) {}

    std::string getFileName() const { return fileName; }
    std::string getContent() const { return content; }
    void setContent(const std::string& newContent) { content = newContent; }

    void display() const {
        std::cout << "File: " << fileName << "\nContent: " << content << std::endl;
    }
};

class Compressor {
public:
    static std::string compress(const std::string& data) {
        std::stringstream compressed;
        int count = 1;

        for (size_t i = 1; i <= data.length(); ++i) {
            if (i == data.length() || data[i] != data[i - 1]) {
                compressed << data[i - 1] << count;
                count = 1;
            } else {
                ++count;
            }
        }

        return compressed.str();
    }

    static std::string decompress(const std::string& data) {
        std::stringstream decompressed;
        for (size_t i = 0; i < data.length(); ++i) {
            char character = data[i];
            ++i;
            int count = data[i] - '0';

            while (count--) {
                decompressed << character;
            }
        }

        return decompressed.str();
    }
};

class FileManager {
private:
    std::vector<File> files;

public:
    void addFile(const std::string& fileName, const std::string& content) {
        files.emplace_back(fileName, content);
    }

    void removeFile(const std::string& fileName) {
        files.erase(std::remove_if(files.begin(), files.end(), [&](const File& file) {
            return file.getFileName() == fileName;
        }), files.end());
    }

    void compressFile(const std::string& fileName) {
        auto it = std::find_if(files.begin(), files.end(), [&](const File& file) {
            return file.getFileName() == fileName;
        });

        if (it != files.end()) {
            it->setContent(Compressor::compress(it->getContent()));
            std::cout << "Compressed content of file: " << fileName << std::endl;
        } else {
            std::cout << "File not found." << std::endl;
        }
    }

    void decompressFile(const std::string& fileName) {
        auto it = std::find_if(files.begin(), files.end(), [&](const File& file) {
            return file.getFileName() == fileName;
        });

        if (it != files.end()) {
            it->setContent(Compressor::decompress(it->getContent()));
            std::cout << "Decompressed content of file: " << fileName << std::endl;
        } else {
            std::cout << "File not found." << std::endl;
        }
    }

    void displayFileContent(const std::string& fileName) const {
        auto it = std::find_if(files.begin(), files.end(), [&](const File& file) {
            return file.getFileName() == fileName;
        });

        if (it != files.end()) {
            it->display();
        } else {
            std::cout << "File not found." << std::endl;
        }
    }
};

int main() {
    FileManager manager;

    manager.addFile("example.txt", "aaaaabbbbcccd");
    manager.addFile("data.txt", "xxxyyyzzz");

    std::cout << "Original Content of example.txt:\n";
    manager.displayFileContent("example.txt");

    std::cout << "\nCompressing example.txt...\n";
    manager.compressFile("example.txt");
    manager.displayFileContent("example.txt");

    std::cout << "\nDecompressing example.txt...\n";
    manager.decompressFile("example.txt");
    manager.displayFileContent("example.txt");

    return 0;
}
