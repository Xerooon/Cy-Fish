CY-Fish : main.o affichage.o init_game.o turns_and_moves.o play.o 
	gcc -o Cy-Fish main.o affichage.o init_game.o turns_and_moves.o play.o

main.o : main.c
	gcc -o main.o -c main.c

affichage.o : affichage.c
	gcc -o affichage.o -c affichage.c

init_game.o : init_game.c
	gcc -o init_game.o -c init_game.c

turns_and_moves.o : turns_and_moves.c
	gcc -o turns_and_moves.o -c turns_and_moves.c

play.o : play.c
	gcc -o play.o -c play.c