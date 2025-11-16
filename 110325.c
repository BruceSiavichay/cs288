#include <stdio.h>

int main(){
	/*
	unsigned int x = 10;
	unsigned int y = 20;
	printf("%d \n", x&y);
	printf("%d \n", x|y);
	printf("%d \n", x^y);
	printf("%d \n", x<<2);
	return 0;*/

	/*
	unsigned int x = 10;
	unsigned int n = 2;
	unsigned int mask = 1 << n;
	printf("%d \n", x|mask);*/

	unsigned int x = 10;
	unsigned int n = 4;
	unsigned int mask = 0xf << n;

	unsigned int x = 10;
	unsigned int n = 3;
	unsigned int mask = ~(1<<n);
	printf("%d \n", x&mask);
}
