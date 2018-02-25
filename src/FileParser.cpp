#include <FileParser.h>
#include <iostream>
#include <string>
#include <user_notification.h>
#include <user_input.h>
#include <platform.h>

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
    std::string title("LIST OF NOTES");
    displayTitleWithBorder(title);
    for(auto it = notes.begin(); it != notes.end(); ++it) {
        displayDataToUserNewLine(*it);
    }
    displayBorderForTitleWithLength(title.size());
}

void FileParser::addNote()
{

    char* input = getLineFromUser();
    std::string line(input);
    bool noCommentNoEmpty = true;

    if (line[0] == '#' || line[0] == '\n') {
        DEBUG_INFO(std::string("Comment or only newline char"));
        noCommentNoEmpty = false;
    }

    //Get current date and time stamp
    std::string dateAndTime(stampler.giveCurrentDateAndTimeStamp());

    //Prepend the note number
    //Used <stdio> due to problems with std::to_string()

    char numStr[16]; // string which will contain the number
    sprintf( numStr, "%d", nrOfNotes+1 );

    //Add date and time stamp and new line at the end of the string
    std::string stampedLine = std::string(numStr) +
                              ". " +
                              std::string("Added on ") +
                              dateAndTime +
                              ": " +
                              line;

    DEBUG_INFO_2(std::string("stampedLine"), stampedLine);

    //Ignore lines with comments & only empty lines
    if ( noCommentNoEmpty) {

        // This is needed in order to remove trailing newline char.
        // This workaround makes the output looks nice.
        std::size_t found = stampedLine.find('\n');
        if ( found != std::string::npos)
            stampedLine.erase(found);

        // This is needed in order to remove trailing carriage return char.
        // This workaround makes the output looks nice.
        found = stampedLine.find('\r');
        if ( found != std::string::npos)
            stampedLine.erase(found);

        // update notes vector
        notes.push_back(stampedLine);
        nrOfNotes++;
        notifyUserInfo(std::string("The note has been added."));

        DEBUG_INFO(std::string("Pushed note to the vector"));
        DEBUG_INFO_2(std::string("Number of NOTES: "), nrOfNotes);
        DEBUG_INFO_2(std::string("\'notes\' vector size: "), notes.size());

        // update the notes file
        if (myfile.is_open()) {
            stampedLine += NEW_LINE;
            myfile << stampedLine.c_str();
            DEBUG_INFO(std::string("Appending to notes file: ") + stampedLine);

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
