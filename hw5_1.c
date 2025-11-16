#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 256

void bubble(char* arr[], const int);

int main(){
	FILE *stream;
	stream = fopen("env.txt", "r");

	char buffer[SIZE];
	char* lineArray[SIZE];

	if(stream == NULL){
		perror("fopen");
	}

	int counter = 0;
	while(fgets(buffer, sizeof(buffer), stream) != NULL){
		//strchr basically looks for a specific character. one of my env variables is so long so I need this here to get rid of it.
		//this basically says that if you don't find a \n in the first 256 characters, just keep going till the end of the line and skip it
		if(strchr(buffer, '\n') == NULL){
			int c;
			while((c = fgetc(stream)) != '\n' && c != EOF)
				;

			continue;
		}


		//all just preformatting and then allocating the right amount of space
		buffer[strcspn(buffer, "\n")] = '\0';
		buffer[SIZE-1]='\0';
		lineArray[counter] = malloc(strlen(buffer) + 1);
		strcpy(lineArray[counter], buffer);
		counter++;

		if(counter > 255){
			break;
		}
	}

	fclose(stream);

	//for(int i = 0; i < counter; i++){
        //        printf("%s \n", lineArray[i]);
        //}

	bubble(lineArray, counter);

	FILE *stream2;
	stream2 = fopen("sorted_env.txt", "w");

	if(stream2 == NULL){
		perror("fopen");
	}

	for(int i = 0; i < counter; i++){
		fprintf(stream2, "%s \n", lineArray[i]);
	}

	fclose(stream2);

	return 0;
}

void bubble(char* arr[], const int size){
	char *token1;
	char *token2;
	for(int i = 0; i < size - 1; i++){
		for(int j = 0; j < size - i - 1; j++){
			//char *token1;
			//char *token2;

			token1 = strtok(arr[j], "=");
			token2 = strtok(arr[j+1], "=");

			//printf("Token1: %s \n", token1);
			//printf("Token2: %s \n", token2);
			
			//printf("%c", arr[j][strlen(token1)]);
			arr[j][strlen(token1)] = '=';
			//printf("%c", arr[j][strlen(token1)]);
			arr[j+1][strlen(token2)] = '=';

			
			if(strcmp(token1, token2) > 0){
				char* hold = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = hold;
				//arr[j+i][strlen(token1)] = '=';
				//printf("%c", arr[j][strlen(token1)]);
				//arr[j][strlen(token2)] = '=';
			}

			//printf("%s", arr[j]);
		}
	}
}
