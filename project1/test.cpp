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

CardDeck random_deck(int size){
	CardDeck deck;

	while(deck.getSize() < size){
		int a = rand() % 12 + 1;
		int b = rand() % 12 + 1;
		int c = rand() % 12 + 1;
		int d = rand() % 12 + 1;

		if (deck.getSize() == size){ break; }
		deck.add(spades.at(a));
		if (deck.getSize() == size){ break; }
		deck.add(hearts.at(b));
		if (deck.getSize() == size){ break; }
		deck.add(clubs.at(c));
		if (deck.getSize() == size){ break; }
		deck.add(diamonds.at(d));
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

void carddeck_constructors_test(CardDeck deck){
	CardDeck deck1;
	CardDeck deck2(deck);
	CardDeck deck3;
	deck3 = deck;

	std::cout << "\n ====== CardDeck constructors testing ======" << std::endl;

	std::cout << "\n **** Empty deck :" << std::endl;
	std::cout << "deck1.getSize() : ";
	std::cout << deck1.getSize() << std::endl;
	std::cout << "deck1.getCapacity() : ";
	std::cout << deck1.getCapacity() << std::endl;
	std::cout << "deck1.isEmpty() : ";
	std::cout << deck1.isEmpty() << std::endl;
	std::cout << "deck1.toString() : ";
	std::cout << deck1.toString() << std::endl;

	std::cout << "\n **** User input deck :" << std::endl;
	std::cout << "deck.getSize() : ";
	std::cout << deck.getSize() << std::endl;
	std::cout << "deck.getCapacity() : ";
	std::cout << deck.getCapacity() << std::endl;
	std::cout << "deck.isEmpty() : ";
	std::cout << deck.isEmpty() << std::endl;
	std::cout << "deck.toString() : ";
	std::cout << deck.toString() << std::endl;

	std::cout << "\n **** Deck using copy constructor :" << std::endl;
	std::cout << "deck2.getSize() : ";
	std::cout << deck2.getSize() << std::endl;
	std::cout << "deck2.getCapacity() : ";
	std::cout << deck2.getCapacity() << std::endl;
	std::cout << "deck2.isEmpty() : ";
	std::cout << deck2.isEmpty() << std::endl;
	std::cout << "deck2.toString() : ";
	std::cout << deck2.toString() << std::endl;
	assert(deck2.toString() == deck.toString());

	std::cout << "\n **** Deck using assignment operator" << std::endl;
	std::cout << "deck3.getSize() : ";
	std::cout << deck3.getSize() << std::endl;
	std::cout << "deck3.getCapacity() : ";
	std::cout << deck3.getCapacity() << std::endl;
	std::cout << "deck3.isEmpty() : ";
	std::cout << deck3.isEmpty() << std::endl;
	std::cout << "deck3.toString() : ";
	std::cout << deck3.toString() << std::endl;
	assert(deck3.toString() == deck.toString());

}

void carddeck_methods_test(){
	int a = rand() % 12 + 1;
	int b = rand() % 12 + 1;
	int c = rand() % 12 + 1;
	int d = rand() % 12 + 1;

	Card random_spade = spades.at(a);
	Card random_heart = hearts.at(b);
	Card random_club = clubs.at(c);
	Card random_diamond = diamonds.at(d);

	Card KA("KING",1); 

	std::cout << "\n ====== CardDeck methods testing ======" << std::endl;

	std::cout << "\n **** Testing hitting capacity:" << std::endl;
	CardDeck deck1 = random_deck(26);
	std::cout << "deck1.getSize() : ";
	std::cout << deck1.getSize() << std::endl;
	std::cout << "deck1.getCapacity() : ";
	std::cout << deck1.getCapacity() << std::endl;
	std::cout << "deck1.isEmpty() : ";
	std::cout << deck1.isEmpty() << std::endl;
	std::cout << "deck1.toString() : ";
	std::cout << deck1.toString() << std::endl;

	std::cout << "\n **** Testing insert():" << std::endl;
	std::cout << "\n Standard cases -> Insert " + random_spade.toString() + " at index 2" << std::endl;
	deck1.insert(random_spade, 2);
	std::cout << "deck1.getSize() : ";
	std::cout << deck1.getSize() << std::endl;
	std::cout << "deck1.getCapacity() : ";
	std::cout << deck1.getCapacity() << std::endl;
	std::cout << "deck1.isEmpty() : ";
	std::cout << deck1.isEmpty() << std::endl;
	std::cout << "deck1.toString() : ";
	std::cout << deck1.toString() << std::endl;

	std::cout << "\n Hedge cases -> Insert " + random_diamond.toString() + " at index getSize() and then at index 0" << std::endl;
	deck1.insert(random_diamond, deck1.getSize());
	deck1.insert(random_diamond, 0);
	std::cout << "deck1.getSize() : ";
	std::cout << deck1.getSize() << std::endl;
	std::cout << "deck1.getCapacity() : ";
	std::cout << deck1.getCapacity() << std::endl;
	std::cout << "deck1.isEmpty() : ";
	std::cout << deck1.isEmpty() << std::endl;
	std::cout << "deck1.toString() : ";
	std::cout << deck1.toString() << std::endl;

	std::cout << "\n **** Testing replace():" << std::endl;
	std::cout << "\n Standard cases -> Copy deck1 to deck2 and replace every card in deck2 with " + KA.toString() << std::endl;
	CardDeck deck2(deck1);
	for (int i = 0; i < deck2.getSize(); i++){
		deck2.replace(KA, i);
	}
	std::cout << "deck2.getSize() : ";
	std::cout << deck2.getSize() << std::endl;
	std::cout << "deck2.getCapacity() : ";
	std::cout << deck2.getCapacity() << std::endl;
	std::cout << "deck2.isEmpty() : ";
	std::cout << deck2.isEmpty() << std::endl;
	std::cout << "deck2.toString() : ";
	std::cout << deck2.toString() << std::endl;

	std::cout << "\n **** Testing remove():" << std::endl;
	std::cout << "\n Standard cases -> Remove element at index 20" << std::endl;
	deck1.remove(20);
	std::cout << "deck1.getSize() : ";
	std::cout << deck1.getSize() << std::endl;
	std::cout << "deck1.getCapacity() : ";
	std::cout << deck1.getCapacity() << std::endl;
	std::cout << "deck1.isEmpty() : ";
	std::cout << deck1.isEmpty() << std::endl;
	std::cout << "deck1.toString() : ";
	std::cout << deck1.toString() << std::endl;

	std::cout << "\n Hedge cases -> Remove element at index getSize() - 1 then index 0" << std::endl;
	deck1.remove(deck1.getSize()-1);
	deck1.remove(0);
	std::cout << "deck1.getSize() : ";
	std::cout << deck1.getSize() << std::endl;
	std::cout << "deck1.getCapacity() : ";
	std::cout << deck1.getCapacity() << std::endl;
	std::cout << "deck1.isEmpty() : ";
	std::cout << deck1.isEmpty() << std::endl;
	std::cout << "deck1.toString() : ";
	std::cout << deck1.toString() << std::endl;

	std::cout << "\n **** Testing swap():" << std::endl;
	std::cout << "\n Standard cases -> swap elements at index 1 and 5" << std::endl;
	deck1.swap(1, 5);
	std::cout << "deck1.getSize() : ";
	std::cout << deck1.getSize() << std::endl;
	std::cout << "deck1.getCapacity() : ";
	std::cout << deck1.getCapacity() << std::endl;
	std::cout << "deck1.isEmpty() : ";
	std::cout << deck1.isEmpty() << std::endl;
	std::cout << "deck1.toString() : ";
	std::cout << deck1.toString() << std::endl;

	std::cout << "\n Hedge cases -> swap elements at index 0 and getSize()-1" << std::endl;
	deck1.swap(0, deck1.getSize()-1);
	std::cout << "deck1.getSize() : ";
	std::cout << deck1.getSize() << std::endl;
	std::cout << "deck1.getCapacity() : ";
	std::cout << deck1.getCapacity() << std::endl;
	std::cout << "deck1.isEmpty() : ";
	std::cout << deck1.isEmpty() << std::endl;
	std::cout << "deck1.toString() : ";
	std::cout << deck1.toString() << std::endl;

	std::cout << "\n **** Testing has():" << std::endl;
	std::cout << "deck1.toString() : ";
	std::cout << deck1.toString() << std::endl;
	std::cout << "has " + random_spade.toString() + " : ";
	std::cout << deck1.has(random_spade) << std::endl;
	std::cout << "has " + random_heart.toString() + " : ";
	std::cout << deck1.has(random_heart) << std::endl;
	std::cout << "has " + random_club.toString() + " : ";
	std::cout << deck1.has(random_club) << std::endl;
	std::cout << "has " + random_diamond.toString() + " : ";
	std::cout << deck1.has(random_diamond) << std::endl;


	std::cout << "\n **** Testing count():" << std::endl;
	std::cout << "deck1.toString() : ";
	std::cout << deck1.toString() << std::endl;
	std::cout << "count " + random_spade.toString() + " : ";
	std::cout << deck1.count(random_spade) << std::endl;
	std::cout << "count " + random_heart.toString() + " : ";
	std::cout << deck1.count(random_heart) << std::endl;
	std::cout << "count " + random_club.toString() + " : ";
	std::cout << deck1.count(random_club) << std::endl;
	std::cout << "count " + random_diamond.toString() + " : ";
	std::cout << deck1.count(random_diamond) << std::endl;

	std::cout << "\n **** Testing take():" << std::endl;
	std::cout << "Before take(5) deck1.toString() : ";
	std::cout << deck1.toString() << std::endl;
	CardDeck deck3 = deck1.take(5);
	std::cout << "After take(5) deck3.toString() : ";
	std::cout << deck3.toString() << std::endl;
	std::cout << "After take(5) deck.toString() : ";
	std::cout << deck1.toString() << std::endl;
}

int main(){
	CardDeck deck1 = random_deck(13);
	CardDeck deck2 = random_deck(13);
	CardDeck deck3 = random_deck(13);

	card_test("CLUB", 11);

	carddeck_constructors_test(deck1);
	carddeck_constructors_test(deck2);
	carddeck_constructors_test(deck3);

	carddeck_methods_test();

	return 0;
}