#include <iostream>
#include <cstdlib>
#include <ctime>

// Function to generate a random number between 1 and 100
int generateRandomNumber() {
    return rand() % 100 + 1;  // Using rand() from <cstdlib>
}

// Function to get a guess from the user
int getUserGuess() {
    int guess;
    std::cout << "\n Enter your guess: ";  // Using std::cout for output
    std::cin >> guess;                  // Using std::cin for input
    return guess;
}

// Function 
void giveHint(int guess, int targetNumber) {
    if (guess < targetNumber) {
        std::cout << "\n Too low! Try again." << std::endl;
    } else if (guess > targetNumber) {
        std::cout << "\n Too high! Try again." << std::endl;
    } else {
        std::cout << "\n Congratulations! You guessed the correct number!" << std::endl;
    }
}

int main() {
    // Random number generator
    srand(static_cast<unsigned int>(time(nullptr)));  

    int targetNumber = generateRandomNumber();
    int guess = 0;
    int attempts = 0;

    std::cout << "\n Guess the number between 1 and 100:" << std::endl;

    // Loop until the user guesses the correct number
    while (guess != targetNumber) {
        guess = getUserGuess();
        attempts++;
        giveHint(guess, targetNumber);
    }

    std::cout << "\n You guessed the number in " << attempts << " attempts." << std::endl;

    return 0;
}
