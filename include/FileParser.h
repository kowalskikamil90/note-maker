#ifndef FILEPARSER_H
#define FILEPARSER_H

#include <fstream> //std::fstream

#define SUCCESS 1
#define FAILURE 0

class FileParser
{
    public:
        FileParser(const char* filePath);
        virtual ~FileParser();

        void displayNotes();
        void addNote();
        void removeNote();
        bool status();

    protected:

    private:
        std::fstream myfile;
};

#endif // FILEPARSER_H
