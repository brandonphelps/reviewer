
// Item is a class that will contain two strings
// a question and answer

#ifndef ITEM_H
#define ITEM_H

#include "serializable.h"
#include <string>

class Item
{
public:
  Item(const std::string& question, const std::string& answer);

  // Description: Copy constructor
  Item(const Item& i);

  std::string getQuestion() const;
  std::string getAnswer() const;


  void incAttempts()
  {
    m_attempts++;
  }

  void incCorrect()
  {
    m_correct++;
  }

private:

  int m_attempts; // number of tries to be answered correctly 
  int m_correct;  // number of times answered correctly

  const std::string m_question;
  const std::string m_answer;
};

#endif
