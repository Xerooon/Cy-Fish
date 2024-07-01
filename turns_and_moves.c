#include "turns_and_moves.h"

int isAnyMoveAvailable(int nbrPlayers, Player playerList[], Hexagon grid[L][C]) { 
    // Check if at least one move is available
    int possible = 0;
    for (int i = 0; i < nbrPlayers; i++) {
        for (int j = 0; j < playerList[i].nbrPenguin; j++) {
            
            possible += isMoveAvailable(i, j, playerList,grid);
        }
    }
    printf("Still %d movements possible\n", possible);
    return possible;
}

void move(int choice, int turn, Player playerList[], int distance, int direction, Hexagon grid[L][C]) { 
    // Make the move
    switch (direction) {
        case 1:
            playerList[turn].score += grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].value;
            grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].value = 0;
            grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].stackOfFish = 0;
            grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].status = -1;
            for (int i = 0; i < distance; i++) {
                playerList[turn].penguin[choice].x -= 1;
                grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].status = 0;
                playerList[turn].score += grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].value;
                rottenFish(choice, turn, playerList, grid);
                grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].value = 0;
                grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].stackOfFish = 0;
                grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].status = -1;
            }
            grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].status = 0;
            break;

        case 2:
            playerList[turn].score += grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].value;
            grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].value = 0;
            grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].stackOfFish = 0;
            grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].status = -1;
            for (int i = 0; i < distance; i++) {
                
                if (playerList[turn].penguin[choice].y % 2 == 0) {
                    playerList[turn].penguin[choice].y -= 1;
                    playerList[turn].penguin[choice].x -= 1;
                    grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].status = 0;
                    playerList[turn].score += grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].value;
                    rottenFish(choice, turn, playerList, grid);
                    grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].value = 0;
                    grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].stackOfFish = 0;
                    grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].status = -1;

                } else {
                    playerList[turn].penguin[choice].y -= 1;
                    grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].status = 0;
                    playerList[turn].score += grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].value;
                    rottenFish(choice, turn, playerList, grid);
                    grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].value = 0;
                    grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].stackOfFish = 0;
                    grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].status = -1;
                }
            }
            grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].status = 0;
            break;

        case 3:
            playerList[turn].score += grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].value;
            grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].value = 0;
            grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].stackOfFish = 0;
            grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].status = -1;
            for (int i = 0; i < distance; i++) {
                if (playerList[turn].penguin[choice].y % 2 == 0) {
                    playerList[turn].penguin[choice].y += 1;
                    playerList[turn].penguin[choice].x -= 1;
                    grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].status = 0;
                    playerList[turn].score += grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].value;
                    rottenFish(choice, turn, playerList, grid);
                    grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].value = 0;
                    grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].stackOfFish = 0;
                    grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].status = -1;
                } else {
                    playerList[turn].penguin[choice].y += 1;
                    grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].status = 0;
                    playerList[turn].score += grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].value;
                    rottenFish(choice, turn, playerList, grid);
                    grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].value = 0;
                    grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].stackOfFish = 0;
                    grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].status = -1;
                }
            }
            grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].status = 0;
            break;

        case 4:
            playerList[turn].score += grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].value;
            grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].value = 0;
            grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].stackOfFish = 0;
            grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].status = -1;
            for (int i = 0; i < distance; i++) {
                playerList[turn].penguin[choice].x += 1;
                grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].status = 0;
                playerList[turn].score += grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].value;
                rottenFish(choice, turn, playerList, grid);
                grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].value = 0;
                grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].stackOfFish = 0;
                grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].status = -1;
            }
            grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].status = 0;
            break;

        case 5:
        
            playerList[turn].score += grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].value;
            grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].value = 0;
            grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].stackOfFish = 0;
            grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].status = -1;
            for (int i = 0; i < distance; i++) {
                if (playerList[turn].penguin[choice].y % 2 == 0) {
                    playerList[turn].penguin[choice].y -= 1;
                    grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].status = 0;
                    playerList[turn].score += grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].value;
                    rottenFish(choice, turn, playerList, grid);
                grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].value = 0;
                grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].stackOfFish = 0;
                grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].status = -1;
                } else {
                    playerList[turn].penguin[choice].y -= 1;
                    playerList[turn].penguin[choice].x += 1;
                    grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].status = 0;
                    playerList[turn].score += grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].value;
                    rottenFish(choice, turn, playerList, grid);
                    grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].value = 0;
                    grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].stackOfFish = 0;
                    grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].status = -1;
                }
            }
            grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].status = 0;
            break;

        case 6:
            playerList[turn].score += grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].value;
            grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].value = 0;
            grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].stackOfFish = 0;
            grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].status = -1;
            for (int i = 0; i < distance; i++) {
                if (playerList[turn].penguin[choice].y % 2 == 0) {
                    playerList[turn].penguin[choice].y += 1;
                    grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].status = 0;
                    playerList[turn].score += grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].value;
                    rottenFish(choice, turn, playerList, grid);
                    grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].value = 0;
                    grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].stackOfFish = 0;
                    grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].status = -1;
                } else {
                    playerList[turn].penguin[choice].y += 1;
                    playerList[turn].penguin[choice].x += 1;
                    grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].status = 0;
                    playerList[turn].score += grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].value;
                    rottenFish(choice, turn, playerList, grid);
                    grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].value = 0;
                    grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].stackOfFish = 0;
                    grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].status = -1;
                }
            }
            grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].status = 0;
            break;

        default:
            printf("Erreur switch move\n");
            exit(1);
            break;
    }
}

