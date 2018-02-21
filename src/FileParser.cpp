#include <FileParser.h>
#include <iostream>
#include <string>

FileParser::FileParser(const char* filePath)
{
  myfile.open(filePath, std::fstream::in | std::fstream::out | std::fstream::app);
  if (!myfile.is_open())
  {
    std::cout << "Problems with opening the file: " << filePath << std::endl;
  }
  else {
    while (myfile) {
        std::string line;
        getline(myfile, line);
        notes.push_back(line);
    }
  }
}

FileParser::~FileParser()
{
    if (myfile.is_open()) {
        myfile.close();
    }
}

void FileParser::displayNotes()
{
    for(auto it = notes.begin(); it != notes.end(); ++it) {
        std::cout << *it << std::endl;
    }
}

void FileParser::addNote()
{

}

void FileParser::removeNote()
{

}

bool FileParser::status()
{
    return myfile.is_open() ? SUCCESS: FAILURE;
}
