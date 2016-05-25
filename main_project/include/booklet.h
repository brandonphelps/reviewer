
#ifndef BOOKLET_H
#define BOOKLET_H

#include <iostream>
#include <fstream>
#include <vector>

#include "item.h"

class Booklet
{
public:
  Booklet(const std::string& filename);
  Booklet(const Booklet& other);

  void addItem(const Item& i);

private:
  std::vector<Item> m_itemlist;
  std::string m_filename;
};

std::ostream& operator<<(std::ostream& out, const Item& item);

#endif
