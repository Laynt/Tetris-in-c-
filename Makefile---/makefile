all: game

display.o: display.c display.h
	gcc -c display.c -o display.o
    
shape.o: shape.c shape.h
	gcc -c shape.c -o shape.o

ingame.o: ingame.c ingame.h
	gcc -c ingame.c -o ingame.o
    
main.o: main.c display.h shape.h ingame.h
	gcc -c main.c -o main.o

game: main.o display.o shape.o ingame.o
	gcc main.o display.o shape.o ingame.o -o game

