#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int getUserChoice() {
    int choice;
    printf("Enter your choice:\n");
    printf("1. Rock\n");
    printf("2. Paper\n");
    printf("3. Scissors\n");
    scanf("%d", &choice);
    return choice;
}


int getComputerChoice() {
    
    return (rand() % 3) + 1;
}


void determineWinner(int userChoice, int computerChoice) {
    if (userChoice == computerChoice) {
        printf("It's a tie!\n");
    } else if ((userChoice == 1 && computerChoice == 3) ||
               (userChoice == 2 && computerChoice == 1) ||
               (userChoice == 3 && computerChoice == 2)) {
        printf("Congratulations! You win!\n");
    } else {
        printf("Computer wins! Better luck next time.\n");
    }
}

int main() {
    int userChoice, computerChoice;

    
    srand(time(NULL));

    printf("Welcome to Rock-Paper-Scissors!\n");

    do {
        
        userChoice = getUserChoice();

        
        if (userChoice < 1 || userChoice > 3) {
            printf("Invalid choice. Please enter a number between 1 and 3.\n");
        } else {
            
            computerChoice = getComputerChoice();

            
            printf("You chose: ");
            switch (userChoice) {
                case 1:
                    printf("Rock\n");
                    break;
                case 2:
                    printf("Paper\n");
                    break;
                case 3:
                    printf("Scissors\n");
                    break;
            }
            printf("Computer chose: ");
            switch (computerChoice) {
                case 1:
                    printf("Rock\n");
                    break;
                case 2:
                    printf("Paper\n");
                    break;
                case 3:
                    printf("Scissors\n");
                    break;
            }

            
            determineWinner(userChoice, computerChoice);
        }
    } while (userChoice < 1 || userChoice > 3); 

    return 0;
}
