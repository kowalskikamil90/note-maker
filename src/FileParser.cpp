#include <FileParser.h>
#include <iostream>
#include <string>
#include <user_notification.h>
#include <user_input.h>

// Only for debugging purposes, not used in production code.
#include <trace_debug.h>

FileParser::FileParser(const char* filePath)
{
  myfile.open(filePath, std::fstream::in | std::fstream::out | std::fstream::app);
  if (!myfile.is_open())
  {
    DEBUG_ERROR(std::string("Problems with opening the file: ") + filePath);
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
    std::cout << "#################  LIST OF NOTES  ###################" << std::endl;
    for(auto it = notes.begin(); it != notes.end(); ++it) {
        std::cout << *it << std::endl;
    }
    std::cout << "#####################################################" << std::endl;
}

void FileParser::addNote()
{

    char* input = getLineFromUser();
    std::string line(input);
    //add new line at the end of the string
    line += "\n";

    //ignore comments & only new lines
    if (line[0] != '#' && line[0] != '\n') {
        // update notes vector
        notes.push_back(line);
        nrOfNotes++;

        notifyUserLogInfo(std::string("The note has been added."));

        // update the notes file
        if (myfile.is_open()) {
            myfile << line.c_str() << std::endl;
            DEBUG_INFO(std::string("Appending to notes file: ") + line);
        } else {
            DEBUG_ERROR(std::string("myfile was closed"));
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
