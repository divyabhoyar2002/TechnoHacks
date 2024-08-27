#include <iostream>
#include <cstdlib>
#include <ctime>

// Function to roll a die and return a random number between 1 and 6
int rollDie() {
    return rand() % 6 + 1;
}

int main() {
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(nullptr)));

    char rollAgain;

    do {
        // Roll two dice
        int die1 = rollDie();
        int die2 = rollDie();
        int sum = die1 + die2;

        // Display the results
        std::cout << "You rolled a " << die1 << " and a " << die2 << ".\n";
        std::cout << "Total: " << sum << std::endl;

        // Ask if the user wants to roll again
        std::cout << "Do you want to roll again? (y/n): ";
        std::cin >> rollAgain;

    } while (rollAgain == 'y' || rollAgain == 'Y');

    std::cout << "Thanks for playing!" << std::endl;

    return 0;
}
