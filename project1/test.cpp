#include <cassert>
#include <iostream>
#include <string>

// #include "Card.hpp"
#include "Card.cpp"
#include "CardDeck.cpp"

void test1(){
	Card card1;
	card1.toString();
	std::string name1 = card1.toString();
 
	std::cout << card1.getSuit() << std::endl;
	std::cout << card1.getNumber() << std::endl;
	std::cout << name1 << std::endl;

	Card card2("CLUB", 11);
	card2.toString();
	std::string name2 = card2.toString();
 
	std::cout << card2.getSuit() << std::endl;
	std::cout << card2.getNumber() << std::endl;
	std::cout << name2 << std::endl;

	CardDeck deck;

	std::cout << deck.getSize() << std::endl;
	std::cout << deck.getCapacity() << std::endl;
	std::cout << (deck.at(0)).toString() << std::endl;

	// assert(name == "SA");
}

int main(){
  test1();
  return 0;
}
