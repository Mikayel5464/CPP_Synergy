#include <iostream>

int** createMatrix(size_t);
void deleteMatrix(int**, size_t);
void inputMatrix(int**, size_t);
void printMatrix(int**, size_t);
int** matrixAddition(int**, int**, size_t);

int main() {
	size_t mat_size = 0;

	std::cout << "Enter the size of matrixes: ";
	std::cin >> mat_size;

	int** mat1 = createMatrix(mat_size);
	std::cout << "Enter the first matrix elements:" << std::endl;
	inputMatrix(mat1, mat_size);

	int** mat2 = createMatrix(mat_size);
	std::cout << "Enter the second matrix elements: " << std::endl;
	inputMatrix(mat2, mat_size);
	
	int** result = matrixAddition(mat1, mat2, mat_size);

	std::cout << "Result matrix:" << std::endl;
	printMatrix(result, mat_size);

	deleteMatrix(mat1, mat_size);
	deleteMatrix(mat2, mat_size);
	deleteMatrix(result, mat_size);

	return 0;
}

int** createMatrix(size_t size) {
	int** matrix = new int*[size];

	for (int i = 0; i < size; ++i) {
		matrix[i] = new int[size];
	}

	return matrix;
}

void deleteMatrix(int** matrix, size_t size) {
	for (int i = 0; i < size; ++i) {
		delete[] matrix[i];
	}

	delete[] matrix;
}

void inputMatrix(int** matrix, size_t size) {
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			std::cin >> matrix[i][j];
		}
	}
}

void printMatrix(int** matrix, size_t size) {
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			std::cout << matrix[i][j] << " ";
		}

		std::cout << std::endl;
	}
}

int** matrixAddition(int** matrix1, int** matrix2, size_t size) {
	int** res_matrix = createMatrix(size);

	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			res_matrix[i][j] = matrix1[i][j] + matrix2[i][j];
		}
	}

	return res_matrix;
}
