#include <iostream>
#include <user_input.h>
#include <user_notification.h>
#include <algorithm>

static char input[INPUT_SIZE];

/* Be careful when using cin >> and getline() interchangeably.
 * Use the ignore() function to get rid of chars that
 * were left in the input buffer */

void getCharFromUser(char& c, std::vector<char>& validChars)
{

    while (true)
    {
        if (std::cin.fail())
        {
            // Clear failure mode and put cin back to normal mode
            std::cin.clear();
        }

        std::cin >> c;

        if (!std::cin.fail())
        {
           // Check if one of valid chars was passed
           if(std::find(validChars.begin(), validChars.end(), c) != validChars.end())
           {

               std::cin.ignore();

               // All good, we have the right char, we may exit the loop
               break;
           }
           else
           {
               displayToUser("Choose valid option : ");
           }
        }

        // Ignore in case something left in the buffer
        std::cin.ignore();
    }

}

void getNumFromUser(unsigned& num)
{

    while (true)
    {
        if (std::cin.fail())
        {
            // Clear failure mode and put cin back to normal mode
            std::cin.clear();
        }

        std::cin >> num;

        if (!std::cin.fail())
        {

            std::cin.ignore();

            // All good, we have reasonable value, we may exit the loop
            break;
        }
        else
        {
            displayToUser("Value out of range. Give reasonable value : ");
        }

        // Ignore in case something left in the buffer
        std::cin.ignore();
    }

}

char* getLineFromUser()
{

    if (std::cin.fail())
    {
        // Clear failure mode and put cin back to normal mode
        std::cin.clear();
    }

    std::cin.getline(input, INPUT_SIZE);

    return input;
}
