#include <FileParser.h>
//#include <fstream>

FileParser::FileParser(const char* filePath)
{
  myfile.open(filePath, std::fstream::in | std::fstream::out | std::fstream::app);
  if (myfile.is_open())
  {
    myfile << "This is some note.\n";
    myfile << "This is another note.\n";
  }
}

FileParser::~FileParser()
{
    myfile.close();
}
