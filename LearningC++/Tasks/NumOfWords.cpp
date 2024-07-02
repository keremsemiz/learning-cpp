// task - count the number of words in a string

#include <iostream>
#include <string>
#include <sstream>

int countWords(const std::string &str) {
    std::istringstream iss(str);
    std::string word;
    int count = 0;
    while (iss >> word) {
        ++count;
    }
    return count;
}

int main() {
    std::string str = "Hello world, this is a simple C++ program.";
    std::cout << "Number of words: " << countWords(str) << std::endl;
    return 0;
}
