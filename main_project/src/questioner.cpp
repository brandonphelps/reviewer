
#include <random>
#include "questioner.h"

Questioner::Questioner()
{
}

void Questioner::addBooklet(const Booklet& book)
{
  std::cout << "Adding booklet" << std::endl;
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
  int half_count = 0;
  int one_count = 0;
  int five_count = 0;
  int ten_count = 0;
  for(int i = 0; i < m_booklets.size(); i++)
  {
    for(int j = 0; j < m_booklets[i].getSize(); j++)
    {
      if(m_booklets[i].getItem(j).needsReview(30))
      {
        half_count++;
      }
      if(m_booklets[i].getItem(j).needsReview(60))
      {
        one_count++;
      }
      if(m_booklets[i].getItem(j).needsReview(300))
      {
        five_count++;
      }
      if(m_booklets[i].getItem(j).needsReview(600))
      {
        ten_count++;
      }
    }
  }
  std::cout << "Forcast" << std::endl;
  std::cout << "Items to review in 30 seconds: " << half_count << std::endl;
  std::cout << "Itmes to review in 1 minute: " << one_count << std::endl;
  std::cout << "Items to review in 5 minutes: " << five_count << std::endl;
  std::cout << "Items to review in 10 minutes: " << ten_count << std::endl;
}
