
#include "item.h"

#include <iostream>

// dood duud

Item::Item(const std::string& question, const std::string& answer) : m_question(question),
                                                                     m_answer(answer)
{
  
}

std::string Item::getQuestion() const
{
  return m_question;
}


std::string Item::getAnswer() const
{
  return m_answer;
}

std::ostream& operator<<(std::ostream& out, const Item& item)
{
  out << "Q: " << item.getQuestion() << std::endl;
  out << "A: " << item.getAnswer();
  return out;
}
