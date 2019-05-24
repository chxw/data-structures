#include <cassert>
#include <iostream>
#include <string>

#include "Card.hpp"
#include "CardDeck.hpp"

void test1(){
  Card card("SPADE", 1);
  std::string name = card.toString();

  assert(name == "SA");
}

int main(){
  test1();
  return 0;
}
