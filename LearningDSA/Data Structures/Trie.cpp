#include <iostream>
#include <unordered_map>

class TrieNode {
public:
    std::unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() : isEndOfWord(false) {}
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() : root(new TrieNode()) {}

    void insert(const std::string& word) {
        TrieNode* current = root;
        for (char ch : word) {
            if (!current->children[ch]) {
                current->children[ch] = new TrieNode();
            }
            current = current->children[ch];
        }
        current->isEndOfWord = true;
    }

    bool search(const std::string& word) {
        TrieNode* current = root;
        for (char ch : word) {
            if (!current->children[ch]) {
                return false;
            }
            current = current->children[ch];
        }
        return current->isEndOfWord;
    }

    bool startsWith(const std::string& prefix) {
        TrieNode* current = root;
        for (char ch : prefix) {
            if (!current->children[ch]) {
                return false;
            }
            current = current->children[ch];
        }
        return true;
    }
};

int main() {
    Trie trie;
    trie.insert("apple");
    trie.insert("app");
    trie.insert("ape");

    std::cout << "Search 'app': " << (trie.search("app") ? "Found" : "Not Found") << std::endl;
    std::cout << "Search 'apple': " << (trie.search("apple") ? "Found" : "Not Found") << std::endl;
    std::cout << "Search 'ap': " << (trie.search("ap") ? "Found" : "Not Found") << std::endl;
    std::cout << "Prefix 'app': " << (trie.startsWith("app") ? "Yes" : "No") << std::endl;
    std::cout << "Prefix 'ap': " << (trie.startsWith("ap") ? "Yes" : "No") << std::endl;

    return 0;
}
