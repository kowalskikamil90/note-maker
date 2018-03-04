#ifndef USER_INPUT_H_INCLUDED
#define USER_INPUT_H_INCLUDED

#include <vector>

//This is max size of the note that the user may enter
#define INPUT_SIZE 200

void getCharFromUser(char& c, std::vector<char>& validChars);

void getNumFromUser(unsigned& num);

char* getLineFromUser();

#endif // USER_INPUT_H_INCLUDED
