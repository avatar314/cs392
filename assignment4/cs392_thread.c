// I pledge my honor that I have abided by the Stevens Honor System - atartagl

#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int item1_counter;
int item2_counter;
int item3_counter;
pthread_mutex_t lock;
pthread_t thid1, thid2, thid3;

void *cs392_thread_run (void *ret) {
	char* mem = malloc(7);
	FILE *fp = fopen((char *)ret, "r");
	
	while(fgets(mem, 7, fp) !='\0') {
		if(strcmp(mem, "+item1") == 0) {
			pthread_mutex_lock(&lock);
			item1_counter++;
			pthread_mutex_unlock(&lock);
		}
		else if (strcmp(mem, "-item1") == 0) {
			pthread_mutex_lock(&lock);
			item1_counter--;
			pthread_mutex_unlock(&lock);
		}
		else if(strcmp(mem, "+item2") == 0) {
			pthread_mutex_lock(&lock);
			item2_counter++;
			pthread_mutex_unlock(&lock);
		}
		else if(strcmp(mem, "-item2") == 0) {
			pthread_mutex_lock(&lock);
			item2_counter--;
			pthread_mutex_unlock(&lock);
		}
		else if(strcmp(mem, "+item3") == 0) {
			pthread_mutex_lock(&lock);
			item3_counter++;
			pthread_mutex_unlock(&lock);
		}
		else if(strcmp(mem, "-item3") == 0) {
			pthread_mutex_lock(&lock);
			item3_counter--;
			pthread_mutex_unlock(&lock);
		}
	}
	pthread_exit(NULL);
}

void* main(int argc, char **argv) {
	pthread_mutex_init(&lock, NULL); 
	
	pthread_create(&thid1, NULL, cs392_thread_run, argv[1]);
	pthread_create(&thid2, NULL, cs392_thread_run, argv[2]);
	pthread_create(&thid3, NULL, cs392_thread_run, argv[3]);
	
	pthread_join(thid1, NULL);
	pthread_join(thid2, NULL);
	pthread_join(thid3, NULL);

	pthread_mutex_destroy(&lock);
	printf("Thread 1 returns: %d\n", item1_counter);
	printf("Thread 2 returns: %d\n", item2_counter);
	printf("Thread 3 returns: %d\n", item3_counter);
	
	return 0;
}