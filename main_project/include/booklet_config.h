
#ifndef BOOKLET_CONFIG_H
#define BOOKLET_CONFIG_H

#include <string>

class BookletConfig
{
public:
  BookletConfig(const std::string& filename);
 
private:

  void load_config();

  std::string m_filename;
};

#endif
