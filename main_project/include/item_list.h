
#ifndef ITEM_LIST_H
#define ITEM_LIST_H

#include "item.h"

#include <vector>

class ItemList
{
public:
  ItemList();
  
  // Description: Adds item i to the end of the list
  void addItem(const Item& i);

  // Description: Gets item from index i, or throws an out of range exception
  Item& getItem(int i);

  std::string serialize();

private:
  std::vector<Item> m_items;
};

#endif
