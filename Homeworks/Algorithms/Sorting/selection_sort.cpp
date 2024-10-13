#include <iostream>

void swap(int&, int&);
void arrayPrint(int*, size_t);
void selectionSort(int*, size_t);

int main() {
	int array[] = {5, 6, 11, 2, 21, 9};
	size_t size = sizeof(array) / sizeof(array[0]);

	std::cout << "Not sorted array: ";
	arrayPrint(array, size);

	selectionSort(array, size);

	std::cout << "Sorted array: ";
	arrayPrint(array, size);
	
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

void selectionSort(int* arr, size_t size) {
	if (size <= 0) {
        return;
    }

    if (arr == nullptr) {
        return;
    }
	
	for (int i = 0; i < size - 1; ++i) {
		int min_index = i;

		for (int j = i + 1; j < size; ++j) {
			if (arr[j] < arr[min_index]) {
				min_index = j;
			}
		}

		swap(arr[min_index], arr[i]);
	}
}
