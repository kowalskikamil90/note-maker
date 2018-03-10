#include <iostream>
#include <user_input.h>
#include <user_notification.h>
#include <algorithm>

/* Max number of characters that the user may enter.
 * If more characters is entered, they will be ignored. */
static char input[INPUT_SIZE];

/* Be careful when using cin >> and getline() interchangeably.
 * Use the ignore() function to get rid of chars that
 * were left in the input buffer.
 * The std::numeric_limits<std::streamsize>::max() is the max number of
 * characters the stream may contain */

void getCharFromUser(char& c, const std::vector<char> &validChars)
{

    while (true)
    {
        /* If stream is in failure mode than we need to bring
         * it back to normal mode */
        if (std::cin.fail())
        {
            std::cin.clear();
        }

        std::cin >> c;

        if (!std::cin.fail())
        {
           // Check if one of valid chars was passed
           if(std::find(validChars.begin(), validChars.end(), c) != validChars.end())
           {

               /* If the user entered more then 1 character, the first one
                * is  considered as a chosen option.
                * We need to get rid of the rest of characters that were
                * left in the buffer */
               std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

               // All good, we have the right char, we may exit the loop
               break;
           }
           else
           {
               displayToUser("Choose valid option : ");
           }
        }

        // Ignore in case something left in the buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

}

void getNumFromUser(unsigned& num)
{

    while (true)
    {
        /* If stream is in failure mode than we need to bring
         * it back to normal mode */
        if (std::cin.fail())
        {
            // Clear failure mode and put cin back to normal mode
            std::cin.clear();
        }

        std::cin >> num;

        /* If user entered something that the number can't be
         * extracted from, then the stream will end up in
         * failure mode. Failure mode will occur also when
         * user entered ridiculously big number.  */
        if (!std::cin.fail())
        {

            /* We need to get rid of the rest of characters that were
             * left in the buffer in case there are any */
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            // All good, we have reasonable value, we may exit the loop
            break;
        }
        else
        {
            displayToUser("Value out of range. Give reasonable value : ");
        }

        // Ignore in case something left in the buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

}

char* getLineFromUser()
{
    /* If stream is in failure mode than we need to bring
     * it back to normal mode */
    if (std::cin.fail())
    {
        // Clear failure mode and put cin back to normal mode
        std::cin.clear();
    }

    std::cin.getline(input, INPUT_SIZE);

    return input;
}
