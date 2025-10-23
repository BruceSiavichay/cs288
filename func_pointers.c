#include <stdio.h>

int cube(int);
int square(int);

int main(){
	int (*fptr)(int);

	int n;
	scanf("%d", &n);
	if(n==0){
		fptr = square;
		printf("%d", fptr(n))
	}else{
		fptr = cube;
		printf("%d", fptr(n));
	}
	return 0;
}


int square(int num){
	return num*num;
}
int cube(int num){
	return num*num*num;
}
