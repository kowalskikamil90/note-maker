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

void notifyUserInfo(const std::string &message)
{
    std::cout << "<<INFO>>: " << message << std::endl;
}

void displayToUserNewLine(const std::string &message)
{
    std::cout << "    >> " << message << std::endl;
}

void displayToUser(const std::string &message)
{
    std::cout << "    >> " << message;
}

void displayDataToUserNewLine(const std::string &message)
{
    std::cout << "# " << message << std::endl;
}

void displayTitleWithBorder(const std::string &title)
{
    std::cout << "################# " << title << " #################";
    std::cout << std::endl;
}

void displayListNumber(unsigned number)
{
    std::cout << number;
    std::cout << ". ";
}

void displayBorderForTitleWithLength(unsigned int size)
{
    for (unsigned int i = 0 ; i < 36+size ; i++)
    {
        std::cout << "#";
    }
    std::cout << std::endl;
}
