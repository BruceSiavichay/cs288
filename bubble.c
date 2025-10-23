#include <stdio.h>
#define SIZE 10

int ascending(int a, int b){
	return a > b;
}
int descending(int a, int b){
	return a < b;
}

void bubble(int *, const int, int(*compare)(int, int));
void swap(int *, int *);


int main(){
	int array[SIZE] = {20, 19, 72, 1, 23, 10, 58, 12, 43, 44};
	bubble(array, SIZE, descending);
	for(int i=0; i<SIZE; i++){
		printf("%4d", array[i]);
	}
}

void bubble(int *arr, const int size, int (*compare)(int, int)){
	for(int i=0; i<size; i++){
		for(int j=0; j<size-1; j++){
			if ((*compare)(arr[j], arr[j+1])){
				swap(&arr[j], &arr[j+1]);
			}
		}
	}
}

void swap(int *elem1, int *elem2){
	int hold = *elem1;
	*elem1 = *elem2;
	*elem2 = hold;
}
