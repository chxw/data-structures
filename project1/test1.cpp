#include <iostream>
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

int main(){
	CardDeck deck1 = random_deck();
	CardDeck deck2 = random_deck();
	CardDeck deck3 = random_deck();

	return 0;
}