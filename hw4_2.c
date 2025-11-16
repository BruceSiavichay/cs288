#include <stdio.h>

int main(){
	FILE *stream1, *stream2;
	stream1 = fopen("sparse_matrix1.txt", "r");
	stream2 = fopen("sparse_matrix2.txt", "r");

	if(stream1 == NULL || stream2 == NULL){
		perror("fopen");
	}

	int a_n, a_m, b_n, b_m;

	//fread for raw data, fscanf for text data
	fscanf(stream1, "%d", &a_n);
	fscanf(stream1, "%d", &a_m);
	fscanf(stream2, "%d", &b_n);
	fscanf(stream2, "%d", &b_m);

	int A_values[a_m], A_column_indicies[a_m], A_row_start[a_n+1], B_values[b_m], B_column_indicies[b_m], B_row_start[b_n+1];

	for(int i = 0; i < a_m; i++){
		int num;
		fscanf(stream1, "%d", &num);
		A_values[i] = num;
	}

	for(int i = 0; i < a_m; i++){
		int num;
		fscanf(stream1, "%d", &num);
		A_column_indicies[i] = num;
	}

	for(int i = 0; i < a_n + 1; i++){
		int num;
		fscanf(stream1, "%d", &num);
		A_row_start[i] = num;
	}

	for(int i = 0; i < b_m; i++){
		int num;
		fscanf(stream2, "%d", &num);
		B_values[i] = num;
	}

	for(int i = 0; i < b_m; i++){
		int num;
		fscanf(stream2, "%d", &num);
		B_column_indicies[i] = num;
	}

	for(int i = 0; i < b_n + 1; i++){
		int num;
		fscanf(stream2, "%d", &num);
		B_row_start[i] = num;
	}

	fclose(stream1);
	fclose(stream2);

	if(a_n != b_n){
		printf("%s", "Error: Matrices are not of same size");
		return 0;
	}

	//done populating
	int totalValueCount = 0;
	
	//this for loop is just for allocating the right amount of space
	for(int i = 0; i < a_n; i++){
		int A_pointer = A_row_start[i];
		int B_pointer = B_row_start[i];
		int A_end = A_row_start[i+1];
		int B_end = B_row_start[i+1];
		int row_count = 0;
		
		//checks until one of the pointers reaches the end
		while(A_pointer < A_end && B_pointer < B_end){
			if(A_column_indicies[A_pointer] == B_column_indicies[B_pointer]){
				if(A_values[A_pointer] + B_values[B_pointer] != 0){
					row_count++;
				}
				A_pointer++;
				B_pointer++;
			}else if(A_column_indicies[A_pointer] < B_column_indicies[B_pointer]){
				row_count++;
				A_pointer++;
			}else if(B_column_indicies[B_pointer] < A_column_indicies[A_pointer]){
				row_count++;
				B_pointer++;
			}
		}

		row_count += (A_end - A_pointer) + (B_end - B_pointer); //adds any remaining stuff after while loop ends
		totalValueCount += row_count;
	}

	int result_values[totalValueCount], result_column_indicies[totalValueCount];

	//this is to avoid garbage values
	for(int i = 0; i < totalValueCount; i++){
		result_values[i] = 0;
		result_column_indicies[i] = 0;
	}

	int pointer = 0;
	int result_row_start[a_n + 1];
	//first value always 0
	result_row_start[0] = 0;

	for(int i = 0; i < a_n; i++){
		int A_pointer = A_row_start[i];
		int B_pointer = B_row_start[i];
		int A_end = A_row_start[i+1];
		int B_end = B_row_start[i+1];
		int row_count = 0;

		while(A_pointer < A_end &&  B_pointer < B_end){
			if(A_column_indicies[A_pointer] == B_column_indicies[B_pointer]){
				if(A_values[A_pointer] + B_values[B_pointer] != 0){
					result_values[pointer] = A_values[A_pointer] + B_values[B_pointer];
                                	result_column_indicies[pointer] = A_column_indicies[A_pointer];
                                	row_count++;
                                	pointer++;
				}
				A_pointer++;
				B_pointer++;
			}else if(A_column_indicies[A_pointer] < B_column_indicies[B_pointer]){
				result_values[pointer] = A_values[A_pointer];
				result_column_indicies[pointer] = A_column_indicies[A_pointer];
				A_pointer++;
				row_count++;
				pointer++;
			}else if(B_column_indicies[B_pointer] < A_column_indicies[A_pointer]){
				result_values[pointer] = B_values[B_pointer];
				result_column_indicies[pointer] = B_column_indicies[B_pointer];
				B_pointer++;
				row_count++;
				pointer++;
			}
		}

		//the two while loops below are for the remaining ones
		while(A_pointer < A_end){
			result_values[pointer] = A_values[A_pointer];
                        result_column_indicies[pointer] = A_column_indicies[A_pointer];
                        A_pointer++;
                        row_count++;
                        pointer++;
		}

		while(B_pointer < B_end){
			result_values[pointer] = B_values[B_pointer];
                        result_column_indicies[pointer] = B_column_indicies[B_pointer];
                        B_pointer++;
                        row_count++;
                        pointer++;
		}

		result_row_start[i+1] = result_row_start[i] + row_count;
	}

	FILE *stream3;
	stream3 = fopen("result_matrix.txt", "w");

	fprintf(stream3, "%d \n", a_n);
	fprintf(stream3, "%d \n", totalValueCount);
	for(int i = 0; i < totalValueCount; i++){
		fprintf(stream3, "%d \n", result_values[i]);
	}
	for(int i = 0; i < totalValueCount; i++){
		fprintf(stream3, "%d \n", result_column_indicies[i]);
	}
	for(int i = 0; i < a_n + 1; i++){
		fprintf(stream3, "%d \n", result_row_start[i]);
	}
}
