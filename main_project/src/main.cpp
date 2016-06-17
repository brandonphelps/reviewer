
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
  std::cout << "Hello World!" << std::endl;
  std::cout << "Args" << std::endl;
  std::cout << argc << std::endl;
  for(int i = 0; i < argc; i++)
  {
    std::cout << argv[i] << std::endl;
  }

  //std::string filename = "/Users/Elemental/Documents/Projects/reviewer/book/ja/katakana.txt";
  //git_libgit2_init();

  if(argc != 2)
  {
    std::cout << "Please specify a reviewer config file" << std::endl;
  }
  else
  {
    JsonParser p;
    std::cout << "Using reviewer config : " << argv[1] << std::endl;

    JsonDict reviewer_config = p.parse(argv[1]);
    std::cout << "Project name : " << reviewer_config.getString("Project Name") << std::endl;

    std::vector<std::string> book2 = reviewer_config.getArray("book 2");
    std::cout << "Book2" << std::endl;
    for(int i = 0; i < book2.size(); i++)
    {
      std::cout << book2[i] << std::endl;
    }
    std::cout << "book 3" << reviewer_config.getString("book 3") << std::endl;
    Booklet b(reviewer_config.getString("book 1"));
    /*
    Questioner quizzer;
    quizzer.addBooklet(b);
    quizzer.performReview();
    */
  }
  return 0;
}
