// task - find the maximum element

#include <iostream>

int findMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int arr[] = {10, 20, 5, 30, 15};
    int size = sizeof(arr) / sizeof(arr[0]);
    std::cout << "Maximum element in the array: " << findMax(arr, size) << std::endl;
    return 0;
}
