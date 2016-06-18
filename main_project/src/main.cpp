
#include <iostream>
#include <fstream>
#include <random>
#include <vector>
// #include <git2.h>

#include "questioner.h"
#include "book.h"
#include "booklet.h"

#include "prompt.h"
#include "booklet_config.h"

#include "json_parser.h"


int main(int argc, char* argv[])
{
  //std::string filename = "/Users/Elemental/Documents/Projects/reviewer/book/ja/katakana.txt";
  //git_libgit2_init();

  if(argc != 2)
  {
    std::cout << "Please specify a reviewer config file" << std::endl;
  }
  else
  {
    JsonParser p;
    JsonDict reviewer_config = p.parse(argv[1]);
    Questioner quizzer;
    quizzer.addBooklet(Booklet(reviewer_config.getString("book 1")));
    quizzer.performReview();
  }
  return 0;
}
