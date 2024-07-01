#include "init_game.h"

void clearTerminal();
void waitForKeyPress();
void homeScreen();
void homeScreenWin();
void displayGrid(int l, int c, int nbrPlayers, Player playerList[]);
void displayStackOfFish(Hexagon grid[L][C]);
void displayValue(Hexagon grid[L][C]);
void displayStatus(Hexagon grid[L][C]);
void penguinsCoord(int nbrPlayer, Player playerList[]);
void moveCursor(int l, int c, int e);
void displayItem(Hexagon grid[L][C], Player playerList[], int nbrPlayer);
void displayAll(Hexagon grid[L][C], int nbrPlayers, Player playerList[]);
void displayRules();
void displaySpecifications();
void displayRequirements();
void endScreenWin(Player playerList[], int nbrplayers);
void endScreen(Player playerList[], int nbrplayers);
void end(Player playerList[], int nbrPlayer);
