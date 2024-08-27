#include <iostream>

// Function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5.0 / 9.0;
}

// Function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32;
}

int main() {
    char choice;
    double temperature, convertedTemperature;

    do {
        std::cout << "Temperature Conversion Menu:\n";
        std::cout << "1. Convert Fahrenheit to Celsius\n";
        std::cout << "2. Convert Celsius to Fahrenheit\n";
        std::cout << "Enter your choice (1 or 2): ";
        std::cin >> choice;

        if (choice == '1') {
            std::cout << "Enter temperature in Fahrenheit: ";
            std::cin >> temperature;
            convertedTemperature = fahrenheitToCelsius(temperature);
            std::cout << temperature << "°F is " << convertedTemperature << "°C.\n";
        } else if (choice == '2') {
            std::cout << "Enter temperature in Celsius: ";
            std::cin >> temperature;
            convertedTemperature = celsiusToFahrenheit(temperature);
            std::cout << temperature << "°C is " << convertedTemperature << "°F.\n";
        } else {
            std::cout << "Invalid choice. Please enter 1 or 2.\n";
            continue;
        }

        std::cout << "Do you want to convert another temperature? (y/n): ";
        std::cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    std::cout << "Thank you for using the temperature converter!" << std::endl;

    return 0;
}
