#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void insertFront(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        std::cout << val << " inserted at front" << std::endl;
    }

    void insertEnd(int val) {
        Node* newNode = new Node(val);
        if (!tail) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        std::cout << val << " inserted at end" << std::endl;
    }

    void deleteNode(int val) {
        Node* temp = head;
        while (temp && temp->data != val) {
            temp = temp->next;
        }
        if (temp) {
            if (temp->prev) temp->prev->next = temp->next;
            if (temp->next) temp->next->prev = temp->prev;
            if (temp == head) head = temp->next;
            if (temp == tail) tail = temp->prev;
            delete temp;
            std::cout << val << " deleted from list" << std::endl;
        } else {
            std::cout << val << " not found in the list" << std::endl;
        }
    }

    void displayForward() {
        Node* temp = head;
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    void displayBackward() {
        Node* temp = tail;
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->prev;
        }
        std::cout << std::endl;
    }
};

int main() {
    DoublyLinkedList list;
    list.insertFront(10);
    list.insertEnd(20);
    list.insertFront(5);
    list.displayForward();
    list.displayBackward();
    list.deleteNode(10);
    list.displayForward();
    list.displayBackward();
    return 0;
}
