#ifndef FILEPARSER_H
#define FILEPARSER_H

#include <fstream> //for file handling

class FileParser
{
    public:
        FileParser(const char* filePath);
        virtual ~FileParser();

    protected:

    private:
        std::fstream myfile;
};

#endif // FILEPARSER_H
