#include <iostream>
#include <string>

#include "Card.cpp"
#include "CardDeck.cpp"

CardDeck create_cards(){
	Card c1("SPADE", 1);
	Card c2("SPADE", 2);
	Card c3("SPADE", 3);
	Card c4("SPADE", 4);
	Card c5("SPADE", 5);
	Card c6("SPADE", 6);
	Card c7("SPADE", 7);
	Card c8("SPADE", 8);
	Card c9("SPADE", 9);
	Card c10("SPADE", 10);
	Card c11("SPADE", 11);
	Card c12("SPADE", 12);
	Card c13("SPADE", 13);

	Card spades[13] = {c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13};

	CardDeck spades_deck;

	for(int i = 0; i < 13; i++){
		spades_deck.add(spades[i]);
	}

	return spades_deck;
}

int main(){
	CardDeck spades = create_cards();

	std::cout << spades.toString() << std::endl;

	return 0;
}