#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv){
	printf("mem. addr. of argc: %p\n", &argc);
	printf("mem. addr. of argv: %p\n", &argv);
	printf("mem. addr. of argv[0]: %p\n", argv);
	printf("mem. addr. in argv[0]: %p\n", argv[0]);
	return 0;

	//break 10
	//run param1 param2 param3
	//x/8xg argv
	//x/64cb argv[0]
}
