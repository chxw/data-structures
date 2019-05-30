#include <cassert>
#include <iostream>
#include <string>

#include "Card.cpp"
#include "CardDeck.cpp"

void test1(){
	// take() testing
	std::cout << "\n ~~take() testing~~ \n" << std::endl;
	std::cout << "\n ~~before take(3)~~ \n" << std::endl;
	std::cout << "\n DECK 4 : \n" << std::endl;
	for(int i = 0; i < deck4.getSize(); i++){
		std::cout << i << " ";
		std::cout << (deck4.at(i)).toString() << std::endl;
	}

	std::cout << "\n ~~after take(3)~~ \n" << std::endl;
	CardDeck deck6 = deck4.take(3);
	std::cout << "\n DECK 6 : \n" << std::endl;
	for(int i = 0; i < deck6.getSize(); i++){
		std::cout << i << " ";
		std::cout << (deck6.at(i)).toString() << std::endl;
	}

	std::cout << "\n DECK 4 : \n" << std::endl;
	for(int i = 0; i < deck4.getSize(); i++){
		std::cout << i << " ";
		std::cout << (deck4.at(i)).toString() << std::endl;
	}

	// std::cout << deck4.toString();

}

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
