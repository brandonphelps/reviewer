

// saves and loads information for a booklet

#ifndef BOOKLET_WRITER_H
#define BOOKLET_WRITER_H

#include <string>
#include <vector>

#include "file_writer.h"

class BookletWriter : public FileWriter
{
  
public:
  BookletWriter(const std::string& filename);

  void save() const;
  void load();

  void setLine(int i, const std::string& data);
  std::string& getLine(int i);

private:
  
  std::string m_filename;
  
  std::vector<std::string> m_data;
};

#endif
