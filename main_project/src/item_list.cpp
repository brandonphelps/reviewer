

#include "item_list.h"
#include <exception>

ItemList::ItemList()
{
  
}

void ItemList::addItem(const Item& i)
{
  m_items.push_back(i);
}

Item& ItemList::getItem(int i)
{
  if(i < 0 || i >= m_items.size())
  {
    throw std::out_of_range("Attempting to get item");
  }

  return m_items[i];
}

std::string serialize()
{
  std::string data = "";


  return data;
}