int isMovePossible(int direction, int distance, int turn, int choice, Player playerList[], Hexagon grid[L][C]) { // check if the move is possible

    int py = playerList[turn].penguin[choice].y;
    int px = playerList[turn].penguin[choice].x;

    switch (direction) {
        case 1:
            for(int i = 0; i< distance; i++) {
                if(px -1 < 0){
                    printf("You go off the grid !\n");
                    return 1;
                }
                if(grid[px -1][py].status != 1){
                    printf("Obstacle on the way !\n");
                    return 1;
                }
                else{
                    px -= 1;
                }
            }
        return 2;
        break;

        case 2:
            for(int i = 0; i< distance; i++){
                if(py%2 == 0){
                    if(px -1 < 0 || py -1 < 0){
                        printf("You go off the grid !\n");
                        return 1;
                    }
                    if(grid[px - 1][py - 1].status != 1){
                        printf("Obstacle on the way !\n");
                        return 1;
                    }
                    else{
                        py -= 1;
                        px -= 1;
                    }
                }
                else{
                    if(py -1 < 0){
                        printf("You go off the grid !\n");
                        return 1;
                    }
                    if(grid[px][py - 1].status != 1 ){
                        printf("Obstacle on the way !\n");
                        return 1;
                    }
                    else{
                        py -= 1;
                    }
                }
            }
        return 2;
        break;

        case 3:
            for(int i = 0; i< distance; i++){
                if(py%2 == 0){
                    if(px -1 < 0 || py +1 > 8){
                        printf("You go off the grid !\n");
                        return 1;
                    }
                    if(grid[px - 1][py + 1].status != 1){
                        printf("Obstacle on the way !\n");
                        return 1;
                    }
                    else{
                        py += 1;
                        px -= 1;
                    }
                }
                else{
                    if(py +1 > 8){
                        printf("You go off the grid !\n");
                        return 1;
                    }
                    if(grid[px][py + 1].status != 1){
                        printf("Obstacle on the way !\n");
                        return 1;
                    }
                    else{
                        py += 1;
                    }
                }
            }
        return 2;
        break;

        case 4:
            for(int i = 0; i< distance; i++) {
                if(px +1 > 8){
                    printf("You go off the grid !\n");
                    return 1;
                }
                if(grid[px + 1][py].status != 1){
                    printf("Obstacle on the way !\n");
                    return 1;
                }
                else{
                    px += 1;
                }
            }
        return 2;
        break;

        case 5:
            for(int i = 0; i< distance; i++){
                if(py%2 == 0){
                    if(py -1 < 0){
                        printf("You go off the grid !\n");
                        return 1;
                    }
                    if(grid[px][py - 1].status != 1){
                        printf("Obstacle on the way !\n");
                        return 1;
                    }
                    else{
                        py -= 1;
                    }
                }
                else{
                    if(py -1 < 0 || px + 1 > 8){
                        printf("You go off the grid !\n");
                        return 1;
                    }
                    if(grid[px + 1][py - 1].status != 1){
                        printf("Obstacle on the way !\n");
                        return 1;
                    }
                    else{
                        py -= 1;
                        px += 1;
                    }
                }
            }
        return 2;
        break;

        case 6:
            for(int i = 0; i< distance; i++){
                if(py%2 == 0){
                    if(py +1 > 8){
                        printf("You go off the grid !\n");
                        return 1;
                    }
                    if(grid[px][py + 1].status != 1){
                        printf("Obstacle on the way !\n");
                        return 1;
                    }
                    else{
                        py += 1;
                    }
                }
                else{
                    if(py +1 > 8 || px + 1 > 8){
                        printf("You go off the grid !\n");
                        return 1;
                    }
                    if(grid[px + 1][py + 1].status != 1 ){
                        printf("Obstacle on the way !\n");
                        return 1;
                    }
                    else{
                        py += 1;
                        px += 1;
                    }
                }
            }
        return 2;
        break;

        default:
            return 1;
            printf("Error switch case isMovePossible\n");
        break;
    }
}

