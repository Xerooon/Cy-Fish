#include "affichage.h"

// Function to clear the terminal screen
void clearTerminal() {
    // If compiling for Windows
    #ifdef _WIN32
    system("cls"); // Clear the terminal using cls command
    // If compiling for non-Windows systems
    #else
    system("clear"); // Clear the terminal using clear command
    #endif
}

void waitForKeyPress() {
    printf("\nPress ENTER to continue...");
    getchar(); // Capture the newline left in the buffer
    getchar(); // Wait for the user to press a key
}

// Function to display the home screen
void homeScreen() {
    clearTerminal();
    printf("\033[96m");
    printf("                                                                                                                    . --- .              \n");
    printf("       o                 o                                                                                         /        \\           \n");
    printf("                  o                                                                                               |  O  _  O |           \n");
    printf("         o   ______      o                                                                                        |  ./   \\. |          \n");
    printf("           _/  (   \\_                                                                                             /  `-._.-'  \\        \n");
    printf(" _       _/  (       \\_  O              ██████╗██╗   ██╗    ███████╗██╗███████╗██╗  ██╗                        .' /         \\ `.       \n");
    printf("| \\_   _/  (   (    0  \\               ██╔════╝╚██╗ ██╔╝    ██╔════╝██║██╔════╝██║  ██║                    .-~.-~/           \\~-.~-.  \n");
    printf("|== \\_/  (   (          |              ██║      ╚████╔╝     █████╗  ██║███████╗███████║                .-~ ~    |             |    ~ ~-.\n");
    printf("|=== _ (   (   (        |              ██║       ╚██╔╝      ██╔══╝  ██║╚════██║██╔══██║                `- .     |             |     . -' \n");
    printf("|==_/ \\_ (   (          |              ╚██████╗   ██║       ██║     ██║███████║██║  ██║                     ~ - |             | - ~     \n");
    printf("|_/     \\_ (   (    \\__/                ╚═════╝   ╚═╝       ╚═╝     ╚═╝╚══════╝╚═╝  ╚═╝                         |             |        \n");
    printf("          \\_ (      _/                                                                                          \\             /        \n");
    printf("            |  |___/                                                                                          ___\\           /___       \n");
    printf("           /__/                                                                                               ~;_  >- . . -<  _i~        \n");
    printf("                                ______________________________________________________________                   `'         `'           \n");
    printf("                                               Created by !Xerooon & Nicotine                                                            \n");
    printf("                                                                                                                                         \n");
    printf("                                    [1] : Rules                       [3] : Requirements                                                 \n");
    printf("                                    [2] : Specifications              [4] : Play !                                                       \n");
    printf("\033[97m\n");
}

void homeScreenWin() {
    clearTerminal();
    printf("\033[96m");
    printf("                                                                                                                    . --- .              \n");
    printf("       o                 o                                                                                         /        \\           \n");
    printf("                  o                                                                                               |  O  _  O |           \n");
    printf("         o   ______      o                                                                                        |  ./   \\. |          \n");
    printf("           _/  (   \\_                                                                                             /  `-._.-' \\        \n");
    printf(" _       _/  (       \\_  O         ______  ____    ____    _______  __       _______. __    __                 .' /          \\ `.       \n");
    printf("| \\_   _/  (   (    0  \\          /      | \\  \\   /   /   |   ____||  |     /       ||  |  |  |            .-~.-~/            \\~-.~-.  \n");
    printf("|== \\_/  (   (          |        |  ,----' \\    \\/   /    |  |__   |  |    |   (----`|  |__|  |        .-~ ~    |             |    ~ ~-.\n");
    printf("|=== _ (   (   (        |        |  |       \\_     _/     |   __|  |  |     \\   \\    |   __   |        `- .     |             |     . -' \n");
    printf("|==_/ \\_ (   (          |        |  `----.    |   |       |  |     |  | .----)   |   |  |  |  |             ~ - |             | - ~     \n");
    printf("|_/     \\_ (   (    \\__/          \\______|     |__|       |__|     |__| |_______/    |__|  |__|                 |             |        \n");
    printf("          \\_ (      _/                                                                                          \\             /        \n");
    printf("            |  |___/                                                                                          ___\\           /___       \n");
    printf("           /__/                                                                                               ~;_  >- . . -<  _i~        \n");
    printf("                                ______________________________________________________________                   `'         `'           \n");
    printf("                                               Created by !Xerooon & Nicotine                                                            \n");
    printf("                                                                                                                                         \n");
    printf("                                    [1] : Rules                       [3] : Requirements                                                 \n");
    printf("                                    [2] : Specifications              [4] : Play !                                                       \n");
    printf("\033[97m\n");
}

