#include "init_game.h"

// Function to determine the number of players
int nbrPlayers() {
    int n;  // Variable to store the number of players
    do {
        printf("Enter the number of players (between 2 and 6): \n");  // Prompt the user to enter the number of players
        if (scanf("%d", &n) != 1) {  // Check input, ensure it's a number
            printf("Invalid input. ");  
            while (getchar() != '\n');  // Clear input buffer to discard incorrect inputs
            continue;  // Continue the loop
        }
        if (n < 2 || n > 6) {  // Check if the number of players is within valid range
            printf("Invalid input. ");
        }
    } while (n < 2 || n > 6);  // Repeat until the number of players is between 2 and 6

return n;  // Return the valid number of players
}

// Function to enter the names of the players
void playersName(Player playerList[], int nbrPlayer) {
    while (getchar() != '\n');  // Clear input buffer
    for (int i = 0; i < nbrPlayer; i++) {  // Loop for each player
        do {
            printf("Enter the name of Player %d (max %d characters): \n", i + 1, SIZE - 1);  // Prompt for player's name
            fgets(playerList[i].name, 100, stdin);  // Read player's name
            playerList[i].name[strcspn(playerList[i].name, "\n")] = '\0';  // Remove newline character
            if (strlen(playerList[i].name) >= SIZE){  // Check if name exceeds character limit
                printf("Invalid input. ");
                while (getchar() != '\n');  // Clear input buffer
                continue;  // Restart loop to re-enter name
            }
        } while (strlen(playerList[i].name) >= SIZE);  // Repeat until name is within character limit
    }
}

// Function to distribute penguins to players based on the number of players
void givePenguin(Player playerList[], int nbrPlayer) {
    for (int i = 0; i < nbrPlayer; i++) {  // Loop through each player
        switch(nbrPlayer) {  // Switch case based on the number of players
            case 2:
                playerList[i].nbrPenguin = 4;  // Assign 4 penguins to each player if there are 2 players

            break;

            case 3:
                playerList[i].nbrPenguin = 3;  // Assign 3 penguins to each player if there are 3 players;
                
            break;

            case 4:

                playerList[i].nbrPenguin = 2;  // Assign 2 penguins to each player if there are 4 players

            break;

            case 5:
                playerList[i].nbrPenguin = 2;  // Assign 2 penguins to each player if there are 5 players
            break;

            case 6:
                playerList[i].nbrPenguin = 2;  // Assign 2 penguins to each player if there are 6 players
            break;

            default:
                printf("Error assigning penguins\n");  // Display error message if the number of players is not handled
                exit(1);
        }
        playerList[i].penguin = (Penguin*)malloc(playerList[i].nbrPenguin * sizeof(Penguin));
        if (playerList[i].penguin == NULL) {
            printf("Error while trying allocate memory");
            exit(1);
        }
    }
}


// Function to set the score of each player to zero
void setZero(Player playerList[], int nbrPlayers) {
    for(int i = 0; i < nbrPlayers; i++) {  // Loop through each player
        playerList[i].score = 0;  // Set the score of the current player to zero
    }
}


// Function to assign points to each hexagon on the grid
void setValue(Hexagon grid[L][C]) {
    int tab[2] = {-1, 1}; // Array to store possible point values
    int tab3[4] = {1, 1, 1, 3};

    for (int i = 0; i < C; i++) { // Loop through columns of the grid
        for(int j = 0; j < L; j++) { // Loop through rows of the grid
            grid[i][j].stackOfFish = rand() % 3 + 1; // Assign a random number of fish to the hexagon (between 1 and 3)

            switch(grid[i][j].stackOfFish) { // Switch case based on the number of fish
                case 1: // If there is 1 fish
                    grid[i][j].value = 1; // Assign a random point value (-1 or 1)
                break;

                case 2: // If there are 2 fish
                    grid[i][j].value = tab[rand() % 2] + 1; // Assign a random point value (-1 or 1) by summing two random values from the array
                break;

                case 3: // If there are 3 fish
                        grid[i][j].value = tab3[rand() % 4];// Assign a random point value (-1 or 1) by summing three random values from the array
                break;

                default:
                    printf("Error in switch case \n"); // Display error message if the switch case is not handled
                    exit(1);
            }
            grid[i][j].status = 1; // Set the status of the hexagon to 1 (indicating it's playable)
        }
    }
}


// Function to check if there is enough place on the grid for the players penguins
int enoughSpace(Hexagon grid[L][C], int nbrJoueur){
    int count = 0; // Variable to count the number of hexagons with 1 fish
    int nbrP = nbrJoueur * 4; // Calculate the total number of penguins for all players

    // Loop through each hexagon in the grid
    for(int i = 0; i < L; i++) {
        for(int j = 0; j < C; j++) {
            if(grid[i][j].stackOfFish == 1) {
                count++; // Increment the count if the hexagon has 1 fish
            }
        }
    }    

    if(count <= nbrP) { // If the count is less than or equal to the total number of penguins
        // Not enough place, regenerate the grid and return 0
        setValue(grid); // Regenerate the grid with new fish positions and point values
        return 0;
    }  
    else {
        // Enough place, return 1
        return 1;  
    }
}

// Function to place penguins on the grid
void placePenguin(Hexagon grid[L][C], int nbrPlayer, Player playerList[]) {
    int i, j;  // Declare variables for row and column indices
    int test = enoughSpace(grid, nbrPlayer);  // Check if there is enough space for all players to place their penguins

    // Loop until there is enough space for all players to place their penguins
    while (test != 1) {
        test = enoughSpace(grid, nbrPlayer);  // Recheck the space availability
    }

    // Loop through each player
    for (int k = 0; k < nbrPlayer; k++) {
        // Loop through each penguin for the current player
        for (int t = 0; t < playerList[k].nbrPenguin; t++) {
            int placed = 0;  // Flag to check if the penguin has been placed
            // Loop until the current penguin is placed
            while (!placed) {
                i = rand() % C;  // Generate a random column index
                j = rand() % L;  // Generate a random row index
                // Check if the hexagon has exactly one fish and is available (status == 1)
                if (grid[i][j].stackOfFish == 1 && grid[i][j].status == 1) {
                    grid[i][j].status = 0;  // Mark the hexagon as occupied
                    playerList[k].penguin[t].x = i;  // Set the x-coordinate of the penguin
                    playerList[k].penguin[t].y = j;  // Set the y-coordinate of the penguin
                    placed = 1;  // Mark the penguin as placed
                }
            }
        }
    }
}

int defWinner(Player playerList[], int nbrPlayer) {
    int maxScore = -1; // Initialise maxScore à -1 pour s'assurer que tout score de joueur sera plus élevé initialement.
    int winner = -1;   // Initialise winner à -1 pour gérer le cas où il n'y aurait pas de joueurs dans la liste.

    for (int n = 0; n < nbrPlayer; n++) { // Parcourt chaque joueur dans la liste.
        if (playerList[n].score > maxScore) { // Vérifie si le score du joueur actuel est supérieur à maxScore.
            maxScore = playerList[n].score; // Met à jour maxScore avec le score du joueur actuel.
            winner = n; // Met à jour winner avec l'indice du joueur actuel.
        }
    }
    return winner; // Retourne l'indice du joueur ayant le score le plus élevé.
}