
#include "booklet.h"
#include "item.h"


#include <exception>

Booklet::Booklet(const std::string& folder) : m_folder(folder),
                                              m_bookletconfig(m_folder)
{
  std::cout << "Loading first chapter" << std::endl;

  double level_count = 0;
  double total_count = 0;

  int chapter_level = 1;

  bool add_next_chapter = true;

  for(int i = 0; (i < m_bookletconfig.getChapters().size()) && add_next_chapter; i++)
  {
    std::cout << m_folder + "/" + m_bookletconfig.getChapters()[i] << std::endl;
    std::string filename = m_folder + "/" + m_bookletconfig.getChapters()[i];

    std::ifstream infile(filename.c_str());
    std::string answer;
    std::string question;

    if(infile.is_open())
    {
      while(getline(infile, question))
      {
        getline(infile, answer);

        Item current_item(question, answer);
        
        // if current chapter is less than the chapter level add the item
        if(i < chapter_level)
        {
          m_itemlist.push_back(current_item);
        }
        else // if not then we have reach the limit possible thus stop checking items
        {
          add_next_chapter = false;
        }
      }
      loadItemInformation();
      level_count = 0;
      total_count = 0;
      std::cout << "Checking Item info" << std::endl;
      for(int j = 0; j < m_itemlist.size(); j++)
      {
        std::cout << m_itemlist[j] << std::endl;
        if(m_itemlist[j].getLevel() >= 1)
        {
          level_count++;
        }
        total_count++;
      }
      if((level_count / total_count) >= 0.8)
      {
        chapter_level++;
      }
      std::cout << "Total level two and over: " << (level_count / total_count) << std::endl;
      std::cout << "Level count " << level_count << " : " << total_count << std::endl;
    }
    else
    {
      std::cout << "Could not find booklet " << filename << std::endl;
    }
    infile.close();
  }
}

Booklet::Booklet(const Booklet& other) : m_folder(other.m_folder),
                                         m_bookletconfig(m_folder)
{
  std::cout << "Booklet Copy constructor" << std::endl;
  for(int i = 0; i < other.m_itemlist.size(); i++)
  {
    m_itemlist.push_back(other.m_itemlist[i]);
  }
}

Item& Booklet::getItem(int i)
{
  if(i < 0 || i >= m_itemlist.size())
  {
    throw std::out_of_range("Indexing into booklet");
  }
  return m_itemlist[i];
}

const Item& Booklet::getItem(int i) const
{
  if(i < 0 || i >= m_itemlist.size())
  {
    throw std::out_of_range("Indexing into booklet");
  }
  return m_itemlist[i];
}


int Booklet::getSize() const
{
  return m_itemlist.size();
}

std::vector<int> Booklet::needReviews()
{
  std::vector<int> items;

  for(int i = 0; i < m_itemlist.size(); i++)
  {
    if(m_itemlist[i].needsReview())
    {
      items.push_back(i);
    }
  }

  return items;
}

void Booklet::loadItemInformation()
{
  std::string datafile = m_folder + ".dat";
  std::ifstream infile(datafile);

  std::string line;

  if(infile.is_open())
  {
    while(getline(infile, line))
    {
      for(int i = 0; i < m_itemlist.size(); i++)
      {
        if(m_itemlist[i].getQuestion() == line)
        {
          getline(infile, line);
          if(m_itemlist[i].getAnswer() == line)
          {
            infile >> m_itemlist[i];
          }
        }
      }
    }
  }
  infile.close();
}

void Booklet::saveItemInformation()
{
  std::string datafile = m_folder + ".dat";

  std::ofstream outfile(datafile);


  for(int i = 0 ; i < m_itemlist.size(); i++)
  {
    outfile << m_itemlist[i] << std::endl;
  }

  outfile.close();
}
 
std::ostream& operator<<(std::ostream& out, const Booklet& book)
{
  for(int i = 0; i < book.getSize() - 1; i++)
  {
    out << book.getItem(i) << std::endl;
  }
  out << book.getItem(book.getSize() - 1);

  return out;
}
