#ifndef NOTE_H
#define NOTE_H

#include <DateAndTimeStampler.h>
#include <string>

class Note
{
    public:
        Note(const std::string& content, bool readFromFile);
        const std::string& toString() const;

    private:
        DateAndTimeStampler stampler;
        std::string dateAndTimeStamp;
        std::string content;
        std::string fullNote;

};

#endif // NOTE_H
