#include <stdio.h>
#define MAX 100

void radix(unsigned int A[], unsigned int n, unsigned int k){
	unsigned int bucket0[MAX], bucket1[MAX];
	unsigned int mask, count0, count1;

	for(int d = 0; d < k; d++){
		mask = 1<<d;
		count0=count1=0;
		for(int i = 0; i < n; i++){
			if((A[i]&mask) == 0){
				bucket0[count0++] = A[i];
			}else{
				bucket1[count1++] = A[i];
			}
		}

		if(d == 31){
			//negative numbers
			//come first
			//reversed
			for(int i = 0; i < count1; i++){
				A[i] = bucket1[count1 - i - 1];
			}

			for(int i = 0; i < count0; i++){
				A[i+count1] = bucket0[i];
			}
		}else{
			for(int i = 0; i < count0; i++){
				A[i] = bucket0[i];
			}
			for(int i = 0; i < count1; i++){
				A[i+count0] = bucket1[i];
			}
		}
	}
}

int main(){
	int size;
	//printf("Enter amount of numbers to be sorted: ");
	scanf("%d", &size);

	unsigned int arr[size];

	for(int i = 0; i < size; i++){
		float value;
		//printf("Enter number at index %d: ", i);
		scanf("%f", &value);
		unsigned int *p = (unsigned int *) &value;
		arr[i] = *p;
	}

	//unsigned int n = sizeof(arr) / sizeof(arr[0]);
	unsigned int k = sizeof(int) * 8;

	radix(arr, size, k);

	for(int i = 0; i < size; i++){
		//lets say arr[i] is 2, arr[i] would be the bit value because that's what we are storing.
		//float * is basically saying imagine that this bit value is pointing to a float
		//and we have the outside asterisk to dereference it, and store it inside the float variable
		float val = *(float*)&arr[i];
		printf("%.2f \n", val);
	}

	return 0;
}
