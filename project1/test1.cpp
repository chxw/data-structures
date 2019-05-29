#include <iostream>
#include <cassert>
#include <string>
#include <stdlib.h>     /* srand, rand */

#include "Card.cpp"
#include "CardDeck.cpp"

std::string s = "SPADE";
std::string h = "HEARTS";
std::string c = "CLUBS";
std::string d = "DIAMONDS";

CardDeck create_suit(std::string s){
	std::string suit = s;

	Card c1(suit, 1);
	Card c2(suit, 2);
	Card c3(suit, 3);
	Card c4(suit, 4);
	Card c5(suit, 5);
	Card c6(suit, 6);
	Card c7(suit, 7);
	Card c8(suit, 8);
	Card c9(suit, 9);
	Card c10(suit, 10);
	Card c11(suit, 11);
	Card c12(suit, 12);
	Card c13(suit, 13);

	Card cards[13] = {c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13};

	CardDeck deck;

	for(int i = 0; i < 13; i++){
		deck.add(cards[i]);
	}

	return deck;
}

CardDeck spades = create_suit(s);
CardDeck hearts = create_suit(h);
CardDeck clubs = create_suit(c);
CardDeck diamonds = create_suit(d);

CardDeck random_deck(){
	CardDeck deck;

	int count = 0;
	while(count < 12){
		int a = rand() % 13 + 1;
		deck.add(spades.at(a));
		int b = rand() % 13 + 1;
		deck.add(hearts.at(b));
		int c = rand() % 13 + 1;
		deck.add(clubs.at(c));
		int d = rand() % 13 + 1;
		deck.add(diamonds.at(d));
		count += 4;
	}

	return deck;
}

void card_test(std::string s, int r){
	Card card1;

	std::cout << "\n ====== Card testing ======" << std::endl;

	std::cout << "\n **** Default contructor :" << std::endl;	
	std::cout << "toString() : ";
	std:: string name1 = card1.toString();
	std::cout << name1 << std::endl;
	std::cout << "getSuit() + getNumber() : ";
	std::cout << card1.getSuit();
	std::cout << card1.getNumber() << std::endl;

	std::cout << "\n **** Non-default contructor :" << std::endl;	
	Card card2(s, r);
	std::cout << "toString() : ";
	std:: string name2 = card2.toString();
	std::cout << name2 << std::endl;
	std::cout << "getSuit() + getNumber() : ";
	std::cout << card2.getSuit();
	std::cout << card2.getNumber() << std::endl;

	std::cout << "\n **** Copy constructor :" << std::endl;	
	Card card3(card2);
	std::cout << "toString() : ";
	std:: string name3 = card3.toString();
	std::cout << name3 << std::endl;
	std::cout << "getSuit() + getNumber() : ";
	std::cout << card3.getSuit();
	std::cout << card3.getNumber() << std::endl;
	assert(card3.equals(card2));

	std::cout << "\n **** Assignment operator :" << std::endl;	
	Card card4;
	card4 = card1;
	std::cout << "toString() : ";
	std:: string name4 = card4.toString();
	std::cout << name4 << std::endl;
	std::cout << "getSuit() + getNumber() : ";
	std::cout << card4.getSuit();
	std::cout << card4.getNumber() << std::endl;
	assert(card4.equals(card1));
}

void carddeck_test(CardDeck deck){
	CardDeck deck1;
	CardDeck deck2(deck);
	CardDeck deck3;
	deck3 = deck;

	std::cout << "\n ====== CardDeck testing ======" << std::endl;

	std::cout << "\n **** Empty deck :" << std::endl;
	std::cout << "deck1.getSize() : ";
	std::cout << deck1.getSize() << std::endl;
	std::cout << "deck1.getCapacity() : ";
	std::cout << deck1.getCapacity() << std::endl;
	std::cout << "deck1.isEmpty() : ";
	std::cout << deck1.isEmpty() << std::endl;

	std::cout << "\n **** User input deck :" << std::endl;
	std::cout << "deck.getSize() : ";
	std::cout << deck.getSize() << std::endl;
	std::cout << "deck.getCapacity() : ";
	std::cout << deck.getCapacity() << std::endl;
	std::cout << "deck.isEmpty() : ";
	std::cout << deck.isEmpty() << std::endl;

	std::cout << "\n **** Deck using copy constructor :" << std::endl;
	std::cout << "deck2.getSize() : ";
	std::cout << deck2.getSize() << std::endl;
	std::cout << "deck2.getCapacity() : ";
	std::cout << deck2.getCapacity() << std::endl;
	std::cout << "deck2.isEmpty() : ";
	std::cout << deck2.isEmpty() << std::endl;

	std::cout << "\n **** Deck using assignment operator" << std::endl;
	std::cout << "deck3.getSize() : ";
	std::cout << deck3.getSize() << std::endl;
	std::cout << "deck3.getCapacity() : ";
	std::cout << deck3.getCapacity() << std::endl;
	std::cout << "deck3.isEmpty() : ";
	std::cout << deck3.isEmpty() << std::endl;
}


int main(){
	CardDeck deck1 = random_deck();
	CardDeck deck2 = random_deck();
	CardDeck deck3 = random_deck();

	card_test("CLUB", 11);

	carddeck_test(deck1);
	carddeck_test(deck2);
	carddeck_test(deck3);

	return 0;
}