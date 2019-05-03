#I pledge my honor that I have abided by the Stevens Honor System - atartagl

all: cs392_echoserver cs392_echoclient

cs392_echoserver: cs392_echoserver.o cs392_log.o
	gcc -o cs392_echoserver cs392_log.o cs392_echoserver.o 
	
cs392_echoclient: cs392_echoclient.o
	gcc -o cs392_echoclient cs392_echoclient.o

cs392_log.o: cs392_log.c
	gcc -o cs392_log.o -c -g cs392_log.c
		
cs392_echoserver.o: cs392_echoserver.c
	gcc -o cs392_echoserver.o -c -g cs392_echoserver.c

cs392_echoclient.o: cs392_echoclient.c
	gcc -o cs392_echoclient.o -c -g cs392_echoclient.c

clean:
	rm -rf *.o cs392_echoclient cs392_echoserver