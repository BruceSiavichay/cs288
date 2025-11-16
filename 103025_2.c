#include <stdio.h>

int main(int argc, char* argv[], char *envp[]){
	int index = 0;
	while(envp[index]){
		printf("%s \n", envp[index]);
		index++;
	}

	//add an env
	//int setenv(char *name, char *value, int overwrite;
	//int setenv("cs288", "001", 0); //to tell if ur trying to overwrite existing env
	//deletes an env
	//unsetenv(char *name);
	//unsetenv("cs288"); //everything is only being affected in the program
	//
	//get env
	//char *getenv(char *name);
	//char *getenv("cs288");
}
