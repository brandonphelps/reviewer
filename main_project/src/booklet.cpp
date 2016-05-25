
#include "booklet.h"
#include "item.h"

Booklet::Booklet(const std::string& filename) : m_filename(filename)
{
  std::ifstream infile(filename);

  std::string answer;
  std::string question;

  if(infile.is_open())
  {
    while(getline(infile, question))
    {
      getline(infile, answer);
      addItem(Item(question, answer));
    }
  }

  infile.close();
}

Booklet::Booklet(const Booklet& other)
{
  m_filename = other.m_filename;
  for(int i = 0; i < other.m_itemlist.size(); i++)
  {
    addItem(other.m_itemlist[i]);
  }
}

void Booklet::addItem(const Item& i)
{
  m_itemlist.push_back(Item(i));
}
