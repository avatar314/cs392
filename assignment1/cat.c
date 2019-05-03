//I pledge my honor that I have abided by the Stevens Honor System

#include <stdio.h>
#include <stdlib.h>

void cat (FILE *f) {
	char *str;
	//int size = ftell(file);
	str = malloc(20);
	
	if(!str){ //while string still has characters in it
		perror("String is empty");
		exit(1);
	}
	while(fread(str, 1, 20, f)){ //reads files with the total number of elements in string 
	    if(ferror(f)){
			break; 
		}
		printf(str);
	}
	free(str);
}


int main (int argc, char ** argv) {
	
	if (argc != 2){
		fprintf(stderr,"Invalid number of arguements.");
		exit(1);
	}
	FILE *file = fopen(argv[1], "r");
	if (file == NULL) {
		fprintf(stderr,"Cannot open file due to error.");
		exit(1);
	}
	
	cat(file);
	printf("\n");
	// fread(ptr, 1, size, file);
	fclose(file);
	return 0;
}