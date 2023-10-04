#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int lower = 1, upper = 100; 
    int number_to_guess, user_guess, attempts = 0;

    
    srand(time(NULL));

    
    number_to_guess = (rand() % (upper - lower + 1)) + lower;

    printf("Welcome to the Guess the Number game!\n");
    printf("I'm thinking of a number between %d and %d. Try to guess it!\n", lower, upper);

    do {
        printf("Enter your guess: ");
        scanf("%d", &user_guess);
        attempts++;

        if (user_guess < number_to_guess) {
            printf("Too low! Try again.\n");
        } else if (user_guess > number_to_guess) {
            printf("Too high! Try again.\n");
        } else {
            printf("Congratulations! You guessed the number %d in %d attempts!\n", number_to_guess, attempts);
        }
    } while (user_guess != number_to_guess);

    return 0;
}
