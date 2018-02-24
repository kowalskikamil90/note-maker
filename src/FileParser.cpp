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

    DEBUG_INFO(std::string("File opened successfully: ") + filePath);

    nrOfNotes = 0;
    while (myfile) {
        std::string line;
        getline(myfile, line);

        //Check if the start of string is either # or newline
        if (*line.begin() == '#' || line.empty()) {

            DEBUG_INFO(std::string("Comment or empty line"));

        }
        else {
            notes.push_back(line);
            nrOfNotes++;

            DEBUG_INFO(std::string("Pushed note to the vector"));
        }
    }

    DEBUG_INFO_2(std::string("Number of NOTES after reading the file: "), nrOfNotes);

    /* After reading the whole file the EOF flag is set.
       The stream will stop working until that flag is cleared. */
    myfile.clear();
  }
}

FileParser::~FileParser()
{
    if (myfile.is_open()) {
        myfile.close();
    }

    notes.clear();
    nrOfNotes = 0;
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

        DEBUG_INFO(std::string("Pushed note to the vector"));
        DEBUG_INFO_2(std::string("Number of NOTES: "), nrOfNotes);

        // update the notes file
        if (myfile.is_open()) {

            myfile << line.c_str() << std::endl;
            DEBUG_INFO(std::string("Appending to notes file: ") + line);

        } else {

            DEBUG_ERROR(std::string("Notes file was closed"));

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
