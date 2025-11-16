#include <stdio.h>

int main() {
	int n;
	int matrix1[100][100], matrix2[100][100], result_matrix[100][100];

	FILE *stream1, *stream2;
	stream1 = fopen("matrix1.bin", "r");
	stream2 = fopen("matrix2.bin", "r");
	if (stream1 == NULL || stream2 == NULL){
		perror("fopen");
	}

	//reads the first character
	size_t size_read = fread(&n, sizeof(int), 1, stream1);

	int n2;
	size_t size_read2 = fread(&n2, sizeof(int), 1, stream2);

	if(n != n2){
		printf("Matrices are not of the same size");
		return 0;
	}else if(n > 100){
		printf("Matrix size is too high");
		return 0;
	}

	for(int i = 0; i < (n * n); i++){
		int num1, num2;
		size_read = fread(&num1, sizeof(int), 1, stream1);
		size_read2 = fread(&num2, sizeof(int), 1, stream2);

		//populates both arrays
		matrix1[i/n][i%n] = num1;
		matrix2[i/n][i%n] = num2;
	}

	fclose(stream1);
	fclose(stream2);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			for(int k = 0; k < n; k++){
				//got this from the instructions
				result_matrix[i][j] += matrix1[i][k] * matrix2[k][j];
			}
		}
	}

	FILE *stream3;
	stream3 = fopen("matrix3.bin", "w");

	size_t writefile = fwrite(&n, sizeof(int), 1, stream3);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			writefile = fwrite(&result_matrix[i][j], sizeof(int), 1, stream3);
		}
	}

	fclose(stream3);

	FILE *stream4;
	stream4 = fopen("matrix3.bin", "r");

	for(int i = 0; i < (n * n) + 1; i++){
		//printing to show it works
		int num;
		size_read = fread(&num, sizeof(int), 1, stream4);
		printf("%d \n", num);
	}

	fclose(stream4);
}
