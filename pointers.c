#include <stdio.h>
#include <stdlib.h>

int main(){
	/*
	int var = 10;
	int *ptr = &var;
	int **pptr = &ptr;
	printf("%d \n", *ptr);
	printf("%d \n", *pptr); //shows memory address of ptr
	printf("%d \n", **pptr); //shows the value, dereferences twice
				 
	int *arr[5]; //stored stack, better for constant stuff
	int **arr2 = (int **)malloc(5*sizeof(int*)); //same thing, stored heap 
	for(int i=0; i<5; i++){
		arr[i] = (int *)malloc(sizeof(int));
		*arr[i] = i;
	}

	for(int i = 0; i < 5; i++){
		printf("%4d", *arr[i]);
	}*/

	int rows=2, columns=4, value=1;
	int ** matrix = (int **)malloc(rows * sizeof(int *));

	for(int i = 0; i < rows; i++){
		matrix[i] = (int *)malloc((columns+i)*sizeof(int)); //jagged
	}

	for(int i=0; i<2; i++){
		for(int j = 0; j < columns+i; j++){
			matrix[i][j] = value++;
		}
	}

	for(int i=0; i<2; i++){
                for(int j = 0; j < columns+i; j++){
                        printf("%4d", matrix[i][j]);
                }
        }


	return 0;
}
