// I pledge my honor that I have abided by the Stevens Honor System - atartagl

#include "cs392_log.h"

void logC(char* argv) {
	FILE *fp;
	fp = fopen("cs392_shell.log", "w");
	fprintf(fp, "%s\n", argv);
	fclose(fp);
}
