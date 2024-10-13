#include <iostream>
#include <vector>

template <typename T>
void arrayPrint(const std::vector<T>& arr, const size_t size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
}

template <typename T>
void insertionSort(std::vector<T>& arr, const size_t size) {
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

int main() {
    std::vector<int> array{9, -5, 1, 4, 31, -20, 8, 0};
    const size_t arr_size = array.size();

    std::cout << "Not sorted array: ";
    arrayPrint(array, arr_size);

    insertionSort(array, arr_size);

    std::cout << "Sorted array: ";
    arrayPrint(array, arr_size);
    
    return 0;
}
