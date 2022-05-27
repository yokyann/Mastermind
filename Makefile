all : main_mastermind

mastermind.o: mastermind.h mastermind.c
	gcc -c -o mastermind.o mastermind.c

main_mastermind.o: main_mastermind.c mastermind.h
	gcc -c -o main_mastermind.o main_mastermind.c

main_mastermind: main_mastermind.o mastermind.o
	gcc -o main_mastermind main_mastermind.o mastermind.o

clean :
	rm -f *.o main_mastermind