

#ifndef QUESTIONER_H
#define QUESTIONER_H

#include "booklet.h"

class Questioner
{
public:
  Questioner(const Booklet& book);

  void askQuestion();

private:
  Booklet m_booklet;
  
};

#endif
