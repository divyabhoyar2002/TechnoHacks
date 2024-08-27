#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

// Function to generate a random password of a given length
std::string generatePassword(int length) {
    const std::string characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                                   "abcdefghijklmnopqrstuvwxyz"
                                   "0123456789"
                                   "!@#$%^&*()-_=+[]{}|;:',.<>?/";
    std::string password;
    password.reserve(length);

    // Seed the random number generator
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    for (int i = 0; i < length; ++i) {
        int index = std::rand() % characters.length();
        password += characters[index];
    }

    return password;
}

int main() {
    int length;

    std::cout << "Enter the desired password length: ";
    std::cin >> length;

    if (length <= 0) {
        std::cerr << "Password length must be a positive integer." << std::endl;
        return 1;
    }

    std::string password = generatePassword(length);

    std::cout << "Generated password: " << password << std::endl;

    return 0;
}
