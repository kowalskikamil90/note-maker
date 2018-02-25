#include <iostream>
#include <FileParser.h>
#include <user_notification.h>
#include <user_input.h>
#include <platform.h>

// Only for debugging purposes, not used in production code.
#include <trace_debug.h>

int main(int argc, char** argv) {

    if (PLATFORM == "Windows")
    {
        DEBUG_INFO(std::string("PLATFORM: Windows"));
    } else if (PLATFORM == "Unix")
    {
        DEBUG_INFO(std::string("PLATFORM: Unix"));
    } else
    {
        DEBUG_INFO(std::string("PLATFORM: Unknown"));
    }

    printWelcomeMessage();

    if (argc > 1) {

        std::string notes_file(argv[1]);

        notifyUserInfo(std::string("Following note file was chosen: ") + notes_file);

        FileParser fileParser(notes_file.c_str());
        if (fileParser.status() == SUCCESS) {

            //This is main loop in the program
            //The user decides what he/she wants to do.
            bool stopped = false;
            char userInput = '#';

            while (!stopped) {

                displayToUserNewLine("");
                displayToUserNewLine("d - display notes");
                displayToUserNewLine("a - add note");
                displayToUserNewLine("r - remove note");
                displayToUserNewLine("q - quit application");
                displayToUserNewLine("");
                displayToUser("Choose option : ");

                getCharFromUser(userInput);

                switch (userInput){

                    case 'd':
                        fileParser.displayNotes();
                        break;
                    case 'a':
                        fileParser.addNote();
                        break;
                    case 'r':
                        fileParser.removeNote();
                        break;
                    case 'q':
                        stopped = true;
                        break;
                    default:
                        notifyUserInfo(std::string("Invalid option was chosen."));

                }
            }
        }
    }

    else {

        displayToUserNewLine("Please specify the NOTES file when running the program.");
        displayToUserNewLine("Exitting the application... ");
    }

    return 0;
}
