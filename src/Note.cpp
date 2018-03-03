#include "Note.h"

/* Only for debugging purposes, not used in production code.
 * When compiled in normal mode (not debug) all debug macros
 * are resolved to an empty instruction, therefore having no
 * effect on the code itself. */
#include <trace_debug.h>

Note::Note(std::string content, bool readFromFile)
{
    if (readFromFile == true)
    {

        /* In such case we need to extract various fields from the note */
        fullNote += content;

        DEBUG_INFO(std::string("Creating the Note object. Read from file: ") + content);

        //TODO: extract all necessary fields

    } else // In this case we need to add a time stamp to the note.
    {
        DEBUG_INFO(std::string("Creating the Note object. Read form user: "));
        //Get current date and time stamp
        dateAndTimeStamp += stampler.giveCurrentDateAndTimeStamp();

        DEBUG_INFO(std::string("dateAndTimeStamp: " + dateAndTimeStamp));

        //Assign the actual content of the note
        this->content += content;

        DEBUG_INFO(std::string("content: " + content));

        //Add date and time stamp and new line at the end of the string
        fullNote = std::string("Added on ") +
                           dateAndTimeStamp +
                                       ": " +
                                     content;

        DEBUG_INFO_2(std::string("fullNote: "), fullNote);

        // This is needed in order to remove trailing newline char.
        // This workaround makes the output looks nice.
        std::size_t found = fullNote.find('\n');
        if ( found != std::string::npos)
        {
            fullNote.erase(found);
            DEBUG_INFO(std::string("Found newline and removed it..."));
        }
    }
}

std::string Note::toString()
{
    return this->fullNote;
}
