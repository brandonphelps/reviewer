
#include <iostream>
#include <fstream>
#include <random>
#include <vector>
// #include <git2.h>

#include "questioner.h"
#include "book.h"
#include "booklet.h"

#include "prompt.h"

#include "json_parser.h"

int main(int argc, char* argv[])
{
  std::cout << "Hello World!" << std::endl;
  std::cout << "Args" << std::endl;
  std::cout << argc << std::endl;
  for(int i = 0; i < argc; i++)
  {
    std::cout << argv[i] << std::endl;
  }

  //std::string filename = "/Users/Elemental/Documents/Projects/reviewer/book/ja/katakana.txt";
  //git_libgit2_init();
  JsonParser p;

  if(argc != 2)
  {
    std::cout << "Please specify a reviewer config file" << std::endl;
  }
  else
  {
    std::cout << "Using reviewer config : " << argv[1] << std::endl;
    std::map<std::string, std::string> reviewer_config = p.parse(argv[1]);
    std::map<std::string, std::string>::iterator it;
    for(it = reviewer_config.begin(); it != reviewer_config.end(); ++it)
    {
      std::cout << it->first << " : " << it->second << std::endl;
    }
    Booklet b(reviewer_config["book 1"]);
    Questioner quizzer;
    quizzer.addBooklet(b);
    quizzer.performReview();
  }

  //Book b("/Users/Elemental/Documents/Projects/reviewer/book/tmp");

  //b.download("https://github.com/brandonphelps/Arctic");

  //b.download("/Users/Elemental/Desktop/ja");
  
  std::cout << "Book loading config" << std::endl;

  //b.load_config();
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
