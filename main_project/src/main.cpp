
#include <iostream>
#include <fstream>
#include <random>
#include <vector>


#include "questioner.h"
#include "booklet.h"

#include "prompt.h"

int main(int argc, char* argv[])
{
  std::string filename = "/Users/Elemental/Documents/Projects/reviewer/book/ja/katakana.txt";

  time_t s;
  s = time(NULL);

  srand(s);
    
  std::cout << "Current seed: " << s << std::endl;
    
  parse(argc, argv);

  Questioner quizer;

  quizer.addBooklet(Booklet(filename));
  quizer.addBooklet(Booklet("/Users/Elemental/Documents/Projects/reviewer/book/ja/hiragana.txt"));

  quizer.performReview();

  return 0;
}
