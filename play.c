#include "play.h"

// Fonction principale
void play() {
    srand(time(NULL)); // Seed initialization for random number generation using the current time

// initialization of the game
    int nbrPlayer = nbrPlayers(); // Declaration of the number of players
    Player playerList[nbrPlayer]; // Declaration of the player list
    Hexagon grid[L][C]; // Declaration of the grid
    

    playersName(playerList, nbrPlayer); // Declarion of player names
    givePenguin(playerList, nbrPlayer); // penguin attribution
    setZero(playerList, nbrPlayer); // score initialization
    setValue(grid); // initialization of fish on the grid
    placePenguin(grid, nbrPlayer, playerList); // placement of penguins on the grid
    printf("The game is correctly initialized\n");

    
// turns and movement of penguins management 
    
    displayAll(grid, nbrPlayer, playerList);

    while(isAnyMoveAvailable(nbrPlayer, playerList, grid) != 0) {
        printf("Start of the tour\n");
        gameTurn(nbrPlayer, playerList, grid);
        displayAll(grid, nbrPlayer, playerList);
    }

    endMenu(playerList, nbrPlayer);

    for (int i = 0; i < nbrPlayer; i++) {
        free(playerList[i].penguin);
    }
}

void endMenu(Player playerList[], int nbrPlayer) {
  int choice = 0; // Variable to store user's choice
    while(1) {
        // Loop until a valid choice (between 1 and 4) is entered
        end(playerList, nbrPlayer);
        do {
            printf("Enter your choice : \n"); // Prompt the user to enter a choice

            // Check if the input is a valid number
            if (scanf("%d", &choice) != 1) {
                printf("Invalid input. "); // Print an error message for invalid input
                while (getchar() != '\n'); // Clear the input buffer to discard incorrect inputs
                continue; // Continue the loop to prompt the user again
            }

            // Check if the choice is within the valid range
            if (choice < 1 || choice > 2) {
                printf("Invalid input. Choose valid option "); // Print an error message for out-of-range choice
                clearTerminal(); // Clear the terminal screen
            }
        } while (choice < 1 || choice > 2); // Repeat the loop if the choice is not between 1 and 4

        // Execute the corresponding action based on the user's choice
        switch (choice) {
            case 1:
                play();
                break;
            case 2:
                printf("Thanks for playing, see you soon :)");
                waitForKeyPress();
                exit(8);
                break;
            default:
                printf("Error with the choice"); // Print an error message if there is an unexpected issue with the choice
                exit(1); 
                break;
        }
    }
}


