

// saves and loads information for a booklet

#ifndef BOOKLET_WRITER_H
#define BOOKLET_WRITER_H

#include "file_writer.h"

class BookletWriter : public FileWriter
{
  
public:
  BookletWriter(const std::string& filename);


  void save() const;
  void load();

private:
  
  std::string m_filename;
  

};

#endif
