#include <cassert>
#include <iostream>
#include <string>

#include "Card.cpp"
#include "CardDeck.cpp"

void test1(){
	// Card class testing

	// Card default constructor
	std::cout << "\n ~~Initialize card1, card2, card3, card4~~ \n" << std::endl;
	Card card1;
	std::string name1 = card1.toString();
	// std::cout << card1.getSuit() << std::endl;
	// std::cout << card1.getNumber() << std::endl;
	std::cout << "card 1 : ";
	std::cout << name1 << std::endl;

	// Card non-default constructor testing
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

	// Card copy constructor testing
	Card card4 = card3;
	std::string name4 = card4.toString();
	// std::cout << card2.getSuit() << std::endl;
	// std::cout << card2.getNumber() << std::endl;
	std::cout << "card 4 : ";
	std::cout << name4 << std::endl;

	// CardDeck class testing
	CardDeck deck;

	std::cout << "\n ~~Deck initialized, no cards added~~ \n" << std::endl;
	std::cout << "\n DECK : \n" << std::endl;
	std::cout << "deck.getSize() : ";
	std::cout << deck.getSize() << std::endl;
	std::cout << "deck.getCapacity() : ";
	std::cout << deck.getCapacity() << std::endl;
	std::cout << "deck.isEmpty() : ";
	std::cout << deck.isEmpty() << std::endl;

	// add() testing
	std::cout << "\n ~~Adding 3 cards to deck~~ \n" << std::endl; // card1, card2, card3
	deck.add(card1); 
	deck.add(card2); 
	deck.add(card3);

	std::cout << "\n DECK : \n" << std::endl;
	std::cout << "deck.getSize() : ";
	std::cout << deck.getSize() << std::endl;
	std::cout << "deck.getCapacity() : ";
	std::cout << deck.getCapacity() << std::endl;
	std::cout << "deck.isEmpty() : ";
	std::cout << deck.isEmpty() << std::endl;

	std::cout << "\n ~~Insert card2 to deck at index 0~~ \n" << std::endl; // card2, card1, card2, card3
	deck.insert(card2, 0);

	std::cout << "\n DECK : \n" << std::endl;
	for(int i = 0; i < deck.getSize(); i++){
		std::cout << i << " ";
		std::cout << (deck.at(i)).toString() << std::endl;
	}

	// copy constructor testing
	std::cout << "\n ~~Initializing deck2 using deck~~ \n" << std::endl;
	CardDeck deck2(deck);

	std::cout << "\n DECK 2 : \n" << std::endl;
	std::cout << "deck2.getSize() : ";
	std::cout << deck2.getSize() << std::endl;
	std::cout << "deck2.getCapacity() : ";
	std::cout << deck2.getCapacity() << std::endl;
	std::cout << "deck2.isEmpty() : ";
	std::cout << deck2.isEmpty() << std::endl;

	for(int i = 0; i < deck2.getSize(); i++){
		std::cout << i << " ";
		std::cout << (deck2.at(i)).toString() << std::endl;
	}

	// CardDeck copy constructor testing
	std::cout << "\n ~~Initializing deck3, deck4, deck5~~ \n" << std::endl;
	CardDeck deck3, deck4, deck5;
	std::cout << "\n ~~ deck3 = deck2; deck4 = deck5 ~~ \n" << std::endl;
	deck3 = deck2;
	deck4 = deck5;

	std::cout << "\n DECK 3 : \n" << std::endl;
	std::cout << "deck3.getSize() : ";
	std::cout << deck3.getSize() << std::endl;
	std::cout << "deck3.getCapacity() : ";
	std::cout << deck3.getCapacity() << std::endl;
	std::cout << "deck3.isEmpty() : ";
	std::cout << deck3.isEmpty() << std::endl;

	for(int i = 0; i < deck3.getSize(); i++){
		std::cout << i << " ";
		std::cout << (deck3.at(i)).toString() << std::endl;
	}

	std::cout << "\n DECK 4 : \n" << std::endl;
	std::cout << "deck4.getSize() : ";
	std::cout << deck4.getSize() << std::endl;
	std::cout << "deck4.getCapacity() : ";
	std::cout << deck4.getCapacity() << std::endl;
	std::cout << "deck4.isEmpty() : ";
	std::cout << deck4.isEmpty() << std::endl;

	for(int i = 0; i < deck4.getSize(); i++){
		std::cout << i << " ";
		std::cout << (deck4.at(i)).toString() << std::endl;
	}

	std::cout << "\n DECK 5 : \n" << std::endl;
	std::cout << "deck5.getSize() : ";
	std::cout << deck5.getSize() << std::endl;
	std::cout << "deck5.getCapacity() : ";
	std::cout << deck5.getCapacity() << std::endl;
	std::cout << "deck5.isEmpty() : ";
	std::cout << deck5.isEmpty() << std::endl;

	for(int i = 0; i < deck5.getSize(); i++){
		std::cout << i << " ";
		std::cout << (deck5.at(i)).toString() << std::endl;
	}

	// CardDeck replace() testing
	std::cout << "\n ~~Initialize card 5~~ \n" << std::endl;
	Card card5("HEART", 13);
	std::string name5 = card5.toString();
	// std::cout << card2.getSuit() << std::endl;
	// std::cout << card2.getNumber() << std::endl;
	std::cout << "card 5 : ";
	std::cout << name5 << std::endl;

	std::cout << "\n ~~deck3.replace(card5, 2)~~ \n" << std::endl;
	deck3.replace(card5, 2);

	std::cout << "\n DECK 3 : \n" << std::endl;
	for(int i = 0; i < deck3.getSize(); i++){
		std::cout << i << " ";
		std::cout << (deck3.at(i)).toString() << std::endl;
	}

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

	// take() testing
	deck4.add(card1);
	deck4.add(card2);
	deck4.add(card3);
	deck4.add(card4);
	deck4.add(card5);
	std::cout << "\n DECK 4 : \n" << std::endl;
	for(int i = 0; i < deck4.getSize(); i++){
		std::cout << i << " ";
		std::cout << (deck4.at(i)).toString() << std::endl;
	}

	CardDeck deck6 = deck4.take(3);
	std::cout << "\n DECK 6 : \n" << std::endl;
	for(int i = 0; i < deck6.getSize(); i++){
		std::cout << i << " ";
		std::cout << (deck6.at(i)).toString() << std::endl;
	}

	// count() testing
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
	std::cout <<  deck4.count(card5) << std::endl;

}

int main(){
  test1();
  return 0;
}
