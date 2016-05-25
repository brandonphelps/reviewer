
#include <random>
#include "questioner.h"

Questioner::Questioner(const Booklet& book) : m_booklet(book)
{

}

void Questioner::askQuestion()
{
  float k = random() % m_booklet.getSize();

  Item& item = m_booklet.getItem(k);

  std::cout << item.getQuestion() << std::endl;
  std::string answer;
  std::cin >> answer;
  
  if(answer != item.getAnswer())
  {
    std::cout << "Wrong!" << std::endl;


    std::cout << "Correct answer: " << item.getAnswer() << std::endl;
  }
  else
  {
    std::cout << "Correct!" << std::endl;
    item.incCorrect();
  }
  item.incAttempts();
}
