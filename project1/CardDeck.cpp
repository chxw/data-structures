#include "CardDeck.hpp"

//default constructor
CardDeck::CardDeck(){
	capacity = 13
	size = 0
	cards = new Card[capacity]
}

//non-default constructor
CardDeck::CardDeck(const CardDeck& other) {
	capacity = other.getCapacity()
	size = other.getSize()
	cards = new Card[capacity]
	for(int i=0; i<size; i++){
		cards.append(other.at(i))
	}
}

//copy constructor
CardDeck& CardDeck::operator=(const CardDeck& other){
	capacity = other.getCapacity()
	size = other.getSize()
	cards = new Card[capacity]
	for(int i=0; i<size; i++){
		cards.append(other.at(i))
	}
}


~CardDeck();

int getSize() const;
int getCapacity() const;

Card at(int index) const;
bool isEmpty() const;

void add(Card card);
void insert(Card card, int at);
void replace(Card card, int at);
void remove(int index);
void swap(int i, int j);

bool has(Card card) const;
int count(Card card) const;

CardDeck take(int n);
std::string toString() const;