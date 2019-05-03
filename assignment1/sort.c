// I pledge my honor that I have abided by the Stevens Honor System
#include "sort.h"
#include <stdbool.h>


void bubble_sort(int a[], int n) { //using bubble sort, sorts the integers in txt file
   int i = 0, j = 0, tmp;
   for (i = 0; i < n; i++) {   // loop n times - 1 per element
       for (j = 0; j < n - i - 1; j++) { // last i elements are sorted already            
            if (a[j] > a[j + 1]) {  // swop if order is broken
               tmp = a[j];
               a[j] = a[j + 1];
               a[j + 1] = tmp;
           }
       }
   }
}

int sort(FILE *file, FILE *file2) { //
	int max = 20;
	char *data = malloc(11);
	if(!data) {
		perror("Malloc Error");
		exit(1);
	}
	int *array = (int *)malloc(sizeof(int)*max);
	int counter = 0;
	while(fgets(data,11,file)) {
		if (counter > max) { //changes size of the array 
			max = max *2; 
			array = (int *)realloc(array,sizeof(int) * max);
		}
		int convert;
		convert = atoi(data);
		array[counter] = convert;
		counter++;
	}
	bubble_sort(array, counter); //sorts within the array
		
	for(int i = 0; i < counter; i++){
		fwrite(&array[i], sizeof(int), 1, file2); //writes to file2
		fputc('\n', file2);
	}
	free(data);
}

int main (int argc, char ** argv) {
	if (argc > 3 || argc < 3) { // sees if arguements are correct 
		fprintf(stderr,"Invalid number of arguements.");
		exit(1);
	}
	FILE *file = fopen(argv[1], "r");
	if (file == NULL) {
		perror("Cannot open file due to error");
		exit(1);
	}
	FILE *file2 = fopen(argv[2], "w");
	if (file2 == NULL) {
		perror("Cannot open file due to error");
		exit(1);
	}
	sort(file, file2);
	fclose(file); //closes files
	fclose(file2);
}