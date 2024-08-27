#include <iostream>
#include <filesystem>
#include <string>

// Namespace for filesystem operations
namespace fs = std::filesystem;

// Function to create a directory
void createDirectory(const std::string& path) {
    if (fs::create_directory(path)) {
        std::cout << "Directory created successfully.\n";
    } else {
        std::cout << "Failed to create directory or directory already exists.\n";
    }
}

// Function to delete a directory
void deleteDirectory(const std::string& path) {
    if (fs::remove_all(path)) {
        std::cout << "Directory deleted successfully.\n";
    } else {
        std::cout << "Failed to delete directory or directory does not exist.\n";
    }
}

// Function to create a file
void createFile(const std::string& path) {
    std::ofstream file(path);
    if (file) {
        std::cout << "File created successfully.\n";
    } else {
        std::cout << "Failed to create file.\n";
    }
}

// Function to delete a file
void deleteFile(const std::string& path) {
    if (fs::remove(path)) {
        std::cout << "File deleted successfully.\n";
    } else {
        std::cout << "Failed to delete file or file does not exist.\n";
    }
}

// Function to list files and directories in a directory
void listDirectory(const std::string& path) {
    if (fs::exists(path) && fs::is_directory(path)) {
        std::cout << "Contents of directory " << path << ":\n";
        for (const auto& entry : fs::directory_iterator(path)) {
            std::cout << entry.path().filename().string() << (fs::is_directory(entry) ? " [DIR]" : "") << '\n';
        }
    } else {
        std::cout << "Directory does not exist.\n";
    }
}

int main() {
    char choice;
    std::string path;

    do {
        std::cout << "File and Folder Management Menu:\n";
        std::cout << "1. Create a directory\n";
        std::cout << "2. Delete a directory\n";
        std::cout << "3. Create a file\n";
        std::cout << "4. Delete a file\n";
        std::cout << "5. List contents of a directory\n";
        std::cout << "Enter your choice (1-5): ";
        std::cin >> choice;

        switch (choice) {
            case '1':
                std::cout << "Enter path of the directory to create: ";
                std::cin >> path;
                createDirectory(path);
                break;
            case '2':
                std::cout << "Enter path of the directory to delete: ";
                std::cin >> path;
                deleteDirectory(path);
                break;
            case '3':
                std::cout << "Enter path of the file to create: ";
                std::cin >> path;
                createFile(path);
                break;
            case '4':
                std::cout << "Enter path of the file to delete: ";
                std::cin >> path;
                deleteFile(path);
                break;
            case '5':
                std::cout << "Enter path of the directory to list: ";
                std::cin >> path;
                listDirectory(path);
                break;
            default:
                std::cout << "Invalid choice. Please enter a number between 1 and 5.\n";
                break;
        }

        std::cout << "Do you want to perform another operation? (y/n): ";
        std::cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    std::cout << "Thank you for using the file and folder manager!" << std::endl;

    return 0;
}
