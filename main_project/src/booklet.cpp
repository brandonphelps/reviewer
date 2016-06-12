
#include "booklet.h"
#include "item.h"


#include <exception>

Booklet::Booklet(const std::string& filename) : m_filename(filename)
{
  std::ifstream infile(filename.c_str());

  std::string answer;
  std::string question;

  if(infile.is_open())
  {
    while(getline(infile, question))
    {
      getline(infile, answer);
      m_itemlist.push_back(Item(question, answer));
    }
  }

  loadItemInformation();

  infile.close();
}

Booklet::Booklet(const Booklet& other)
{
  m_filename = other.m_filename;
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
  std::string datafile = m_filename + ".dat";
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
  std::string datafile = m_filename + ".dat";

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
