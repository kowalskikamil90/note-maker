#include <iostream>
#include <FileParser.h>

// Only for debugging purposes, not used in production code.
#include <trace_debug.h>

static void printWelcomeMessage();

int main(int argc, char** argv) {

    printWelcomeMessage();

    if (argc > 1) {

        std::string notes_file(argv[1]);
        std::cout << "Following note file was chosen::" << notes_file << std::endl;
        FileParser fileParser(notes_file.c_str());
        if (fileParser.status() == SUCCESS) {

            //This is main loop in the program
            //The user decides what he/she wants to do.
            bool stopped = false;
            char userInput = 'z';

            while (!stopped) {

                std::cout << "Choose option:" << std::endl;
                std::cout << "d - display notes" << std::endl;
                std::cout << "a - add note" << std::endl;
                std::cout << "r - remove note" << std::endl;
                std::cout << "q - quit application" << std::endl;
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

        std::cout << "Please specify the NOTES file when running the program." << std::endl;
        std::cout << "E.g: " << argv[0] << " <notes_file_path> " << std::endl;
        std::cout << "Exitting the application... " << std::endl;

    }

    return 0;
}

static void printWelcomeMessage()
{
    // Prints welcome message...
    std::cout << "###############################" << std::endl;
    std::cout << "#  Welcome to the note maker  #" << std::endl;
    std::cout << "#  author: Kamil Kowalski     #" << std::endl;
    std::cout << "#  version: 1.0               #" << std::endl;
    std::cout << "###############################" << std::endl << std::endl;
}
