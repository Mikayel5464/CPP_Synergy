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
void countingSort(std::vector<T>& arr) {
    if (arr.empty()) {
        return;
    }

    T max_val = *std::max_element(arr.begin(), arr.end());
    std::vector<T> count(max_val + 1, 0);

    for (int i = 0; i < arr.size(); ++i) {
        ++count[arr[i]];
    }

    int index = 0;
    
    for (int i = 0; i <= max_val; ++i) {
        while (count[i] > 0) {
            arr[index++] = i;
            --count[i];
        }
    }
}

int main() {
    std::vector array{7, 15, 8, 2, 4, 1};

    std::cout << "Not sorted array: ";
	arrayPrint(array);

	countingSort(array);
	
	std::cout << "Sorted array: ";
	arrayPrint(array);

    return 0;
}