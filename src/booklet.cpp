

#include "booklet.h"

Booklet::Booklet(const std::string& filename)
{
  std::ifstream infile(filename);


  infile.close();
}
