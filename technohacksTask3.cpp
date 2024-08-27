#include <iostream>
#include <cstdlib>
#include <ctime>

// Function to get the computer's choice
int getComputerChoice() {
    return rand() % 3;  // Random number between 0 and 2
}

// Function to get the user's choice
int getUserChoice() {
    int choice;
    std::cout << "Choose one:\n0 - Rock\n1 - Paper\n2 - Scissors\n";
    std::cout << "Enter your choice (0, 1, or 2): ";
    std::cin >> choice;
    return choice;
}

// Function to determine the winner
void determineWinner(int userChoice, int computerChoice) {
    const char* choices[] = {"Rock", "Paper", "Scissors"};

    std::cout << "You chose: " << choices[userChoice] << std::endl;
    std::cout << "Computer chose: " << choices[computerChoice] << std::endl;

    if (userChoice == computerChoice) {
        std::cout << "It's a tie!" << std::endl;
    } else if ((userChoice == 0 && computerChoice == 2) ||
               (userChoice == 1 && computerChoice == 0) ||
               (userChoice == 2 && computerChoice == 1)) {
        std::cout << "You win!" << std::endl;
    } else {
        std::cout << "Computer wins!" << std::endl;
    }
}

int main() {
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(nullptr)));

    char playAgain;

    do {
        int userChoice = getUserChoice();
        int computerChoice = getComputerChoice();

        determineWinner(userChoice, computerChoice);

        std::cout << "Do you want to play again? (y/n): ";
        std::cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    std::cout << "Thanks for playing!" << std::endl;

    return 0;
}
