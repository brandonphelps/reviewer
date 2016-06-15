
#include "booklet_config.h"

#include "json_parser.h"
#include <iostream>


BookletConfig::BookletConfig(const std::string& book_folder) : m_filename(book_folder + "/config.json")
{
  load_config();
}

void BookletConfig::load_config()
{
  std::cout << "Loading config: " << m_filename << std::endl;
  JsonParser p;

  std::map<std::string, std::string> data = p.parse(m_filename);
  std::cout << "Book Name: " << data["Book Name"] << std::endl;
}
