// I pledge my honor that I have abided by the Stevens Honor System - atartagl

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
 
static void handler (int sig, siginfo_t *siginfo, void *context) {
	printf ("\nSIGINT Recieved: %id, UID: %ld\n", (int)siginfo->si_pid, (long)siginfo->si_uid);
}
 
int main (int argc, char *argv[]) {
	struct sigaction act;
 
	memset (&act, '\0', sizeof(act));

	act.sa_sigaction = &handler;
 
	act.sa_flags = SA_SIGINFO | SA_RESETHAND;

	if (sigaction(SIGINT, &act, NULL) < 0) {
		perror ("sigaction");
		return 1;
	}
 
	while(1) {
		sleep (1);
		printf("Hellow\n");
	}
}