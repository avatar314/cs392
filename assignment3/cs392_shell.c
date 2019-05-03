// I pledge my honor that I have abided by the Stevens Honor System - atartagl

#include "cs392_exec.h"
#include "cs392_signal.h"
#include "cs392_log.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]){
  signalC(); //registers signals
  int n = 1024;
  char arr[1024];

  for(;;){
    memset(&arr, '\0', sizeof(arr)); //clearing input
    printf("cs392_shell $: "); 
    fgets(arr, sizeof(arr), stdin); //gets the input
    size_t size = strlen(arr);
    if(arr[size- 1] == '\n'){
      arr[size - 1] = '\0';
    }
    logC(arr);
    if(arr == "exit"){ //checks for exit command
      exit(0);
    }
    char* string = strtok(arr, " "); //gets the first section of string
    int x = 0;
    while(string != NULL){
      argv[x] = string;
      string = strtok(NULL, " ");
      x++;
    }
    argv[x] = NULL;
    exec(argv);
  }
  return 1;
}
