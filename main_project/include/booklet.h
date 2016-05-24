
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

  void addItem(const Item& i);

private:
  std::vector<Item> m_itemlist;
};

std::ostream& operator<<(std::ostream& out, const Item& item);

#endif
