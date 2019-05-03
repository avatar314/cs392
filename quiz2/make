prog : main.o sum.o
	g++ -o my_prog main.o sum.o  	

sum.o : sum.c sum.h
	g++ -c sum.c
main.o : main.c sum.c sum.h
	g++ -c main.c
	
clean:
		rm *.o prog
