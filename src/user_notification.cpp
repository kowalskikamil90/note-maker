#include <user_notification.h>
#include <iostream>

void printWelcomeMessage()
{
    // Prints welcome message...
    std::cout << "###############################" << std::endl;
    std::cout << "#  Welcome to the note maker  #" << std::endl;
    std::cout << "#  author: Kamil Kowalski     #" << std::endl;
    std::cout << "#  version: 1.0               #" << std::endl;
    std::cout << "###############################" << std::endl << std::endl;
}

void notifyUserLogInfo(std::string message)
{
    std::cout << "LOG_INFO: " << message << std::endl;
}

void displayToUser(std::string message)
{
    std::cout << "    # " << message << std::endl;
}
