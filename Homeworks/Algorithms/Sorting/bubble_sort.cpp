#include <iostream>

void swap(int&, int&);
void arrayPrint(int*, size_t);
void bubbleSort(int*, size_t);

int main() {
	int array[] = {7, 4, 23, 54, 20, 40, 0};
	size_t arr_size = sizeof(array) / sizeof(array[0]);

	std::cout << "Not sorted array: ";
	arrayPrint(array, arr_size);

	bubbleSort(array, arr_size);
	
	std::cout << "Sorted array: ";
	arrayPrint(array, arr_size);

	return 0;
}

void swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void arrayPrint(int* arr, size_t size) {
	for (int i = 0; i < size; ++i) {
		std::cout << arr[i] << " ";
	}

	std::cout << std::endl;
}

void bubbleSort(int* arr, size_t size) {
	if (size <= 0) {
        return;
    }

    if (arr == nullptr) {
        return;
    }

	for (int i = 0; i < size - 1; ++i) {
		bool is_swapped = false;

		for (int j = 0; j < size - i - 1; ++j) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);

				is_swapped = true;
			}
		}

		if(!is_swapped) {
			break;
		}
	}
}
