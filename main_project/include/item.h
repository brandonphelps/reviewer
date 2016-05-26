
// Item is a class that will contain two strings
// a question and answer

#ifndef ITEM_H
#define ITEM_H

#include "serializable.h"
#include <iostream>
#include <string>

class Item
{
public:
  Item(const std::string& question, const std::string& answer);

  // Description: Copy constructor
  Item(const Item& i);

  std::string getQuestion() const;
  std::string getAnswer() const;

  int getAttempts() const;
  int getCorrect() const;

  int getLevel() const
  {
    return m_level;
  }
  
  int getScheduledTime() const
  {
    return m_scheduled_timestamp;
  }

  int getSuccession() const
  {
    return m_succession_correct;
  }

  void incAttempts();
  void incCorrect();

  void askQuestion();

  bool needsReview();

  friend std::istream& operator>>(std::istream& in, Item& item);

private:
  void scheduleNextReview();


private:

  int m_attempts; // number of tries to be answered correctly 
  int m_correct;  // number of times answered correctly

  int m_level;
  int m_succession_correct; // number of times answered correctly in succession
  int m_succession_wrong;
  
  // Description: time stamp for when the question was asked.
  //              time in seconds since epoch 
  time_t m_asked_timestamp; 

  time_t m_scheduled_timestamp;

  const std::string m_question;
  const std::string m_answer;

};

std::ostream& operator<<(std::ostream& out, const Item& item);

#endif
