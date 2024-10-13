#include <iostream>
#include <vector>

template <typename T>
void swap(T& a, T& b) {
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
void arrayPrint(const std::vector<T>& arr, const size_t size) {
	for (int i = 0; i < size; ++i) {
		std::cout << arr[i] << " ";
	}

	std::cout << std::endl;
}

template <typename T>
void bubbleSort(std::vector<T>& arr, const size_t size) {
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

int main() {
	std::vector<int> array{7, 4, -23, 54, 20, -40, 0};
	const size_t arr_size = array.size();

	std::cout << "Not sorted array: ";
	arrayPrint(array, arr_size);

	bubbleSort(array, arr_size);
	
	std::cout << "Sorted array: ";
	arrayPrint(array, arr_size);

	return 0;
}
