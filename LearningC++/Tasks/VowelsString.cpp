// task - count amount of vowels in string

#include <iostream>
#include <string>

int countVowels(const std::string &str) {
    int count = 0;
    for (char c : str) {
        switch (tolower(c)) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                ++count;
                break;
        }
    }
    return count;
}

int main() {
    std::string str = "Hello World";
    std::cout << "Number of vowels: " << countVowels(str) << std::endl;
    return 0;
}
