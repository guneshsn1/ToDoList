#include <iostream>
#include <vector>
#include <string>

int main(){
    bool reask = true;
    std::vector<std::string> todoList;
    while(reask){ // Main loop to allow multiple actions
    std::string task;
    char choice;
    std::cout << "Welcome to the To-Do List App!" << std::endl;
    std::cout << "What would you like to do?" << std::endl;
    std::cout << "A: Add a task" << std::endl;
    std::cout << "V: View tasks" << std::endl;
    std::cout << "R: Remove a task" << std::endl;
    std::cout << "Q: Quit" << std::endl;
    bool notValidChoice = true; 
    while(notValidChoice){ // Loop until a valid choice is made
    std::cin >> choice;
    if(choice == 'Q' || choice == 'q' ){ // Quit option
        std::cout << "Exiting the To-Do List App. Goodbye!" << std::endl;
        exit(0);
    } else if(choice == 'A' || choice == 'a'){ // Add task option
        std::cout << "Enter the task to add: ";
        std::cin.ignore();
        std::getline(std::cin, task);
        todoList.push_back(task);
        std::cout << "Task added!" << std::endl;
        std::cout << "Here is your updated To-Do List:" << std::endl;
        for(int i = 0; i < todoList.size(); i++){ // Display updated list
            std::cout << i + 1 << ": " << todoList[i] << std::endl;
        }
        notValidChoice = false; // Exit loop after valid choice
    } else if(choice == 'V' || choice == 'v'){ // View tasks option
        std::cout << "Your To-Do List:" << std::endl;
        for(int i = 0; i < todoList.size(); i++){
            std::cout << i + 1 << ": " << todoList[i] << std::endl;
        }
        notValidChoice = false; // Exit loop after valid choice
    } else if(choice == 'R' || choice == 'r'){ // Remove task option
        int taskNumber;
        std::cout << "Enter the task number to remove: ";
        bool isnotValid = true;
        while(isnotValid){ // Loop until a valid task number is provided
        std::cin >> taskNumber;
        taskNumber -= 1; // Adjust for 0-based index
        try{
            if(taskNumber < 0 || taskNumber >= todoList.size()){ // Check for valid range
                throw std::out_of_range("Task number out of range");
            }
            todoList.erase(todoList.begin() + taskNumber);
            std::cout << "Task removed!" << std::endl;
            std::cout << "Here is your updated To-Do List:" << std::endl;
            for(int i = 0; i < todoList.size(); i++){ // Display updated list
                std::cout << i + 1 << ": " << todoList[i] << std::endl;
            }
            isnotValid = false; // Exit loop after valid removal
            notValidChoice = false; // Exit main choice loop
        } catch(const std::out_of_range&){ // Handle invalid task number
            std::cout << "Task number out of range! Enter a valid number: ";
        }
        }
    } else {
        std::cout << "Invalid choice!" << std::endl; // Prompt for valid choice again
    }
    }
    std::cout << "Would you like to perform another action? (Y/N): "; // Ask to continue or exit
    char again;
    std::cin >> again;
    if(again == 'N' || again == 'n'){
        reask = false; // Exit main loop
        std::cout << "Thank you for using the To-Do List App. Goodbye!" << std::endl;
    } else if(again == 'Y' || again == 'y'){
        reask = true; // Continue main loop
    } else {
        std::cout << "Invalid input, exiting." << std::endl;
        reask = false;
        std::cout << "Thank you for using the To-Do List App. Goodbye!" << std::endl;   
    }
    }
    return 0;
}