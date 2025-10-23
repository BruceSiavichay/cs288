#include <stdio.h>

//passing addresses between functions

int cube(int *);

int main(){
	int n=5;
	int result = cube(&n);
	printf("%d", result);
	return 0;
}

int cube(int *num){
	*num = *num * *num * *num;
}

