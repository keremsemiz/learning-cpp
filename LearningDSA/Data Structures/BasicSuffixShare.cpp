#include <iostream>
#include <unordered_map>

class SuffixTreeNode {
public:
    std::unordered_map<char, SuffixTreeNode*> children;

    void insertSuffix(const std::string& suffix) {
        if (suffix.empty()) return;

        char firstChar = suffix[0];
        if (children.find(firstChar) == children.end()) {
            children[firstChar] = new SuffixTreeNode();
        }

        children[firstChar]->insertSuffix(suffix.substr(1));
    }

    bool search(const std::string& pattern) {
        if (pattern.empty()) return true;

        char firstChar = pattern[0];
        if (children.find(firstChar) == children.end()) {
            return false;
        }

        return children[firstChar]->search(pattern.substr(1));
    }
};

class SuffixTree {
private:
    SuffixTreeNode* root;

public:
    SuffixTree(const std::string& text) {
        root = new SuffixTreeNode();
        for (int i = 0; i < text.length(); ++i) {
            root->insertSuffix(text.substr(i));
        }
    }

    bool search(const std::string& pattern) {
        return root->search(pattern);
    }
};

int main() {
    std::string text = "banana";
    SuffixTree tree(text);

    std::cout << "Searching 'nan': " << (tree.search("nan") ? "Found" : "Not Found") << std::endl;
    std::cout << "Searching 'ana': " << (tree.search("ana") ? "Found" : "Not Found") << std::endl;
    std::cout << "Searching 'nana': " << (tree.search("nana") ? "Found" : "Not Found") << std::endl;
    std::cout << "Searching 'ban': " << (tree.search("ban") ? "Found" : "Not Found") << std::endl;
    std::cout << "Searching 'nab': " << (tree.search("nab") ? "Found" : "Not Found") << std::endl;

    return 0;
}
