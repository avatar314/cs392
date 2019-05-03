//I pledge my honor that I have abided by the Stevens Honor System - atartagl

#include "cs392_signal.h"

static void handler(int sig, siginfo_t *siginfo, void *context) {
	printf("Signal Recieved.\n");
}

int signalC() {
	struct sigaction act;
 
	memset (&act, '\0', sizeof(act));

	act.sa_sigaction = &handler;
 
	act.sa_flags = SA_SIGINFO;

    sigaction(SIGINT,&act,NULL);
	sigaction(SIGTSTP,&act,NULL);
} 

