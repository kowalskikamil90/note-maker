#include "DateAndTimeStampler.h"
#include <ctime>

std::string DateAndTimeStampler::giveCurrentDateAndTimeStamp()
{
   // Current date/time based on current system.
   // This is measured in seconds from 1970..
   time_t now = time(0);

   std::string dateAndTime(ctime(&now));

   // Remove trailing newline char.
   std::size_t found = dateAndTime.find('\n');
   if ( found != std::string::npos)
       dateAndTime.erase(found);

   return dateAndTime;
}
