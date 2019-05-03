//I pledge my honor that I have abided by the Stevens Honor System - atartagl

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <time.h> 
#include "cs392_log.h"

#define MAXPENDING 5 
#define BUFFSIZE 32

int main (int argc, char *argv[]) {
	struct sockaddr_in echoclient, echoserver;
	char buffer[BUFFSIZE];
	int serversock, clientsock;
	
	socklen_t clientlen = sizeof(echoclient);
	serversock = socket(AF_INET, SOCK_STREAM, 0);
	if (serversock == -1){
		printf("Error creating socket \n");
		exit(0);
	}
	memset(&echoserver, 0, sizeof(echoserver)); 
	echoserver.sin_family = AF_INET; 
	echoserver.sin_addr.s_addr = htonl(INADDR_ANY); 
	echoserver.sin_port = htons(atoi(argv[1]));
	if (bind(serversock, (struct sockaddr *) &echoserver, sizeof(echoserver)) != 0) {
		printf("Error binding socket \n");
		exit(0);
	}
	if (listen(serversock, MAXPENDING) != 0){
		printf("Error listening for client \n");
		exit(0);
	}
	while(1) {
		clientsock = accept(serversock, (struct sockaddr *) &echoclient, &clientlen);
		memset(&buffer, 0, sizeof(buffer)); 
		cs392_socket_log(echoclient.sin_addr.s_addr, echoclient.sin_port); 
		recv(clientsock, buffer, BUFFSIZE, 0);
		send(clientsock, buffer, BUFFSIZE, 0);
		close(clientsock);
	}
	close(serversock);
	return 0;
}
