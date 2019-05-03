//I pledge my honor that I have abided by the Stevens Honor System - atartagl

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>

#define BUFFSIZE 32

int sock;
struct sockaddr_in echoserver;

int main(int argc, char *argv[]) {

	char buffer[BUFFSIZE];
	unsigned int echolen;
	int received = 0;
	fgets(buffer, BUFFSIZE, stdin);
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == -1) {
    	printf("Error creating socket \n");
    	exit(0);
	}
	memset(&echoserver, 0, sizeof(echoserver)); /* Clear struct */
	echoserver.sin_family = AF_INET; /* Internet/IP */
	echoserver.sin_addr.s_addr = inet_addr(argv[1]); /* IP address */
	echoserver.sin_port = htons(atoi(argv[2])); /* server port */
	if (connect(sock, (struct sockaddr *) &echoserver, sizeof(echoserver)) != 0) {
		printf("Error connecting to server\n");
	}
	echolen = strlen(buffer);
	write(sock, buffer, echolen);
	read(sock, buffer, echolen);
	printf("Server says: %s", buffer);
	close(sock);
	return 0;
}
