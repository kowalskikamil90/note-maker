#include "Note.h"

/* Only for debugging purposes, not used in production code.
 * When compiled in normal mode (not debug) all debug macros
 * are resolved to an empty instruction, therefore having no
 * effect on the code itself. */
#include <trace_debug.h>

Note::Note(const std::string& content, bool readFromFile)
{
    if (readFromFile == true)
    {
        /* In such case we only need to assign fullNote.
         * There is no need to extract other fields from
         * note's content. */
        fullNote.assign(content);

        DEBUG_INFO(std::string("Creating the Note object. Read from file: ") + content);

    }
    else // In this case we need to add a time stamp to the note.
    {
        DEBUG_INFO(std::string("Creating the Note object. Read form user: "));

        //Get current date and time stamp
        dateAndTimeStamp = stampler.giveCurrentDateAndTimeStamp();

        DEBUG_INFO(std::string("dateAndTimeStamp: " + dateAndTimeStamp));

        // Assign the actual content of the note
        this->content.assign(content);

        DEBUG_INFO(std::string("content: " + content));

        // Add date and time stamp and new line at the end of the string
        fullNote = std::string("Added on ") +
                               dateAndTimeStamp +
                               ": " +
                               content;

        DEBUG_INFO_2(std::string("fullNote: "), fullNote);

        /* This is to make sure to remove trailing newline char.
         * This way, we are certain that each line is not ended
         * with the end line char. */
        std::size_t found = fullNote.find('\n');
        if ( found != std::string::npos)
        {
            fullNote.erase(found);
            DEBUG_INFO(std::string("Found newline and removed it..."));
        }
    }
}

const std::string& Note::toString() const
{
    return this->fullNote;
}
