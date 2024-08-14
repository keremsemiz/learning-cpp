#include <iostream>
#include <vector>

int mergeAndCount(std::vector<int>& arr, int l, int m, int r) {
    int leftSize = m - l + 1;
    int rightSize = r - m;

    std::vector<int> left(leftSize);
    std::vector<int> right(rightSize);

    for (int i = 0; i < leftSize; i++) {
        left[i] = arr[l + i];
    }
    for (int i = 0; i < rightSize; i++) {
        right[i] = arr[m + 1 + i];
    }

    int i = 0, j = 0, k = l;
    int inversions = 0;

    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
            inversions += (leftSize - i);
        }
    }

    while (i < leftSize) {
        arr[k++] = left[i++];
    }

    while (j < rightSize) {
        arr[k++] = right[j++];
    }

    return inversions;
}

int countInversions(std::vector<int>& arr, int l, int r) {
    int inversions = 0;
    if (l < r) {
        int m = l + (r - l) / 2;

        inversions += countInversions(arr, l, m);
        inversions += countInversions(arr, m + 1, r);
        inversions += mergeAndCount(arr, l, m, r);
    }
    return inversions;
}

int main() {
    std::vector<int> arr = {1, 20,