#include <stdio.h>
#include <unistd.h> //u can use bash commands, also POSIX arguments rules getopt

int main(int argc, char * argv[]){

	//to parse commandline arguments, we use getopt()
	//getopt(int argc, char *argv[], char *optstring)
	//optstring = a string that summarizes the legimimate options program needs to recognize
	//getopt returns:
	//-1 if the end of options list is reached
	//positive value is the ascii val of the option itself
	//? for unknown options
	//for options requireing option argument, place ':' immediate after the option
	//? for missing option argumentsi
	//
	//getopt also allows us to work with few global variables to parse the arguments
	//1. optarg => option argument => stores the option argument of the immediate processed option
	//2. optind => option index => keeps track of the index position of arguments
	//3. opterr => option error => stores the errors from getopt
	//4. optopt => option option => stores the most recent processed option
	//
	// with : in front of the optstring, getopt returns ':' for missing option arguments
	int opt;
	while((opt=getopt(argc, argv, ":f:il")) != 1){
		switch(opt){
			case 'f':
				//behaviour of option f
				printf("The option is %c and the argument is %s \n", opt, optarg); break;
			case 'i':
				printf("%c \n", opt); break;
			case 'l'
				printf("%c \n", opt); break;
			case ':'
				printf("option %c missing option arguments", optopt); break;
			case '?'
				printf("unknown option: %c", optopt);
		}

		for(; optind < argc; optind++){
			printf("%s \n", argv[optind]);
		}
	}

	/*
	printf("%d \n", argc);

	while(argc > 0){
		argc--;
		printf("%s |n", argv[argc]);
	}

	return 0;*/
}
