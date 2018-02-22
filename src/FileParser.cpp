#include <FileParser.h>
#include <iostream>
#include <string>

#define INPUT_SIZE 200

FileParser::FileParser(const char* filePath)
{
  myfile.open(filePath, std::fstream::in | std::fstream::out | std::fstream::app);
  if (!myfile.is_open())
  {
    std::cout << "DEBUG ERROR : Problems with opening the file: " << filePath << std::endl;
  }
  else {
    nrOfNotes = 0;
    while (myfile) {
        std::string line;
        getline(myfile, line);
        //ignore comments in note file
        if (line[0] != '#' && line[0] != '\n') {
            notes.push_back(line);
            nrOfNotes++;
        }
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
    //update the file
    char input[INPUT_SIZE];
    std::cin.getline(input, INPUT_SIZE);

    std::string line(input);
    //add new line at the end of the string
    line += "\n";

    //ignore comments & only new lines
    if (line[0] != '#' && line[0] != '\n') {
        // update notes vector
        notes.push_back(line);
        nrOfNotes++;

        // update the notes file
        if (myfile.is_open()) {
            myfile << line.c_str() << std::endl;
            std::cout << "DEBUG INFO : appending to notes file :" << line << std::endl;
        } else {
            std::cout << "DEBUG ERROR : myfile was closed" << std::endl;
        }
    }
}

void FileParser::removeNote()
{

}

bool FileParser::status()
{
    return myfile.is_open() ? SUCCESS: FAILURE;
}
