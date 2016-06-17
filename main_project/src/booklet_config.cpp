
#include "booklet_config.h"

#include "json_parser.h"
#include <iostream>


BookletConfig::BookletConfig(const std::string& book_folder) : m_filename(book_folder + "/config.json")
{
  std::cout << "Booklet Config Constructor: " << m_filename << std::endl;
  load_config();
}

std::vector<std::string> BookletConfig::getChapters()
{
  return m_chapters;
}

void BookletConfig::load_config()
{
  std::cout << "Booklet Loading config" << std::endl;

  JsonParser p;
  std::cout << "Attempting to parse file: " << m_filename << std::endl;
  JsonDict data = p.parse(m_filename);
  std::cout << "Book Name: " << data.getString("Book Name") << std::endl;
  std::cout << "Chapter 1: " << data.getArray("chapters")[0] << std::endl;
  std::cout << "Chatper 2: " << data.getArray("chapters")[1] << std::endl;

  m_chapters = data.getArray("chapters");
}
