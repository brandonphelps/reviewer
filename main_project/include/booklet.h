
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

  Item& getItem(int i);
  const Item& getItem(int i) const;

  int getSize() const;

  std::vector<int> needReviews();

  // Description: Loads all other information for the each of the items from a data file
  void loadItemInformation();
  
  void saveItemInformation();

private:

private:
  std::vector<Item> m_itemlist;

  std::string m_filename;
};

std::ostream& operator<<(std::ostream& out, const Booklet& book);

#endif
