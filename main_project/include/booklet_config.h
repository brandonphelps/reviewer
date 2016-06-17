
#ifndef BOOKLET_CONFIG_H
#define BOOKLET_CONFIG_H

#include <string>
#include <vector>

class BookletConfig
{
public:
  BookletConfig(const std::string& filename);

  std::vector<std::string> getChapters();
 
private:

  void load_config();

  std::vector<std::string> m_chapters;

  std::string m_filename;
};

#endif
