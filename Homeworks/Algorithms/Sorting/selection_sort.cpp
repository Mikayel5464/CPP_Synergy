#include <iostream>
#include <vector>

template <typename T>
void swap(T& a, T& b) {
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
void arrayPrint(const std::vector<T>& arr, size_t size) {
	for (int i = 0; i < size; ++i) {
		std::cout << arr[i] << " ";
	}

	std::cout << std::endl;
}

template <typename T>
void selectionSort(std::vector<T>& arr, size_t size) {
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

int main() {
	std::vector<int> array{5, 6, 11, 2, 21, 9};
	const size_t arr_size = array.size();

	std::cout << "Not sorted array: ";
	arrayPrint(array, arr_size);

	selectionSort(array, arr_size);

	std::cout << "Sorted array: ";
	arrayPrint(array, arr_size);
	
	return 0;
}