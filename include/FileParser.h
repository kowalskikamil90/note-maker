#ifndef FILEPARSER_H
#define FILEPARSER_H

#include <fstream> //std::fstream
#include <vector> //std::vector
#include <Note.h>

#define SUCCESS 1
#define FAILURE 0

class FileParser
{
    public:
        FileParser(const char* filePath);
        virtual ~FileParser();

        void displayNotes();
        bool addNote();
        bool removeNote();
        bool status();

    protected:

    private:
        std::string filePath;
        std::fstream myfile;
        std::vector<Note> notes;
        unsigned int nrOfNotes;

};

#endif // FILEPARSER_H
