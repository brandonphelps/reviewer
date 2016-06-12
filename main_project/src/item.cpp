
#include "item.h"
#include "time_table.h"
#include <time.h>
#include <iostream>

// dood duud

Item::Item(const std::string& question, const std::string& answer) : m_attempts(0),
                                                                     m_correct(0),
                                                                     m_level(0),
                                                                     m_succession_correct(0),
                                                                     m_next_apperance(0),
                                                                     m_asked_timestamp(0),
                                                                     m_scheduled_timestamp(0),
                                                                     m_question(question),
                                                                     m_answer(answer)
{
  
}

Item::Item(const Item& other) : m_attempts(other.m_attempts),
                                m_correct(other.m_correct),
                                m_level(other.m_level),
                                m_succession_correct(other.m_succession_correct),
                                m_next_apperance(other.m_next_apperance),
                                m_asked_timestamp(other.m_asked_timestamp),
                                m_scheduled_timestamp(other.m_scheduled_timestamp),
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

int Item::getAttempts() const
{
  return m_attempts;
}

int Item::getCorrect() const
{
  return m_correct;
}

void Item::incAttempts()
{
  m_attempts++;
}

void Item::incCorrect()
{
  m_correct++;
  if(m_succession_correct >= 4)
  {
    m_succession_correct = 0;
    m_level++;
  }
  m_succession_correct++;
  m_succession_wrong = 0;
}

void Item::askQuestion()
{
  std::string answer;

  std::cout << getQuestion() << std::endl;
  std::cin >> answer;

  if(answer == getAnswer())
  {
    std::cout << "Correct!" << std::endl;
    incCorrect();
  }
  else
  {
    std::cout << "Wrong!" << std::endl;
    std::cout << "Correct answer: " << getAnswer() << std::endl;
    m_succession_correct = 0;
    m_succession_wrong++;
    if(m_succession_wrong >= 4)
    {
      m_succession_wrong = 0;
      m_level--;
    }
  }
  incAttempts();

  time(&m_asked_timestamp);
  scheduleNextReview();
}

bool Item::needsReview()
{
  return needsReview(0);
}

bool Item::needsReview(int range)
{
  time_t current_time;
  time(&current_time);

  if(m_scheduled_timestamp - current_time <= range)
  {
    return true;
  }
  else
  {
    return false;
  }
}

void Item::scheduleNextReview()
{
  m_next_apperance = computeTime(m_level, m_succession_correct);

  m_scheduled_timestamp = m_asked_timestamp + m_next_apperance;
}

std::ostream& operator<<(std::ostream& out, const Item& item)
{
  out << item.getQuestion() << std::endl;
  out << item.getAnswer() << std::endl;

  out << item.getAttempts() << std::endl;
  out << item.getCorrect() << std::endl;

  out << item.getLevel() << std::endl;
  out << item.getSuccession() << std::endl;

  out << item.getScheduledTime();

  return out;
}

std::istream& operator>>(std::istream& in, Item& item)
{
  in >> item.m_attempts;
  in >> item.m_correct;

  in >> item.m_level;
  in >> item.m_succession_correct;

  in >> item.m_scheduled_timestamp;
  return in;
}
