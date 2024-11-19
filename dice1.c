#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initialize random number generator
    srand(time(0));

    int dice1, dice2, total;

    // Game title
    printf("Welcome to the Dice Game!\n");

    // Ask the user to press Enter to roll the dice
    printf("Press Enter to roll the dice...\n");
    getchar();  // Wait for user input

    // Roll two dice
    dice1 = rand() % 6 + 1;  // Random number between 1 and 6 for dice1
    dice2 = rand() % 6 + 1;  // Random number between 1 and 6 for dice2

    // Calculate total of both dice
    total = dice1 + dice2;

    // Display the result
    printf("You rolled: %d and %d\n", dice1, dice2);
    printf("Total: %d\n", total);

    // Simple win condition (for fun)
    if (total == 7) {
        printf("Congratulations! You rolled a lucky 7!\n");
    } else {
        printf("Better luck next time!\n");
    }

    return 0;
}
