
#include <random>
#include "questioner.h"

Questioner::Questioner()
{
}

void Questioner::addBooklet(const Booklet& book)
{
  m_booklets.push_back(book);
}

void Questioner::askQuestion()
{
  float randBooklet = random() % m_booklets.size();

  float k = random() % m_booklets[randBooklet].getSize();

  Item& item = m_booklets[randBooklet].getItem(k);

  item.askQuestion();
}

void Questioner::performReview()
{
  std::cout << "Performing Review" << std::endl;
  std::vector<Item*> items;

  for(int i = 0; i < m_booklets.size(); i++)
  {
    for(int j = 0; j < m_booklets[i].getSize(); j++)
    {
      if(m_booklets[i].getItem(j).needsReview())
      {
        items.push_back(&m_booklets[i].getItem(j));
      }
    }
  }

  // randomize the selection order of the items
  for(int i = 1; i < items.size(); i++)
  {
    int rand_index = rand() % i;

    Item* temp = items[i];
    items[i] = items[rand_index];
    items[rand_index] = temp;
  }

  bool saved = false;

  for(int i = 0; i < items.size(); i++)
  {
    items[i]->askQuestion();
    saved = false;
    if(i % 5 == 0)
    {
      save();
      saved = true;
    }
  }

  if(!saved)
  {
    save();
  }

  if(items.size() == 0)
  {
    nextItems();
  }
}

void Questioner::save()
{
  for(int i = 0; i < m_booklets.size(); i++)
  {
    m_booklets[i].saveItemInformation();
  }
}

void Questioner::nextItems()
{
  std::cout << "Checking for next items" << std::endl;
  int count = 0;
  for(int i = 0; i < m_booklets.size(); i++)
  {
    for(int j = 0; j < m_booklets[i].getSize(); j++)
    {
      if(m_booklets[i].getItem(j).needsReview(600))
      {
        std::cout << "Item" << std::endl << m_booklets[i].getItem(j) << std::endl;
        count++;
      }
    }
  }
  std::cout << "Items to review in 10 minutes: " << count << std::endl;
}
