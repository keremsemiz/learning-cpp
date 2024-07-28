#include <iostream>
#include <string>

std::string caesarCipher(const std::string& text, int shift) {
    std::string result;
    for (char c : text) {
        if (std::isalpha(c)) {
            char base = std::islower(c) ? 'a' : 'A';
            result += (c - base + shift) % 26 + base;
        } else {
            result += c;
        }
    }
    return result;
}

std::string caesarDecipher(const std::string& text, int shift) {
    return caesarCipher(text, 26 - shift);
}

int main() {
    std::string message = "Hello, World!";
    int shift = 3;

    std::string encrypted = caesarCipher(message, shift);
    std::string decrypted = caesarDecipher(encrypted, shift);

    std::cout << "Original Message: " << message << std::endl;
    std::cout << "Encrypted Message: " << encrypted << std::endl;
    std::cout << "Decrypted Message: " << decrypted << std::endl;

    return 0;
}
