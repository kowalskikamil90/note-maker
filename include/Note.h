#ifndef NOTE_H
#define NOTE_H

#include <DateAndTimeStampler.h>
#include <string>

class Note
{
    public:
        Note(std::string content, bool readFromFile);
        std::string toString();

    private:
        DateAndTimeStampler stampler;
        std::string dateAndTimeStamp;
        std::string content;
        std::string fullNote;
        unsigned noteNumber;

};

#endif // NOTE_H
