//I pledge my honor that I have abided by the Stevens Honor System - atartagl

#include "cs392_log.h"
struct sockaddr_in echoclient, echoserver;

void cs392_socket_log(int addr, int port){
	FILE *fp = fopen("cs392_socket.log", "a");
	if (fp == NULL) 
		printf("error");
	fprintf(fp, "%d %d\r\n", addr, port);
	fflush(fp);
	fclose(fp);
}