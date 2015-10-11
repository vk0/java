#define SIZE 10000

int main()
{
	int * buffer = new int[SIZE*SIZE];
	int ** matrix = new int*[SIZE];

	for (int i = 0; i < SIZE; i++) {
		matrix[i] = buffer+i*SIZE;
	}

	delete[] matrix;
	delete[] buffer;
}
