#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice() {
    return rand() % 6 + 1; 
}

int main() {
    int player1 = 0, player2 = 0; 
    int dice, currentPlayer = 1;
    srand(time(NULL)); 

    printf("Welcome to Snake and Ladder Game!\n");

    while (player1 < 100 && player2 < 100) {
        printf("\nPlayer %d's turn.\n", currentPlayer);

        
        dice = rollDice();
        printf("You rolled a %d.\n", dice);

    
        if (currentPlayer == 1) {
            player1 += dice;
        } else {
            player2 += dice;
        }


        if (player1 == 4) {
            player1 = 14;
            printf("Oops! You encountered a ladder, move to position 14.\n");
        } else if (player1 == 9) {
            player1 = 31;
            printf("Oops! You encountered a ladder, move to position 31.\n");
        } else if (player1 == 17) {
            player1 = 7;
            printf("Oh no! You encountered a snake, move back to position 7.\n");
        } else if (player1 == 20) {
            player1 = 38;
            printf("Oops! You encountered a ladder, move to position 38.\n");
        } else if (player1 == 28) {
            player1 = 84;
            printf("Oops! You encountered a ladder, move to position 84.\n");
        } else if (player1 == 40) {
            player1 = 59;
            printf("Oops! You encountered a ladder, move to position 59.\n");
        } else if (player1 == 51) {
            player1 = 67;
            printf("Oops! You encountered a ladder, move to position 67.\n");
        } else if (player1 == 54) {
            player1 = 34;
            printf("Oh no! You encountered a snake, move back to position 34.\n");
        } else if (player1 == 62) {
            player1 = 19;
            printf("Oh no! You encountered a snake, move back to position 19.\n");
        } else if (player1 == 63) {
            player1 = 81;
            printf("Oops! You encountered a ladder, move to position 81.\n");
        } else if (player1 == 64) {
            player1 = 60;
            printf("Oh no! You encountered a snake, move back to position 60.\n");
        } else if (player1 == 71) {
            player1 = 91;
            printf("Oops! You encountered a ladder, move to position 91.\n");
        } else if (player1 == 87) {
            player1 = 24;
            printf("Oh no! You encountered a snake, move back to position 24.\n");
        } else if (player1 == 93) {
            player1 = 73;
            printf("Oh no! You encountered a snake, move back to position 73.\n");
        } else if (player1 == 95) {
            player1 = 75;
            printf("Oh no! You encountered a snake, move back to position 75.\n");
        } else if (player1 == 99) {
            player1 = 78;
            printf("Oh no! You encountered a snake, move back to position 78.\n");
        }

        
        if (currentPlayer == 1 && player1 > 100) {
            player1 -= dice; 
        } else if (currentPlayer == 2 && player2 > 100) {
            player2 -= dice; 
        }

        
        printf("Player 1 is at position %d.\n", player1);
        printf("Player 2 is at position %d.\n", player2);

        
        if (player1 >= 100) {
            printf("Player 1 wins!\n");
            break;
        } else if (player2 >= 100) {
            printf("Player 2 wins!\n");
            break;
        }

        
        currentPlayer = (currentPlayer == 1) ? 2 : 1;

        
        printf("Press Enter to continue...\n");
        while (getchar() != '\n');
    }

    return 0;
}
