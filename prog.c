#include <stdio.h>

int main(){
        //int arr[10];
	//int index=1;
	//int index=37829173 results in segmentation fault

	//arr[index]=123;
	//printf("The value at %d is %d", index, arr[index]);
	//
	//in c by default, without initialization it assigns a garbage value
	int num, result = 1;
	scanf("%d", &num);

	for(int i = 1; i <= num; i++){
		result=result*i;
	}

	printf("\n %d", result);

	return 0;
}
