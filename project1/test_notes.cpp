#include <cassert>
#include <iostream>
#include <string>

#include "Card.cpp"
#include "CardDeck.cpp"


void carddeck_methods_test(){
	std::cout << "\n Hedge cases -> Insert " + random_heart.toString() + " at index getSize()+1" << std::endl;

	deck1.insert(random_heart, deck1.getSize()+1);
	std::cout << "deck1.getSize() : ";
	std::cout << deck1.getSize() << std::endl;
	std::cout << "deck1.getCapacity() : ";
	std::cout << deck1.getCapacity() << std::endl;
	std::cout << "deck1.isEmpty() : ";
	std::cout << deck1.isEmpty() << std::endl;
	std::cout << "deck1.toString() : ";
	std::cout << deck1.toString() << std::endl;
	assert((deck1.at(30)).toString() == random_heart.toString());
}


int main(){
  test1();
  return 0;
}
