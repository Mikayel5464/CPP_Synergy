#include <iostream>

void arrayPrint(int*, size_t);
void insertionSort(int*, size_t);

int main() {
    int array[] = {9, -5, 1, 4, 31, -20, 8, 0};
    size_t size = sizeof(array) / sizeof(array[0]);

    std::cout << "Not sorted array: ";
    arrayPrint(array, size);

    insertionSort(array, size);

    std::cout << "Sorted array: ";
    arrayPrint(array, size);
    
    return 0;
}

void arrayPrint(int* arr, size_t size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
}

void insertionSort(int* arr, size_t size) {
    if (size <= 0) {
        return;
    }

    if (arr == nullptr) {
        return;
    }
    
    for (int i = 1; i < size; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && key < arr[j]) {
            arr[j + 1] = arr[j];
            --j;
        }

        arr[j + 1] = key;
    }
}