// Function to display the game board
void displayGrid(int l, int c, int nbrPlayers, Player playerList[]) {
     // Set text color to cyan
    printf("\033[96m");
    int car;

    // Adjust the dimensions for display
    l = l - 1;
    c = (c + 1) / 2;

    
    // First row of hexagons
    for (int i = 0; i < c - 1; i++) {
        printf("  ____      ");
    }
        printf("  ____\n");
    for (int i = 0; i < c - 1; i++) {
        printf(" /    \\     ");
    }
        printf(" /    \\\n");
    for (int i = 0; i < c - 1; i++) {
        printf("/      \\____");
    }
        printf("/      \\\n");
    for (int i = 0; i < c - 1; i++) {
        printf("\\      /    ");
    }
        printf("\\      /\n");
    for (int i = 0; i < c - 1; i++) {
        printf(" \\____/     ");
    }
        printf(" \\____/\n");

    // Middle rows of hexagons
    for (int i = 0; i < l; i++) {
        for (int i = 0; i <c - 1; i++) {
            printf(" /    \\     ");
        }
        printf(" /    \\\n");
        for (int i = 0; i <c - 1; i++) {
            printf("/      \\____");
        }
        printf("/      \\\n");
        for (int i = 0; i <c - 1; i++) {
            printf("\\      /    ");
        }
        printf("\\      /\n");
        for (int i = 0; i <c - 1 ; i++) {
            printf(" \\____/     ");
        }
        printf(" \\____/\n");
    }

    //Dernière ligne
    for (int i = 0; i < 3; i++) {
        if (i == 0) {
            printf("      \\      /");
        } 
        else {
            printf("    \\      /");
        }
    }
    printf("    \\      /\n");
    for (int i = 0; i < 3 ; i++) {
        if (i == 0) {
            printf("       \\____/     ");
        } 
        else {
            printf(" \\____/     ");
        }
    }
    printf(" \\____/\n");
    // Reset text color to default
    printf("\033[97m"); 
    printf("\n");

    // Display player information
    for(int u = 0; u < nbrPlayers; u++) {
        // Print player number and name
        printf("Player : %d | Name : %s ", u + 1, playerList[u].name);
        // Get the length of the player's name
        car = strlen(playerList[u].name);
        // Print spaces to align the output
        for(int t = 0; t < (SIZE - 1) - car; t++) {
            printf(" ");
        }
        // Print player's score
        printf("| Score : %d |", playerList[u].score);
        // Print each penguin's coordinates for the current player
        for (int g = 0; g < playerList[u].nbrPenguin; g++) {
            printf(" Penguins : %d : (%d, %d) |", g + 1, playerList[u].penguin[g].x + 1, playerList[u].penguin[g].y + 1);
        }
        printf("\n");
    }
}

// Function to display the stack of fish for each Hexagon in the grid
void displayStackOfFish(Hexagon grid[L][C]) {
    // Loop through each column of the grid
    for (int i = 0; i < C; i++){
        // Loop through each row of the grid
        for(int j = 0; j < L; j++){
            // Print the number of fish on the current hexagon
            printf("%d ", grid[i][j].stackOfFish);
        }
        // Print a newline character after each row
        printf("\n");
    }
}

// Function to display the value of each hexagon in the grid
void displayValue(Hexagon grid[L][C]) {
    // Loop through each column of the grid
    for (int i = 0; i < C; i++){
        // Loop through each row of the grid
        for(int j = 0; j < L; j++){
            // Print the value of the current hexagon
            printf("%d ", grid[i][j].value);
        }
        // Print a newline character after each row
        printf("\n");
    }
}

// Function to display the status of each hexagon in the grid
void displayStatus(Hexagon grid[L][C]) {
    // Loop through each column of the grid
    for (int i = 0; i < C; i++){
        // Loop through each row of the grid
        for(int j = 0; j < L; j++){
            // Print the status of the current hexagon
            printf("%d ", grid[i][j].status);
        }
        // Print a newline character after each row
        printf("\n");
    }
}

