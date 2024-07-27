#include <iostream>

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST {
private:
    TreeNode* root;

    void inOrder(TreeNode* node) const {
        if (node) {
            inOrder(node->left);
            std::cout << node->data << " ";
            inOrder(node->right);
        }
    }

    TreeNode* insert(TreeNode* node, int data) {
        if (!node) {
            return new TreeNode(data);
        }
        if (data < node->data) {
            node->left = insert(node->left, data);
        } else {
            node->right = insert(node->right, data);
        }
        return node;
    }

    bool search(TreeNode* node, int data) const {
        if (!node) return false;
        if (node->data == data) return true;
        if (data < node->data) return search(node->left, data);
        return search(node->right, data);
    }

public:
    BST() : root(nullptr) {}

    void insert(int data) {
        root = insert(root, data);
    }

    bool search(int data) const {
        return search(root, data);
    }

    void displayInOrder() const {
        inOrder(root);
        std::cout << std::endl;
    }
};

int main() {
    BST bst;
    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    bst.insert(2);
    bst.insert(4);
    bst.insert(6);
    bst.insert(8);

    std::cout << "In-order traversal: ";
    bst.displayInOrder();

    std::cout << "Search for 4: " << (bst.search(4) ? "Found" : "Not Found") << std::endl;
    std::cout << "Search for 9: " << (bst.search(9) ? "Found" : "Not Found") << std::endl;

    return 0;
}
