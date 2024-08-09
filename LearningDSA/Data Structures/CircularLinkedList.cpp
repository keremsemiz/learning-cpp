#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class CircularLinkedList {
private:
    Node* last;

public:
    CircularLinkedList() : last(nullptr) {}

    void insert(int value) {
        Node* newNode = new Node(value);
        if (last == nullptr) {
            last = newNode;
            last->next = last;
        } else {
            newNode->next = last->next;
            last->next = newNode;
            last = newNode;
        }
        std::cout << value << " inserted into list" << std::endl;
    }

    void deleteNode(int value) {
        if (last == nullptr) {
            std::cout << "List is empty" << std::endl;
            return;
        }
        Node* temp = last->next;
        Node* prev = last;
        do {
            if (temp->data == value) {
                if (temp == last) {
                    if (temp == last->next) {
                        last = nullptr;
                    } else {
                        prev->next = temp->next;
                        last = prev;
                    }
                } else {
                    prev->next = temp->next;
                }
                delete temp;
                std::cout << value << " deleted from list" << std::endl;
                return;
            }
            prev = temp;
            temp = temp->next;
        } while (temp != last->next);
        std::cout << value << " not found in the list" << std::endl;
    }

    void display() {
        if (last == nullptr) {
            std::cout << "List is empty" << std::endl;
            return;
        }
        Node* temp = last->next;
        do {
            std::cout << temp->data << " ";
            temp = temp->next;
        } while (temp != last->next);
        std::cout << std::endl;
    }
};

int main() {
    CircularLinkedList list;
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.display();
    list.deleteNode(20);
    list.display();
    return 0;
}