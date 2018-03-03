#include "DateAndTimeStampler.h"
#include <ctime>

std::string DateAndTimeStampler::giveCurrentDateAndTimeStamp()
{
   /* Current date/time based on current system.
    * This returns time measured in seconds from 1970.. */
   time_t now = time(0);

   /* This converts time to a readable format
    * to have a date and time */
   std::string dateAndTime(ctime(&now));

   /* Remove trailing newline char if exists */
   std::size_t found = dateAndTime.find('\n');
   if ( found != std::string::npos)
       dateAndTime.erase(found);

   return dateAndTime;
}
