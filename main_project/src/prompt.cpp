

#include "prompt.h"

#include <iostream>

bool parse(int argc, char* argv[])
{
  for(int i = 0; i < argc; i++)
  {
    std::cout << argv[i] << std::endl;
  }
  return true;
}


void printHelp()
{
  
}
   
