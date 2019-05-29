#include <cassert>
#include <iostream>
#include <string>

#include "Card.cpp"
#include "CardDeck.cpp"

void test1(){
	// CardDeck remove testing
	std::cout << "\n ~~deck3.remove(1)~~ \n" << std::endl;
	deck3.remove(1);
	std::cout << "\n DECK 3 : \n" << std::endl;
	for(int i = 0; i < deck3.getSize(); i++){
		std::cout << i << " ";
		std::cout << (deck3.at(i)).toString() << std::endl;
	}

	// CardDeck swap testing
	std::cout << "\n ~~deck3.swap(0,1)~~ \n" << std::endl;
	deck3.swap(0,2);
	std::cout << "\n DECK 3 : \n" << std::endl;
	for(int i = 0; i < deck3.getSize(); i++){
		std::cout << i << " ";
		std::cout << (deck3.at(i)).toString() << std::endl;
	}

	// has() testing
	std::cout << "\n ~~deck3.has() testing~~ \n" << std::endl;
	std::cout << "has " + card1.toString() + " : ";
	std::cout << deck3.has(card1) << std::endl;
	std::cout << "has " + card2.toString() + " : ";
	std::cout << deck3.has(card2) << std::endl;
	std::cout << "has " + card3.toString() + " : ";
	std::cout << deck3.has(card3) << std::endl;
	std::cout << "has " + card4.toString() + " : ";
	std::cout << deck3.has(card4) << std::endl;
	std::cout << "has " + card5.toString() + " : ";
	std::cout <<  deck3.has(card5) << std::endl;

	// count() testing
	deck4.add(card1);
	deck4.add(card2);
	deck4.add(card3);
	deck4.add(card4);
	deck4.add(card5);

	std::cout << "\n ~~deck4.count() testing~~ \n" << std::endl;
	std::cout << "count " + card1.toString() + " : ";
	std::cout << deck4.count(card1) << std::endl;
	std::cout << "count " + card2.toString() + " : ";
	std::cout << deck4.count(card2) << std::endl;
	std::cout << "count " + card3.toString() + " : ";
	std::cout << deck4.count(card3) << std::endl;
	std::cout << "count " + card4.toString() + " : ";
	std::cout << deck4.count(card4) << std::endl;
	std::cout << "count " + card5.toString() + " : ";
	std::cout << deck4.count(card5) << std::endl;

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

int main(){
  test1();
  return 0;
}
