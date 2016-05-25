
#include <iostream>
#include <fstream>
#include <random>
#include <vector>


#include "questioner.h"
#include "booklet.h"

#include "prompt.h"

int main(int argc, char* argv[])
{
  std::string filename = "/Users/Elemental/Documents/Projects/reviewer/book/ja/hiragana.txt";

  srand(time(time()));


  parse(argc, argv);

  Booklet k(filename);

  Questioner quizer(k);
  
  quizer.askQuestion();

  return 0;
}
