
#include <iostream>
#include <fstream>

#include <vector>
#include "booklet.h"

#include "prompt.h"

int main(int argc, char* argv[])
{
  std::string filename = "/Users/Elemental/Documents/Projects/reviewer/book/ja/hiragana.txt";

  parse(argc, argv);


  Booklet k(filename);


  return 0;
}