void choiceMove(int choice, Player playerList[], int turn, Hexagon grid[L][C]) { // Make the player choose the move

    int direction = 0;
    int distance = 0;

    do {
        printf("Choose direction : \n");
        printf("1 : Top\n2 : Top-Left\n3 : Top-Right\n4 : Bottom\n5 : Bottom-Left\n6 : Bottom-Right\n"); 
        if (scanf("%d", &direction) != 1) {  // Check input, ensure it's a number
            printf("Invalid input. ");  
            while (getchar() != '\n');  // Clear input buffer to discard incorrect inputs
            continue;  // Continue the loop
        }
        if (direction < 1 || direction > 6) { 
            printf("Invalid input. Choose valid option.");
        } 
    } while (direction < 1 || direction > 6); 
    
    do { 
        printf("Choose distance : \n");
        if (scanf("%d", &distance) != 1) {  // Check input, ensure it's a number
            printf("Invalid input. ");  
            while (getchar() != '\n');  // Clear input buffer to discard incorrect inputs
            continue;  // Continue the loop
        }
        if ( distance < 1 || distance > 8) { 
            printf("Invalid input. Choose valid option ");
        } 
    } while (distance < 1 || distance > 8);

    if( isMovePossible(direction, distance, turn, choice, playerList, grid) == 2 ) {
        move(choice, turn, playerList, distance, direction, grid);
    }
    else {
        printf("Invalid movement\n");
        choiceMove(choice, playerList, turn, grid);
    }
}

