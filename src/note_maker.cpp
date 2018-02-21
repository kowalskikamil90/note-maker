#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char**argv) {

    // Prints welcome message...
    std::cout << "Welcome to the note maker..." << std::endl;
    std::cout << "author: Kamil Kowalski" << std::endl << std::endl;

    if (argc > 1) {

        std::string notes_file(argv[1]);
        std::cout << "Following note file was chosen::" << notes_file << std::endl;

    }

    else {

        std::cout << "Please specify the NOTES file when running the program." << std::endl;
        std::cout << "E.g: " << argv[0] << " <notes_file_path> " << std::endl;
        std::cout << "Exitting the application... " << std::endl;

    }

    return 0;
}
