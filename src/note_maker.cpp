#include <iostream>
#include <FileParser.h>
#include <user_notification.h>

// Only for debugging purposes, not used in production code.
#include <trace_debug.h>

int main(int argc, char** argv) {

    printWelcomeMessage();

    if (argc > 1) {

        std::string notes_file(argv[1]);

        notifyUserLogInfo(std::string("Following note file was chosen: ") + notes_file);

        FileParser fileParser(notes_file.c_str());
        if (fileParser.status() == SUCCESS) {

            //This is main loop in the program
            //The user decides what he/she wants to do.
            bool stopped = false;
            char userInput = 'z';

            while (!stopped) {

                displayToUser("Choose option:");
                displayToUser("d - display notes");
                displayToUser("a - add note");
                displayToUser("r - remove note");
                displayToUser("q - quit application");

                std::cin >> userInput;
                // ignore() is needed because getline() catches the \n char from cin above
                std::cin.ignore();

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

                }
            }
        }
    }

    else {

        displayToUser("Please specify the NOTES file when running the program.");
        displayToUser("Exitting the application... ");
    }

    return 0;
}
