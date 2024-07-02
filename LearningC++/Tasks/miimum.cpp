// task - find the smallest element in an array

#include <iostream>

int findMin(int arr[], int size) {
    int min = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int main() {
    int arr[] = {10, 20, 5, 30, 15};
    int size = sizeof(arr) / sizeof(arr[0]);
    std::cout << "Minimum element in the array: " << findMin(arr, size) << std::endl;
    return 0;
}
