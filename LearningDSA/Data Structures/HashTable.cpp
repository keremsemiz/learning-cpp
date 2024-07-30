#include <iostream>
#include <vector>

class HashTable {
private:
    static const int TABLE_SIZE = 10;
    std::vector<int> table;

public:
    HashTable() : table(TABLE_SIZE, -1) {}

    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

    void insert(int key) {
        int index = hashFunction(key);
        int originalIndex = index;

        while (table[index] != -1) {
            index = (index + 1) % TABLE_SIZE;
            if (index == originalIndex) {
                std::cout << "Hash table is full" << std::endl;
                return;
            }
        }

        table[index] = key;
        std::cout << "Inserted " << key << " at index " << index << std::endl;
    }

    int search(int key) {
        int index = hashFunction(key);
        int originalIndex = index;

        while (table[index] != -1) {
            if (table[index] == key) {
                return index;
            }
            index = (index + 1) % TABLE_SIZE;
            if (index == originalIndex) {
                break;
            }
        }

        return -1;
    }

    void display() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            std::cout << i << ": " << table[i] << std::endl;
        }
    }
};

int main() {
    HashTable ht;
    ht.insert(10);
    ht.insert(20);
    ht.insert(30);
    ht.insert(40);
    ht.insert(50);
    ht.display();

    int key = 30;
    int index = ht.search(key);
    if (index != -1) {
        std::cout << "Key " << key << " found at index " << index << std::endl;
    } else {
        std::cout << "Key " << key << " not found" << std::endl;
    }

    return 0;
}
