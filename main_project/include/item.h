
// Item is a class that will contain two strings
// a question and answer

#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item
{
public:
  Item(const std::string& question, const std::string& answer);

  std::string getQuestion() const;
  std::string getAnswer() const;

private:

  int m_attempts; // number of tries to be answered correctly 
  int m_correct;  // number of times answered correctly

  std::string m_question;
  std::string m_answer;
};

#endif
