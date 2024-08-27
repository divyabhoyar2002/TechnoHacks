#include <iostream>
#include <string>
#include <cmath>

// Function to convert binary string to decimal
int binaryToDecimal(const std::string& binary) {
    int decimal = 0;
    int power = 1; // 2^0

    // Iterate over the binary string from right to left
    for (int i = binary.length() - 1; i >= 0; --i) {
        if (binary[i] == '1') {
            decimal += power;
        } else if (binary[i] != '0') {
            std::cerr << "Invalid binary input: " << binary << std::endl;
            return -1;
        }
        power *= 2; // Move to the next power of 2
    }
    return decimal;
}

int main() {
    std::string binary;
    
    std::cout << "Enter a binary number: ";
    std::cin >> binary;

    int decimal = binaryToDecimal(binary);
    
    if (decimal != -1) {
        std::cout << "The decimal equivalent of binary " << binary << " is " << decimal << "." << std::endl;
    }

    return 0;
}
