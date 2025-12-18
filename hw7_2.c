#include <stdio.h>
#define MAX 100

void radix(unsigned int A[], unsigned int n, unsigned int k){
	unsigned int bucket0[MAX], bucket1[MAX], bucket2[MAX], bucket3[MAX], bucket4[MAX], bucket5[MAX], bucket6[MAX], bucket7[MAX], bucket8[MAX], bucket9[MAX], bucketA[MAX], bucketB[MAX], bucketC[MAX], bucketD[MAX], bucketE[MAX], bucketF[MAX];
	unsigned int mask, count0, count1, count2, count3, count4, count5, count6, count7, count8, count9, countA, countB, countC, countD, countE, countF;

	int d = 0;

	while(d < k){
		count0=count1=count2=count3=count4=count5=count6=count7=count8=count9=countA=countB=countC=countD=countE=countF=0;
		for(int i = 0; i < n; i++){
			mask = 0xF << d;
                	unsigned int digit = (A[i] & mask) >> d;

			//printf("%d", digit);

			if(d == 31){
				digit=(A[i] >> 31) & 1;
			}


			if(digit == 0){
				bucket0[count0++] = A[i];
			}else if(digit == 1){
				bucket1[count1++] = A[i];
			}else if(digit == 2){
				bucket2[count2++] = A[i];
			}else if(digit == 3){
				bucket3[count3++] = A[i];
			}else if(digit == 4){
                                bucket4[count4++] = A[i];
                        }else if(digit == 5){
                                bucket5[count5++] = A[i];
                        }else if(digit == 6){
                                bucket6[count6++] = A[i];
                        }else if(digit == 7){
                                bucket7[count7++] = A[i];
                        }else if(digit == 8){
                                bucket8[count8++] = A[i];
                        }else if(digit == 9){
                                bucket9[count9++] = A[i];
                        }else if(digit == 0xA){
                                bucketA[countA++] = A[i];
                        }else if(digit == 0xB){
                                bucketB[countB++] = A[i];
                        }else if(digit == 0xC){
                                bucketC[countC++] = A[i];
                        }else if(digit == 0xD){
                                bucketD[countD++] = A[i];
                        }else if(digit == 0xE){
                                bucketE[countE++] = A[i];
                        }else if(digit == 0xF){
                                bucketF[countF++] = A[i];
                        }
		}

		int totalCount = 0;

		if(d == 31){
			//here we are checking final bit so only bucket0 and bucket1 is necessary
			for(int i = 0; i < count1; i++){
				A[i] = bucket1[i];
			}
			for(int i = 0; i < count0; i++){
				A[i+count1] = bucket0[i];
			}
		}else{
			for(int i = 0; i < count0; i++){
                                A[i] = bucket0[i];
                        }
			totalCount += count0;
                        for(int i = 0; i < count1; i++){
                                A[i + totalCount] = bucket1[i];
                        }
			totalCount += count1;
                        for(int i = 0; i < count2; i++){
                                A[i + totalCount] = bucket2[i];
                        }
			totalCount += count2;
                        for(int i = 0; i < count3; i++){
                                A[i + totalCount] = bucket3[i];
                        }
			totalCount += count3;
                        for(int i = 0; i < count4; i++){
                                A[i + totalCount] = bucket4[i];
                        }
			totalCount += count4;
                        for(int i = 0; i < count5; i++){
                                A[i + totalCount] = bucket5[i];
                        }
			totalCount += count5;
                        for(int i = 0; i < count6; i++){
                                A[i+totalCount] = bucket6[i];
                        }
			totalCount += count6;
                        for(int i = 0; i < count7; i++){
                                A[i+totalCount] = bucket7[i];
                        }
			totalCount += count7;
                        for(int i = 0; i < count8; i++){
                                A[i+totalCount] = bucket8[i];
                        }
			totalCount += count8;
                        for(int i = 0; i < count9; i++){
                                A[i+totalCount] = bucket9[i];
                        }
			totalCount += count9;
                        for(int i = 0; i < countA; i++){
                                A[i+totalCount] = bucketA[i];
                        }
			totalCount += countA;
                        for(int i = 0; i < countB; i++){
                                A[i+totalCount] = bucketB[i];
                        }
			totalCount += countB;
                        for(int i = 0; i < countC; i++){
                                A[i+totalCount] = bucketC[i];
                        }
			totalCount += countC;
                        for(int i = 0; i < countD; i++){
                                A[i+totalCount] = bucketD[i];
                        }
			totalCount += countD;
                        for(int i = 0; i < countE; i++){
                                A[i+totalCount] = bucketE[i];
                        }
			totalCount += countE;
                        for(int i = 0; i < countF; i++){
                                A[i+totalCount] = bucketF[i];
                        }	
		}
		if(d == 28){
			d=31;
		}else{
			d+=4;
		}
	}
}

int main(){
	int size;
	//printf("Enter amount of numbers to be sorted: ");
	scanf("%d", &size);

	unsigned int arr[size];

	for(int i = 0; i < size; i++){
		unsigned int value;
		//printf("Enter number at index %d: ", i);
		scanf("%d", &value);
		//printf("%4X", value);
		arr[i] = value;
	}

	unsigned int k = sizeof(int) * 8;

	radix(arr, size, k);

	for(int i = 0; i < size; i++){
		printf("%d \n", arr[i]);
	}

	return 0;
}
