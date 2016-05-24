
#ifndef FILE_WRITER_H
#define FILE_WRITER_H

class FileWriter
{
public:
  virtual void save() const = 0;
  virtual void load() = 0;
};

#endif
