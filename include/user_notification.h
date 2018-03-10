#ifndef USER_NOTIFICATION_H_INCLUDED
#define USER_NOTIFICATION_H_INCLUDED

#include <string>

void printWelcomeMessage();

void notifyUserInfo(const std::string &message);

void displayToUser(const std::string &message);

void displayDataToUserNewLine(const std::string &message);

void displayToUserNewLine(const std::string &message);

void displayTitleWithBorder(const std::string &title);

void displayListNumber(unsigned number);

void displayBorderForTitleWithLength(unsigned int size);

#endif // USER_NOTIFICATION_H_INCLUDED
