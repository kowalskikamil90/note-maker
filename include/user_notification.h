#ifndef USER_NOTIFICATION_H_INCLUDED
#define USER_NOTIFICATION_H_INCLUDED

#include <string>

void printWelcomeMessage();

void notifyUserInfo(std::string message);

void displayToUser(std::string message);

void displayDataToUserNewLine(std::string message);

void displayToUserNewLine(std::string message);

void displayTitleWithBorder(std::string title);

void displayBorderForTitleWithLength(unsigned int size);

#endif // USER_NOTIFICATION_H_INCLUDED
