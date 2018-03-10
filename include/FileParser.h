#ifndef FILEPARSER_H
#define FILEPARSER_H

#include <fstream>
#include <vector>
#include <Note.h>

#define SUCCESS 1
#define FAILURE 0

class FileParser
{
    public:
        FileParser(const char* filePath);
        ~FileParser();

        void displayNotes() const;
        bool addNote();
        bool removeNote();
        bool status() const;

    private:
        const std::string filePath;
        std::fstream myfile;
        std::vector<Note> notes;
        unsigned int nrOfNotes;

};

#endif // FILEPARSER_H
