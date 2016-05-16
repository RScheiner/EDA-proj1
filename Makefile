### Makefile ###

all: projeto

projeto: lista.o matriz.o main.o
	gcc main.o matriz.o lista.o -lm -o projeto.exe
	
main.o: main.c
	gcc -c main.c

matriz.o: matriz.c
	gcc -c matriz.c
	
lista.o: lista.c
	gcc -c lista.c
	
clean:
	rm -rf *.o projeto.exe

run:projeto
	./projeto.exe