// Function to display the coordinates of all penguins for each player
void penguinsCoord(int nbrPlayer, Player playerList[]) {
    // Loop through each player
    for(int i = 0; i < nbrPlayer; i++) {
        // Loop through each penguin of the current player
        for(int j = 0; j < playerList[i].nbrPenguin; j++){
            // Print the coordinates of the current penguin
            printf("(%d, %d)", playerList[i].penguin[j].x, playerList[i].penguin[j].y);
        }
    }
}
// Function to move the cursor in the terminal
void moveCursor(int l, int c, int e) {
    // e = 1 : penguin | 2 : broken tile
    int row, col;  // Declare variables to hold the calculated row and column values
    int startROW = 3;  // Initial row offset value
    int startCOL = 2;  // Initial column offset value
    int rowIncrement = 4;  // Row increment per cell
    int colIncrement = 6;  // Column increment per cell

    // Check if the column index is odd
    if (c % 2 != 0) {
        // Check if the entity is a penguin
        if (e == 1) {
            startROW = 6;  // Set starting row offset for penguin in odd columns
            startCOL = 2;  // Set starting column offset for penguin in odd columns
        }
        // Check if the entity is a broken tile
        else if (e == 2) {
            startROW = 6;  // Set starting row offset for broken tile in odd columns
            startCOL = 5;  // Set starting column offset for broken tile in odd columns
        }
        // Default case for other entities in odd columns
        else {
            startROW = 5;  // Set starting row offset for other entities in odd columns
            startCOL = 2;  // Set starting column offset for other entities in odd columns
        }
    }
    // Column index is even
    else {
        // Check if the entity is a penguin
        if (e == 1) {
            startROW = 4;  // Set starting row offset for penguin in even columns
            startCOL = 2;  // Set starting column offset for penguin in even columns
        }
        // Check if the entity is a broken tile
        else if (e == 2) {
            startROW = 4;  // Set starting row offset for broken tile in even columns
            startCOL = 5;  // Set starting column offset for broken tile in even columns
        }
        // Default case for other entities in even columns
        else {
            startROW = 3;  // Set starting row offset for other entities in even columns
            startCOL = 2;  // Set starting column offset for other entities in even columns
        }
    }

    // Calculate the final row position
    row = startROW + l * rowIncrement;
    // Calculate the final column position
    col = startCOL + c * colIncrement;

    // Move the cursor to the calculated position using ANSI escape codes
    printf("\033[%d;%dH", row, col);
}

// Function to display items (fish and penguins) on the grid
void displayItem(Hexagon grid[L][C], Player playerList[], int nbrPlayer) {
    // Loop through each row of the grid
    for (int i = 0; i < L; i++){
        // Loop through each column of the grid
        for(int j = 0; j < C; j++){
            // If there are fish on the current hexagon
            if(grid[i][j].stackOfFish != 0) {
                // Move the cursor to the current position for displaying fish
                moveCursor(i, j, 0);
                // Loop through the stack of fish
                for(int u = 0; u < grid[i][j].stackOfFish; u++) {
                    // If compiling for Windows
                    #ifdef _WIN32
                    printf("\033[92m@"); // Print a fish symbol in green color
                    // If compiling for non-Windows systems
                    #else
                    printf("🐟"); // Print a fish emoji
                    #endif
                } 
            }
            // If the hexagon has a penguin on it (status is 0)
            if(grid[j][i].status == 0) {
                // Move the cursor to the current position for displaying the penguin
                moveCursor(j, i, 1);
                // If compiling for Windows
                #ifdef _WIN32
                printf("\033[95mP("); // Print a penguin symbol in magenta color
                for(int k = 0; k < nbrPlayer; k++){
                    for(int l = 0; l < playerList[k].nbrPenguin; l++){
                        if(playerList[k].penguin[l].x == j && playerList[k].penguin[l].y == i){
                            printf("%d.%d)",k+1,l+1);
                        }
                    }
                }
                // If compiling for non-Windows systems
                #else
                printf("🐧"); // Print a penguin emoji
                for(int k = 0; k < nbrPlayer; k++){
                    for(int l = 0; l < playerList[k].nbrPenguin; l++){
                        if(playerList[k].penguin[l].x == j && playerList[k].penguin[l].y == i){
                            printf("%d.%d)",k+1,l+1);
                        }
                    }
                }
                #endif
            }
            // If the hexagon is marked as unplayable (status is -1)
            if(grid[i][j].status == -1) {
                // Move the cursor to the current position for displaying the unplayable mark
                moveCursor(i, j, 2);
                // If compiling for Windows
                #ifdef _WIN32
                printf("\033[91mX"); // Print an X symbol in red color
                // If compiling for non-Windows systems
                #else
                printf("❌"); // Print a cross mark emoji
                #endif
            }
        }
    } 
}

