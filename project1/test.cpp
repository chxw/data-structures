#include <cassert>
#include <iostream>
#include <string>

// #include "Card.hpp"
#include "Card.cpp"
// #include "CardDeck.hpp"

void test1(){
  Card card("SPADE", 1);
  card.toString();
  std::string name = card.toString();

  std::cout << card.getSuit() << std::endl;
  std::cout << card.getNumber() << std::endl;
  std::cout << name << std::endl;

  assert(name == "SA");
}

int main(){
  test1();
  return 0;
}
