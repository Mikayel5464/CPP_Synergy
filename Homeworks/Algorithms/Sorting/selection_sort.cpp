#include <iostream>
#include <vector>

template <typename T>
void swap(T& a, T& b) {
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
void arrayPrint(const std::vector<T>& arr) {
	for (int i = 0; i < arr.size(); ++i) {
		std::cout << arr[i] << " ";
	}

	std::cout << std::endl;
}

template <typename T>
void selectionSort(std::vector<T>& arr) {
	for (int i = 0; i < arr.size() - 1; ++i) {
		int min_index = i;

		for (int j = i + 1; j < arr.size(); ++j) {
			if (arr[j] < arr[min_index]) {
				min_index = j;
			}
		}

		swap(arr[min_index], arr[i]);
	}
}

int main() {
	std::vector<int> array{5, 6, 11, 2, 21, 9};
	
	std::cout << "Not sorted array: ";
	arrayPrint(array);

	selectionSort(array);

	std::cout << "Sorted array: ";
	arrayPrint(array);
	
	return 0;
}