void displayAll(Hexagon grid[L][C], int nbrPlayers, Player playerList[]) {
    // Clear the terminal screen to start with a fresh display
    clearTerminal();
    
    // Display the grid with the given dimensions (L x C), number of players, and the informations of players
    displayGrid(L, C, nbrPlayers, playerList);
    
    // Display items on the grid
    displayItem(grid, playerList, nbrPlayers);
    
    // Move the cursor to the specified position (row 13, column 0) with entity type 4 (not specified in given context)
    moveCursor(11, 0, 4);
    
    // Print a new line at the end to ensure the cursor is positioned properly after the function executes
    printf("\033[97m"); 
    printf("\n");
}

void displayRules() {
    char ch;
    FILE *file = fopen("rules.txt", "r"); // Open the file in read mode
    if (file == NULL) {
        perror("Unable to open rules.txt"); // Print error message if the file cannot be opened
        exit(404); // Exit the program with an error code
    }

    while ((ch = fgetc(file)) != EOF) {
        putchar(ch); // Print each character from the file to the console
    }

    fclose(file); // Close the file
}

void displaySpecifications() {
    char ch;
    FILE *file = fopen("specifications.txt", "r"); // Open the file in read mode
    if (file == NULL) {
        perror("Unable to open rules.txt"); // Print error message if the file cannot be opened
        exit(404); // Exit the program with an error code
    }

    while ((ch = fgetc(file)) != EOF) {
        putchar(ch); // Print each character from the file to the console
    }

    fclose(file); // Close the file
}

void displayRequirements() {
    char ch;
    FILE *file = fopen("README.md", "r"); // Open the file in read mode
    if (file == NULL) {
        perror("Unable to open rules.txt"); // Print error message if the file cannot be opened
        exit(404); // Exit the program with an error code
    }

    while ((ch = fgetc(file)) != EOF) {
        putchar(ch); // Print each character from the file to the console
    }

    fclose(file); // Close the file
}

void endScreenWin(Player playerList[], int nbrPlayer) {
    int car;
    int winner = 0;
    clearTerminal();
    printf("\033[96m");
    printf("                                                                                                                    . --- .                \n");
    printf("       o                 o                                                                                         /        \\             \n");
    printf("                  o                                                                                               |  O  _  O |             \n");
    printf("         o   ______      o                              ____  ____   _                                            |  ./   \\. |            \n");
    printf("           _/  (   \\_                                  / ___|/ ___| | |                                           /  `-._.-' \\           \n");
    printf(" _       _/  (       \\_  O                            | |  _| |  _  | |                                       .' /           \\ `.        \n");
    printf("| \\_   _/  (   (    0  \\                              | |_| | |_| | |_|                                   .-~.-~/             \\~-.~-.   \n");
    printf("|== \\_/  (   (          |                              \\____|\\____| (_)                                .-~ ~    |             |    ~ ~-.\n");
    printf("|=== _ (   (   (        |                                                                              `- .     |             |     . -'   \n");
    printf("|==_/ \\_ (   (          |                                                                                   ~ - |             | - ~       \n");
    printf("|_/     \\_ (   (    \\__/                         ------------------------                                       |             |          \n");
    printf("          \\_ (      _/                          ||                      ||                                      \\             /          \n");
    printf("            |  |___/                             ------------------------                                     ___\\           /___         \n");
    printf("           /__/                                                                                               ~;_  >- . . -<  _i~          \n");
    printf("                                ______________________________________________________________                   `'         `'             \n");
    printf("                                                      Was it fun ? x)                                                                      \n");
    printf("                                                                                                                                           \n");
    printf("                                    [1] : Play again !                [2] : Quit ...                                                       \n");
    printf("                                                                                                                                           \n");
    printf("                                                                                                                                           \n");
    printf("                                                        Scoreboard                                                                         \n");
    printf("                                                        ----------                                                                         \n");
    printf("                                             Players :              Score :                                                                \n");
    printf("                                                                                                                                           \n");
    winner = defWinner(playerList, nbrPlayer);
    for(int u = 0; u < nbrPlayer; u++) {
        printf("                                          ");
        printf("%d | %s ", u + 1, playerList[u].name);
        // Get the length of the player's name
        car = strlen(playerList[u].name);
        // Print spaces to align the output
        for(int t = 0; t < (SIZE - 1) - car; t++) {
            printf(" ");
        }
        // Print player's score
        printf("%d", playerList[u].score);
        // Print each penguin's coordinates for the current player
        printf("\n");
    }

    printf("\033[91m");
    printf("\033[%d;%dH", 12, 52);
    printf("%s", playerList[winner].name);

    moveCursor(7, 0, 4);
    printf("\033[97m\n");
}

