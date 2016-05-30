

#ifndef QUESTIONER_H
#define QUESTIONER_H

#include "booklet.h"

#include <vector>

class Questioner
{
public:

  Questioner();

  void addBooklet(const Booklet& book);

  void askQuestion();

  void performReview();

  void save();

  // Description: List number of items that will be in review in a 5 minutes
  void nextItems();
  
private:
  std::vector<Booklet> m_booklets;
  
};

#endif
