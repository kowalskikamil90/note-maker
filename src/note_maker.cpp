#include <iostream>
#include <FileParser.h>
#include <user_notification.h>
#include <user_input.h>

/* Only for debugging purposes, not used in production code.
 * When compiled in normal mode (not debug) all debug macros
 * are resolved to an empty instruction, therefore having no
 * effect on the code itself. */
#include <trace_debug.h>

int main(int argc, char** argv) {

    printWelcomeMessage();

    if (argc > 1) {

        std::string notes_file(argv[1]);

        notifyUserInfo(std::string("Following note file was chosen: ") + notes_file);

        FileParser fileParser(notes_file.c_str());
        if (fileParser.status() == SUCCESS) {

            /* This is main loop in the program.
             * The user decides what to do. */
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

                //Vector holding all valid user input
                const std::vector<char> validChars{'d', 'a', 'r', 'q'};

                getCharFromUser(userInput, validChars);

                switch (userInput)
                {

                    case 'd':
                        fileParser.displayNotes();
                        break;

                    case 'a':

                        if (fileParser.addNote() == SUCCESS)
                        {
                            break;
                        }
                        else
                        {
                            return 1;
                        }

                    case 'r':

                        if (fileParser.removeNote() == SUCCESS)
                        {
                            break;
                        }
                        else
                        {
                            return 1;
                        }

                    case 'q':
                        stopped = true;
                        break;

                    default:
                        notifyUserInfo(std::string("Invalid option was chosen."));

                }
            }
        }
    }

    else
    {

        displayToUserNewLine("Please specify the NOTES file when running the program.");
        displayToUserNewLine("Exitting the application... ");

    }

    return 0;
}
