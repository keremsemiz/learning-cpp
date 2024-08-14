#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

class Node {
public:
    char data;
    int freq;
    Node* left;
    Node* right;

    Node(char data, int freq) : data(data), freq(freq), left(nullptr), right(nullptr) {}
};

struct compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

class HuffmanCoding {
private:
    Node* root;
    std::unordered_map<char, std::string> huffmanCodes;

    void buildHuffmanTree(const std::string& text) {
        std::unordered_map<char, int> freq;
        for (char ch : text) {
            freq[ch]++;
        }

        std::priority_queue<Node*, std::vector<Node*>, compare> minHeap;
        for (auto pair : freq) {
            minHeap.push(new Node(pair.first, pair.second));
        }

        while (minHeap.size() != 1) {
            Node* left = minHeap.top();
            minHeap.pop();
            Node* right = minHeap.top();
            minHeap.pop();

            Node* top = new Node('$', left->freq + right->freq);
            top->left = left;
            top->right = right;

            minHeap.push(top);
        }

        root = minHeap.top();
        generateCodes(root, "");
    }

    void generateCodes(Node* node, const std::string& str) {
        if (!node) {
            return;
        }

        if (node->data != '$') {
            huffmanCodes[node->data] = str;
        }

        generateCodes(node->left, str + "0");
        generateCodes(node->right, str + "1");
    }

    void deleteTree(Node* node) {
        if (!node) return;

        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }

public:
    HuffmanCoding() : root(nullptr) {}

    ~HuffmanCoding() {
        deleteTree(root);
    }

    std::string encode(const std::string& text) {
        buildHuffmanTree(text);
        std::string encodedString;
        for (char ch : text) {
            encodedString += huffmanCodes[ch];
        }
        return encodedString;
    }

    std::string decode(const std::string& encodedString) {
        std::string decodedString;
        Node* currentNode = root;
        for (char bit : encodedString) {
            currentNode = (bit == '0') ? currentNode->left : currentNode->right;
            if (!currentNode->left && !currentNode->right) {
                decodedString += currentNode->data;
                currentNode = root;
            }
        }
        return decodedString;
    }
};

int main() {
    std::string text = "huffman coding example";
    HuffmanCoding hc;

    std::string encodedString = hc.encode(text);
    std::cout << "Encoded string: " << encodedString << std::endl;

    std::string decodedString = hc.decode(encodedString);
    std::cout << "Decoded string: " << decodedString << std::endl;

    return 0;
}