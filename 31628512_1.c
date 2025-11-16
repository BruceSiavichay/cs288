#include <stdio.h>
#include <stdint.h>
#include <ctype.h>

int main(int argc, char * argv[]){
	printf("argv | ");
	//printf("%02hhx ", argv[0][i]);

	unsigned char *p = (unsigned char *)&argv;
	for(int i = 7; i >= 0; i--){
		printf("%02hhx ", *(p+i));
	}

	printf(" | %p \n", &argv);

	printf("\n");

	//printf("%p \n", (void *)argv[0]);

	for(int i = 0; i < argc; i++){
		printf("argv[%d] | ", i);
		unsigned char *p2 = (unsigned char *)&argv[i];
		for(int j = 7; j >= 0; j--){
			printf("%02hhx ", *(p2+j));
		}

		printf(" | %p \n", &argv[i]);
		//printf("%p \n", (void *)argv[0]);
	}

	printf("\n");

	unsigned char *p3 = (unsigned char *)argv[0];

	//uintptr_t converts the ptr thing to an integer
	while(((uintptr_t) p3) % 8 != 0){
		p3--;
	}

	unsigned char *end = NULL;
	char *final_arg = argv[argc-1];
	while(*final_arg){
		final_arg++;
	}

	end = (unsigned char *)(final_arg+1);

	while(p3 < end){
		printf("|");
		for(int i = 7; i >= 0; i--){
			printf("%02hhx", *(p3 + i));
			if(isprint(*(p3+i))){
				printf("(%c) ", *(p3 + i));
			}else{
				printf("(\\0) ");
			}
		}
		printf("| %p \n", p3);
		p3 += 8;
	}

	return 0;
}