void endScreen(Player playerList[], int nbrPlayer) {
    int car;
    int winner = 0;
    clearTerminal();
    printf("\033[96m");
    printf("                                                                                                                    . --- .              \n");
    printf("       o                 o                                                                                         /        \\           \n");
    printf("                  o                                                                                               |  O  _  O |           \n");
    printf("         o   ______      o                         ██████╗  ██████╗     ██╗                                       |  ./   \\. |          \n");
    printf("           _/  (   \\_                            ██╔════╝ ██╔════╝     ██║                                        /  `-._.-'  \\        \n");
    printf(" _       _/  (       \\_  O                       ██║  ███╗██║  ███╗    ██║                                     .' /         \\ `.       \n");
    printf("| \\_   _/  (   (    0  \\                        ██║   ██║██║   ██║    ╚═╝                                  .-~.-~/           \\~-.~-.  \n");
    printf("|== \\_/  (   (          |                        ╚██████╔╝╚██████╔╝    ██╗                             .-~ ~    |             |    ~ ~-.\n");
    printf("|=== _ (   (   (        |                          ╚═════╝  ╚═════╝     ╚═╝                            `- .     |             |     . -' \n");
    printf("|==_/ \\_ (   (          |                                                                                   ~ - |             | - ~     \n");
    printf("|_/     \\_ (   (    \\__/                        ╔══════════════════════╗                                        |             |        \n");
    printf("          \\_ (      _/                          ║║                      ║║                                      \\             /        \n");
    printf("            |  |___/                              ╚══════════════════════╝                                    ___\\           /___       \n");
    printf("           /__/                                                                                               ~;_  >- . . -<  _i~        \n");
    printf("                                ______________________________________________________________                   `'         `'           \n");
    printf("                                                      Was it fun ? x)                                                                    \n");
    printf("                                                                                                                                         \n");
    printf("                                    [1] : Play again !                [2] : Quit ...                                                     \n");
    printf("                                                                                                                                         \n");
    printf("                                                                                                                                         \n");
    printf("                                                        Scoreboard                                                                       \n");
    printf("                                                        ‾‾‾‾‾‾‾‾‾‾                                                                       \n");
    printf("                                             Players :              Score :                                                              \n");
    printf("                                                                                                                                         \n"); 
    winner = defWinner(playerList, nbrPlayer);    
    for(int u = 0; u < nbrPlayer; u++) {
        printf("                                          ");
        printf("%d | %s ", u + 1, playerList[u].name);
        // Get the length of the player's name
        car = strlen(playerList[u].name);
        // Print spaces to align the output
        for(int t = 0; t < (SIZE - 1) - car; t++) {
            printf(" ");
        }
        // Print player's score
        printf("%d", playerList[u].score);
        // Print each penguin's coordinates for the current player
        printf("\n");
    }

    printf("\033[91m");
    printf("\033[%d;%dH", 12, 55);
    printf("%s", playerList[winner].name);

    moveCursor(7, 0, 4);
    printf("\033[97m\n");
}

void end(Player playerList[], int nbrPlayer) {
    #ifdef _WIN32
    endScreenWin(playerList, nbrPlayer);
    #else
    endScreen(playerList, nbrPlayer);
    #endif
}

