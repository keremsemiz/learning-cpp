#include <iostream>
#include <vector>

class MinHeap {
private:
    std::vector<int> heap;

    void heapifyUp(int index) {
        while (index != 0 && heap[parent(index)] > heap[index]) {
            std::swap(heap[index], heap[parent(index)]);
            index = parent(index);
        }
    }

    void heapifyDown(int index) {
        int smallest = index;
        int left = leftChild(index);
        int right = rightChild(index);

        if (left < heap.size() && heap[left] < heap[smallest])
            smallest = left;
        if (right < heap.size() && heap[right] < heap[smallest])
            smallest = right;

        if (smallest != index) {
            std::swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }

    int parent(int index) { return (index - 1) / 2; }
    int leftChild(int index) { return 2 * index + 1; }
    int rightChild(int index) { return 2 * index + 2; }

public:
    MinHeap() {}

    void insert(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    int extractMin() {
        if (heap.size() == 0) return -1;
        if (heap.size() == 1) {
            int root = heap[0];
            heap.pop_back();
            return root;
        }

        int root = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);

        return root;
    }

    void display() {
        for (int val : heap) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    MinHeap minHeap;
    minHeap.insert(10);
    minHeap.insert(20);
    minHeap.insert(5);
    minHeap.insert(30);
    minHeap.display();

    std::cout << "Extracted min: " << minHeap.extractMin() << std::endl;
    minHeap.display();

    return 0;
}
