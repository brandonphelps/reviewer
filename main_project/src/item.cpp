
#include "item.h"

#include <iostream>

// dood duud

Item::Item(const std::string& question, const std::string& answer) : m_attempts(0),
                                                                     m_correct(0),
                                                                     m_question(question),
                                                                     m_answer(answer)
{
  
}

Item::Item(const Item& other) : m_attempts(other.m_attempts),
                                m_correct(other.m_correct),
                                m_question(other.m_question),
                                m_answer(other.m_answer)
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
