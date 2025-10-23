#include <stdio.h>
#include <string.h>

int main(){
	char str[] = "abcd";
	char str1[] = "abcd\0helloworld";
	printf("%lu \n", sizeof(str));
	printf("%lu \n", strlen(str));"

	//the string functions will stop at the null delimiter
	printf("%lu \n", strlen(str1));

	char str3[] = "tom@njit.edu:home/cs288/fall-2025";
	char delimiter[] = "@.:/-"
	char *token;
	token = strtok(str3, delimiter);
	//printf("%s", token)
	
	while(token != NULL){
		printf("%s \n", token);
		//recognizes to continue from MULL in str3
		token = strtok(NULL, delimiter);
	}
	return 0;
}
