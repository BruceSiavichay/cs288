#include <stdio.h>

int main() {
	int n;
	int matrix1[100][100], matrix2[100][100], result_matrix[100][100];

	FILE *stream1;
	stream1 = fopen("matrix3.bin", "r");
	if (stream1 == NULL){
		perror("fopen");
	}

	//reads the first character
	size_t size_read = fread(&n, sizeof(int), 1, stream1);

	if(n > 100){
		printf("Matrix size is too high");
	}

	printf("Value of n: %d", n);

	for(int i = 0; i < (n * n); i++){
		int num1;
		size_read = fread(&num1, sizeof(int), 1, stream1);

		//populates array
		matrix1[i/n][i%n] = num1;
	}

	fclose(stream1);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			printf("%d ", matrix1[i][j]);
		}
		printf("\n");
	}
}
