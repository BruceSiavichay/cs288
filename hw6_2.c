#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char * argv[]){
	int opt;
	//overrides
	opterr = 0;
	while((opt=getopt(argc, argv, ":cduf:s")) != -1){
		switch(opt){
			case 'c':
			case 'd':
			case 'u':
				printf("Option %c is present \n", opt); break;
			case 'f':
				printf("Fields: %s\n", optarg); break;
			case ':':
				printf("Option %c is missing a value \n", optopt); break;
			case 's':
				int remaining = argc - optind;

        			if(remaining == 3){
                			for(int i = 0; i < 3; i++){
                        			printf("argument: %s \n", argv[optind]);
						optind++;
                		}
        			}else{
                			printf("Invalid number of arguments for s");
					optind = argc;
        			} break;
			case '?':
				printf("Unknown option %c \n", optopt); break;
		}
	}

	return 0;
}

