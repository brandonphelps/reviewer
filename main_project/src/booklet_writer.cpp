
#include <exception>
#include <fstream>

#include "booklet_writer.h"


BookletWriter::BookletWriter(const std::string& filename) : m_filename(filename)
{
}

void BookletWriter::setLine(int i, const std::string& data)
{
  if(i >= 0 && i < m_data.size())
  {
    m_data[i] = data;
  }
}

std::string& BookletWriter::getLine(int i)
{
  if(i >= 0 && i < m_data.size())
  {
    return m_data[i];
  }
  throw std::out_of_range("get line index");
}

void BookletWriter::save() const
{
  std::ofstream myfile;

  myfile.open(m_filename);

  for(int i = 0; i < m_data.size(); i++)
  {
    myfile << m_data[i];
  }
}

void BookletWriter::load()
{
  
}
