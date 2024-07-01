#include "affichage.h"

int isAnyMoveAvailable(int nbrPlayers, Player playerList[], Hexagon grid[L][C]);
void move(int choice, int turn, Player playerList[], int distance, int direction, Hexagon grid[L][C]);
int isMovePossible(int direction, int distance, int turn, int choice, Player playerList[], Hexagon grid[L][C]);
void choiceMove(int choice, Player playerList[], int turn, Hexagon grid[L][C]);
int isMoveAvailable(int turn, int choice, Player playerList[], Hexagon grid[L][C]);
void gameTurn(int nbrPlayers, Player playerList[], Hexagon grid[L][C]);
void rottenFish(int choice, int turn, Player playerList[], Hexagon grid[L][C]);
