

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
  
private:
  std::vector<Booklet> m_booklets;
  
};

#endif
