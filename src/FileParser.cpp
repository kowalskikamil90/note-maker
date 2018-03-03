#include <FileParser.h>
#include <Note.h>
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
        if (*line.begin() == '#') {

            DEBUG_INFO(std::string("Read a comment"));

        }
        else if (line.empty()) {

            DEBUG_INFO(std::string("Read empty line"));

        }
        else {

            /* If the note is read from the file it means it already has
             * a timestamp, so we do not need to add it while constructing
             * the Note object. */
            bool readFromFile = true;
            Note aNote(line, readFromFile);
            notes.push_back(aNote);
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
    unsigned noteNum = 1;
    for(auto it = notes.begin(); it != notes.end(); ++it) {
        displayListNumber(noteNum++);
        displayDataToUserNewLine(it->toString());
    }
    displayBorderForTitleWithLength(title.size());
}

bool FileParser::addNote()
{

    char* input = getLineFromUser();
    std::string line(input);

    /* If the note is read from the user it means it does not have
     * a timestamp, so we need to add it while constructing
     * the Note object. */
    bool readFromFile = false;
    Note aNote(line, readFromFile);

    // update notes vector
    notes.push_back(aNote);
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
            myfile << it->toString().c_str();
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
