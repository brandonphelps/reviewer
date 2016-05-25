
#include <random>
#include "questioner.h"

Questioner::Questioner(const Booklet& book) : m_booklet(book)
{
}

void Questioner::askQuestion()
{
  srand(0);

  random.rand(0, 10);
}
