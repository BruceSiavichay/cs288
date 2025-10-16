#include <stdio.h>

int main(){
	/*
	int arr[20];
	float arr_2[20];
	int value = -10;
	for(int i = 0; i < 20; i++){
		arr[i] = value;
		arr_2[i] = value;
		value++;
	}
	*/

	int arr[3][2];
	int value = 0;
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 2; j++){
			arr[i][j] = value;
			value++
		}
	}

	//treating a MD array as a 1D array through pointers
	int *ptr = (int *) arr;
	for(int i = 0; i < 6; i++){
		printf("%d\n", ptr[i]);
	}

	//you could do the vice versa with pointers by having two for loops and treating it as rows and columns.

	return 0;
}
