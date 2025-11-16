#include <stdio.h>

struct transaction{
	int index;
	char name[20];
	float price;
	//struct transaction *ptr;
	//struct transaction *ptr2;
}

int main(){
	int x = 10;

	struct transaction rec1 = {1, "john1", 85.5};

	int *field1 = (int *)&rec1;
	char* field = (char *)&rec1 + 4;
	float *field3 = (float *)((char *)&rec1 + 24);

	/*
	struct transaction rec1 = {1, "john", 85.5};
	struct transaction *ptr = &rec1;
	printf("%d", rec1.index);
	printf("%d", ptr->index);
	*/


	return 0;
}
