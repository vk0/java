#define SIZE 10000

int main() {
	int ** matrix = new int*[SIZE];

	for (int i = 0; i < SIZE; i++) {
		matrix[i] = new int[SIZE];
	}

	for (int i = 0; i < SIZE; i++)
		delete[] matrix[i];

	delete[] matrix;

	return 0;
}
