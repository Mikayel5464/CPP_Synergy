#include <iostream>
#include <vector>

template <typename T>
void arrayPrint(const std::vector<T>& arr) {
    for (int i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
}

template <typename T>
void insertionSort(std::vector<T>& arr) {
    for (int i = 1; i < arr.size(); ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && key < arr[j]) {
            arr[j + 1] = arr[j];
            --j;
        }

        arr[j + 1] = key;
    }
}

int main() {
    std::vector<int> array{9, -5, 1, 4, 31, -20, 8, 0};

    std::cout << "Not sorted array: ";
    arrayPrint(array);

    insertionSort(array);

    std::cout << "Sorted array: ";
    arrayPrint(array);
    
    return 0;
}
