#include <FileParser.h>
#include <iostream>
#include <string>
#include <user_notification.h>
#include <user_input.h>

/* Only for debugging purposes, not used in production code.
 * When compiled in normal mode (not debug) all debug macros
 * are resolved to an empty instruction, therefore having no
 * effect on the code itself. */
#include <trace_debug.h>

FileParser::FileParser(const char* filePath)
{
  this->filePath += filePath;
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

bool FileParser::addNote()
{

    char* input = getLineFromUser();
    std::string line(input);

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

    DEBUG_INFO_2(std::string("stampedLine: "), stampedLine);

    // This is needed in order to remove trailing newline char.
    // This workaround makes the output looks nice.
    std::size_t found = stampedLine.find('\n');
    if ( found != std::string::npos)
    {
        stampedLine.erase(found);
        DEBUG_INFO(std::string("Found newline and removed it..."));
    }

    // update notes vector
    notes.push_back(stampedLine);
    nrOfNotes++;
    notifyUserInfo(std::string("The note has been added."));

    DEBUG_INFO(std::string("Pushed note to the vector"));
    DEBUG_INFO_2(std::string("Number of NOTES: "), nrOfNotes);
    DEBUG_INFO_2(std::string("\'notes\' vector size: "), notes.size());

    if (myfile.is_open())
    {
        /* Need to close the file and open it in trunc mode */
        myfile.close();
        myfile.open(filePath, std::fstream::in | std::fstream::out | std::fstream::trunc);
        if (!myfile.is_open())
        {
            DEBUG_ERROR(std::string("Problems with opening the file in trunc mode: ") + filePath);
            return FAILURE;
        }

        for(auto it = notes.begin(); it != notes.end(); ++it)
        {

            //*it += "\n";
            myfile << it->c_str();
            myfile << '\n';
            DEBUG_INFO(std::string("Appending to notes file..."));

        }

     } else
     {

       DEBUG_ERROR(std::string("Notes file was closed. Note was not appended to the file."));
       return FAILURE;

     }

     return SUCCESS;
}

void FileParser::removeNote()
{

}

bool FileParser::status()
{
    return myfile.is_open() ? SUCCESS: FAILURE;
}
