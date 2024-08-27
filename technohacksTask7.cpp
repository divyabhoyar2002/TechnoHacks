#include <iostream>
#include <vector>
#include <string>

// Task structure to store task details
struct Task {
    std::string description;
    bool completed;
};

// Function to add a task to the to-do list
void addTask(std::vector<Task>& todoList) {
    std::string description;
    std::cout << "Enter task description: ";
    std::cin.ignore();  // Clear the newline character left in the buffer
    std::getline(std::cin, description);
    todoList.push_back(Task{description, false});
    std::cout << "Task added.\n";
}

// Function to mark a task as completed
void markTaskCompleted(std::vector<Task>& todoList) {
    int taskNumber;
    std::cout << "Enter the task number to mark as completed: ";
    std::cin >> taskNumber;

    if (taskNumber >= 1 && taskNumber <= static_cast<int>(todoList.size())) {
        todoList[taskNumber - 1].completed = true;
        std::cout << "Task marked as completed.\n";
    } else {
        std::cout << "Invalid task number.\n";
    }
}

// Function to display all tasks
void displayTasks(const std::vector<Task>& todoList) {
    if (todoList.empty()) {
        std::cout << "No tasks in the list.\n";
        return;
    }

    std::cout << "To-Do List:\n";
    for (size_t i = 0; i < todoList.size(); ++i) {
        std::cout << (i + 1) << ". " << todoList[i].description
                  << (todoList[i].completed ? " (Completed)" : "") << std::endl;
    }
}

int main() {
    std::vector<Task> todoList;
    char choice;

    do {
        std::cout << "To-Do List Menu:\n";
        std::cout << "1. Add a task\n";
        std::cout << "2. Mark a task as completed\n";
        std::cout << "3. Display all tasks\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice (1-4): ";
        std::cin >> choice;

        switch (choice) {
            case '1':
                addTask(todoList);
                break;
            case '2':
                markTaskCompleted(todoList);
                break;
            case '3':
                displayTasks(todoList);
                break;
            case '4':
                std::cout << "Exiting the program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please enter a number between 1 and 4.\n";
                break;
        }

        if (choice != '4') {
            std::cout << "Do you want to perform another operation? (y/n): ";
            std::cin >> choice;
        }

    } while (choice == 'y' || choice == 'Y');

    return 0;
}