int isMoveAvailable(int turn, int choice, Player playerList[], Hexagon grid[L][C]) { // check if move is available for one penguin
    int possible = 0;
    int py = playerList[turn].penguin[choice].y;
    int px = playerList[turn].penguin[choice].x;

    for(int i = 1; i < 7; i++) {

        switch (i) {
            case 1: // check if upper move is available
                if(px -1 >= 0) {
                    if(grid[px - 1][py].status == 1) {
                        possible += 1;
                    }
                }

            break;

            case 2: // check if upper-left move is available
                if(py % 2 == 0){
                    if(py -1 >= 0 && px -1 >= 0) {
                        if(grid[px - 1][py - 1].status == 1) {
                            possible += 1;
                        }
                    }
                }
                else{
                    if(py -1 >= 0) {
                        if(grid[px][py - 1].status == 1) {
                            possible += 1;
                        }
                    }
                }
            break; 

            case 3: // check if upper-right move is available
                if(py % 2 == 0) {
                    if (py +1 <= 8 && px -1 >= 0){
                        if(grid[px - 1][py + 1].status == 1) {
                            possible += 1;
                        }
                    }
                }
                else{
                    if(py +1 <= 8) {
                        if(grid[px][py + 1].status == 1) {
                            possible += 1;
                        }
                    }    
                }
            break;
            
            case 4: // check if down move is available
                if(px +1 <= 8) {
                    if(grid[px + 1][py].status == 1) {
                        possible += 1;
                    }
                }
            break;

            case 5: // check if down-left move is available
                if(py % 2 == 0) {
                    if(py -1 >= 0){
                        if(grid[px][py - 1].status == 1){
                            possible += 1;
                        }
                    }
                }
                else{
                    if(py - 1 >= 0 && px  +1 <= 8){
                        if(grid[px + 1][py - 1].status == 1){
                        possible += 1;
                        }
                    }
                }
            break;

            case 6: // check if down-right move is available
                if(py % 2 == 0) {
                    if(py +1 <= 8){
                        if(grid[px][py + 1].status == 1){
                            possible += 1;
                        }
                    }
                }
                else{
                    if(py +1 <= 8 && px +1 <= 8){
                    
                        if(grid[px + 1][py + 1].status == 1){
                            possible += 1;
                        }
                    }
                }
            break;
            default:
                printf("Error isMoveAvailable");
                exit(1);
            break;
        }
    }
    return possible;
}

void gameTurn(int nbrPlayers, Player playerList[], Hexagon grid[L][C]) { // Play turns

    int mvP = 0;
    int choiceP = 0;
    int turn = 0;

    for(int i = 0; i < nbrPlayers; i++) {
        printf("Turn of player : %d\n", i+1);
        for(int j = 0; j < playerList[i].nbrPenguin; j++){
            mvP += isMoveAvailable(turn, j, playerList, grid);
        }

        if(mvP == 0){
            printf("Player %d has no possible movement \n",turn + 1);
            goto nextTurn;
        }
        mvP = 0;
        do { 
            printf("Choose a penguin that can move: \n");
            if (scanf("%d", &choiceP) != 1) {  // Check input, ensure it's a number
                printf("Invalid input. ");  
                while (getchar() != '\n');  // Clear input buffer to discard incorrect inputs
                continue;  // Continue the loop
            }
            if (choiceP - 1 < 0 || choiceP - 1 > playerList[i].nbrPenguin || isMoveAvailable(turn, choiceP - 1, playerList, grid) == 0) { 
                printf("Invalid input. Choose valid option ");
            } 
        } while (choiceP - 1 < 0 || choiceP - 1 > playerList[i].nbrPenguin || isMoveAvailable(turn, choiceP - 1, playerList, grid) == 0);
        choiceMove(choiceP - 1, playerList, turn, grid);
        displayAll(grid, nbrPlayers, playerList);
        nextTurn: printf("Next turn\n");
        turn += 1;
    }
}


void rottenFish(int choice, int turn, Player playerList[], Hexagon grid[L][C]) {

    switch (grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].stackOfFish) {

        case 1:
        break;

        case 2:
            if(grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].value < 2) {
                printf("\033[91mThe penguin ate a rotten fish");
            }
        break;

        case 3 :
            if(grid[playerList[turn].penguin[choice].x][playerList[turn].penguin[choice].y].value < 3) {
                printf("\033[91mThe penguin ate a rotten fish");
            }
        break;

        default:
            printf("Error switch case rottenFish()");
            exit(1);
        break;
    }
    printf("\033[97m");
}