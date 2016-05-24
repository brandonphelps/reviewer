

#include "booklet.h"
#include "item.h"

Booklet::Booklet(const std::string& filename)
{
  std::ifstream infile(filename);

  std::string answer;
  std::string question;

  if(infile.is_open())
  {
    while(getline(infile, question))
    {
      std::cout << "Q: " << question << std::endl;
      getline(infile, answer);
      std::cout << "A: " << answer << std::endl;

      addItem(Item(question, answer));
    }
  }

  infile.close();
}

void Booklet::addItem(const Item& i)
{
  std::cout << "Adding item: " << i << std::endl;
  m_itemlist.push_back(i);
}
