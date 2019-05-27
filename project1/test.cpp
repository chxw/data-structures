#include <cassert>
#include <iostream>
#include <string>

// #include "Card.hpp"
#include "Card.cpp"
#include "CardDeck.cpp"

void test1(){
	// Card class testing
	Card card1;
	std::string name1 = card1.toString();
	// std::cout << card1.getSuit() << std::endl;
	// std::cout << card1.getNumber() << std::endl;
	std::cout << "card 1 : ";
	std::cout << name1 << std::endl;

	Card card2("CLUB", 11);
	std::string name2 = card2.toString();
	// std::cout << card2.getSuit() << std::endl;
	// std::cout << card2.getNumber() << std::endl;
	std::cout << "card 2 : ";
	std::cout << name2 << std::endl;

	Card card3("DIAMOND", 12);
	std::cout << "card 3 : ";
	std::string name3 = card3.toString();
	std::cout << name3 << std::endl;

	Card card4 = card3;
	std::string name4 = card4.toString();
	// std::cout << card2.getSuit() << std::endl;
	// std::cout << card2.getNumber() << std::endl;
	std::cout << "card 4 : ";
	std::cout << name4 << std::endl;

	// CardDeck class testing

	CardDeck deck;

	// std::cout << deck.getSize() << std::endl;
	// std::cout << deck.getCapacity() << std::endl;
	// std::cout << deck.isEmpty() << std::endl;

	deck.add(card1); 
	deck.add(card2); 
	deck.add(card3);

	// card1, card2, card3

	std::cout << deck.getSize() << std::endl;
	std::cout << deck.getCapacity() << std::endl;
	std::cout << deck.isEmpty() << std::endl;

	deck.insert(card2, 0);

	// card2, card1, card2, card3

	for(int i = 0; i < deck.getSize(); i++){
		std::cout << i << " ";
		std::cout << (deck.at(i)).toString() << std::endl;
	}

	CardDeck deck2(deck);

	std::cout << deck.getSize() << std::endl;
	std::cout << deck.getCapacity() << std::endl;
	std::cout << deck.isEmpty() << std::endl;

	for(int i = 0; i < deck2.getSize(); i++){
		std::cout << i << " ";
		std::cout << (deck2.at(i)).toString() << std::endl;
	}


	// std::cout << (deck.at(0)).toString() << std::endl;
	// std::cout << (deck.at(1)).toString() << std::endl;


	// assert(name == "SA");
}

int main(){
  test1();
  return 0;
}
