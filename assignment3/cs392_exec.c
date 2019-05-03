//I pledge my honor that I have abided by the Stevens Honor System - atartagl

#include "cs392_exec.h"

int argc;
void exec(char *argv[]){
	pid_t pid;
	int status;
	if((pid = fork()) < 0){
		//create fork
		printf("error forking\n");
		for(int i=0; i<argc; i++){
                	free(argv[i]);
		}
		free(argv);
		
		exit(1);
	}else if(pid == 0){
		//child
		if(execvp(argv[0], argv) < 0){
			printf("error executing\n");
			for(int i=0; i<argc; i++){
              		  	free(argv[i]);
			}
			free(argv);
			exit(1);
		}
		for(int i=0; i<argc; i++){
                	free(argv[i]);
		}
		free(argv);
	}else{
		//parent
		while(wait(&status) != pid);
	}	
}