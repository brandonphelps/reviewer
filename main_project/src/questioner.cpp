
#include <random>
#include "questioner.h"

Questioner::Questioner(const Booklet& book) : m_booklet(book)
{
}

void Questioner::askQuestion()
{
  for(int i = 0; i < 100; i++)
  {
    std::cout << "mah number: " << random() % 10 << std::endl;
  }
  float k = random() % 10;

  std::cout << "my number: " << k << std::endl;
  std::cout << "my number: " << random() << std::endl;
  std::cout << "my number: " << random() << std::endl;
  std::cout << "my number: " << random() << std::endl;
  std::cout << "my number: " << random() << std::endl;
}
