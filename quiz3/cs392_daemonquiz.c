// I pledge my honor that I have abided by the Stevens Honor System - atartagl

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

int main(void) {
	
	pid_t pid = fork();
	
	if (pid < 0) {
		exit(EXIT_FAILURE);
	}
	
	if (pid > 0) {
		exit(EXIT_SUCCESS);
	}
	umask(0);
	
	pid_t sid = setsid();
	
	if (sid < 0) {
		exit(EXIT_FAILURE);
	}
	
	if((chdir("/tmp")) < 0) {
		exit(EXIT_FAILURE);
	}
	
	close(0);
	close(1);
	close(2);
	
	FILE* fp = fopen("cs392_daemon.log", "w+");
	
	while(1) {
		time_t t = time(NULL);
		struct tm *tm = localtime(&t);
		fprintf(fp, "%s", asctime(tm));
		fflush(fp);
		sleep(2);
	}
	fclose(fp);
	exit(EXIT_SUCCESS);
}