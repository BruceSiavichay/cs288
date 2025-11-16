#include <stdio.h>
#define MAX 100

void radix(unsigned int A[], unsigned int n, unsigned int k){
	//create two buckets for each possible bit
	unsigned int bucket0[MAX], bucket1[MAX];
	unsigned int mask, count0, count1;

	//outer loop iterates through the bits from least to most significant
	for(int d = 0; d < k; d++){
		//innter loop iterates through each element in the array A
		mask = 1<<d;
		count0=count1=0;
		for(int i = 0; i < n; i++){
			//distributing the elements using the d-th bit as the key
			if((A[i]&mask) == 0){
				bucket0[count0++] = A[i];
			}else{
				bucket1[count1++] = A[i];
			}
		}
		//joining the buckets (join bucket 0 first then bucket 1 for ascending order)
		for(int i = 0; i < count0; i++){
			A[i] = bucket0[i];
		}
		for(int i = 0; i < count1; i++){
			A[i+count0] = bucket1[i];
		}
	}
}


int main(){
	unsigned int arr[] = {12, 33, 13, 89, 0, 67, 56};
	unsigned int n = sizeof(arr) / sizeof(arr[0]);
	unsigned int k = sizeof(int) * 8;

	radix(arr, n, k);
	for(int i = 0; i < n; i++){
		printf("%4d", arr[i]);
	}
}
