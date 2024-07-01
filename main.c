#include "play.h"

int main() {

    int choice = 0; // Variable to store user's choice

    while(1) {
        // Loop until a valid choice (between 1 and 4) is entered
        do {
            #ifdef _WIN32
                homeScreenWin(); // Display the home screen for windows
            #else 
                homeScreen(); // Display the home screen for other OS
            #endif

            printf("Enter your choice: \n"); // Prompt the user to enter a choice

            // Check if the input is a valid number
            if (scanf("%d", &choice) != 1) {
                printf("Invalid input. "); // Print an error message for invalid input
                while (getchar() != '\n'); // Clear the input buffer to discard incorrect inputs
                continue; // Continue the loop to prompt the user again
            }

            // Check if the choice is within the valid range
            if (choice < 1 || choice > 4) {
                printf("Invalid input. Choose valid option "); // Print an error message for out-of-range choice
                clearTerminal(); // Clear the terminal screen
            }
        } while (choice < 1 || choice > 4); // Repeat the loop if the choice is not between 1 and 4

        // Execute the corresponding action based on the user's choice
        switch (choice) {
            case 1:
                displayRules();
                waitForKeyPress();
                break;
            case 2:
                displaySpecifications();
                waitForKeyPress();
                break;
            case 3:
                displayRequirements();
                waitForKeyPress();
                break;
            case 4:
                play(); // Call the play function if choice is 4
                break;
            default:
                printf("Error with the choice"); // Print an error message if there is an unexpected issue with the choice
                exit(5); 
                break;
        }
    }

    return 0; // Return 0 to indicate successful execution
}