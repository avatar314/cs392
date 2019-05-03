//I pledge my honor that I have abided by the Stevens Honor System - atartagl

#ifndef SIGNAL_H
#define SIGNAL_H
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>


static void handler(int sig, siginfo_t *siginfo, void *context);
int signalC(); 

#endif 