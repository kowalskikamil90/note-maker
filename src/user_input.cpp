#include <iostream>
#include <user_input.h>

static char input[INPUT_SIZE];

// Be careful when using cin and getline() together.

void getCharFromUser(char& c)
{
    std::cin >> c;
    // ignore() is needed because getline() catches the \n char from cin
    std::cin.ignore();
}

void getNumFromUser(unsigned& num)
{
    std::cin >> num;
    // ignore() is needed because getline() catches the \n char from cin
    std::cin.ignore();
}

char* getLineFromUser()
{
    std::cin.getline(input, INPUT_SIZE);
    return input;
}
