#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define SIZE 21
#define L  9
#define C  9

typedef struct {
    int x;
    int y;
}Penguin;

typedef struct {
    char name[SIZE];
    int score;
    int nbrPenguin;
    Penguin* penguin;
}Player;

typedef struct{
    int stackOfFish; //nombre de poissons sur une case
    int status; //Le statut de la case (1 : case libre | 0 : casse occupée | -1 : casse cassée)
    int value; //valeur de la case (somme des poissons)
}Hexagon;

int nbrPlayers();
void playersName(Player playerList[], int nbrPlayer);
void givePenguin(Player playerList[], int nbrPlayer);
void setZero(Player playerList[], int nbrplayers);
void setValue(Hexagon grid[L][C]);
int enoughSpace(Hexagon grid[L][C], int nbrJoueur);
void placePenguin(Hexagon grid[L][C], int nbrPlayer, Player playerList[]);
int defWinner(Player playerList[], int nbrPlayer);
