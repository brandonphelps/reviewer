
#include <iostream>
#include <fstream>
#include <random>
#include <vector>
#include <git2.h>

#include "questioner.h"
#include "book.h"
#include "booklet.h"

#include "prompt.h"

#include <json_parser.h>

int main(int argc, char* argv[])
{
  std::string filename = "/Users/Elemental/Documents/Projects/reviewer/book/ja/katakana.txt";

  git_libgit2_init();

  JsonParser p;

  Book b("/Users/Elemental/Documents/Projects/reviewer/book/tmp");

  //b.download("https://github.com/brandonphelps/Arctic");

  //b.download("/Users/Elemental/Desktop/ja");

  b.load_config();

  /*
  time_t s;
  s = time(NULL);

  srand(s);
    
  std::cout << "Current seed: " << s << std::endl;
    
  parse(argc, argv);

  Questioner quizer;

  quizer.addBooklet(Booklet(filename));
  quizer.addBooklet(Booklet("/Users/Elemental/Documents/Projects/reviewer/book/ja/hiragana.txt"));
  quizer.addBooklet(Booklet("/Users/Elemental/Documents/Projects/reviewer/book/ja/kanji1.txt"));

  quizer.performReview();
  */
  return 0;
}
