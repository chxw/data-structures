#include "CardDeck.hpp"

//default constructor
CardDeck::CardDeck(){
	capacity = 13;
	size = 0;
	cards = new Card[capacity];
}

//non-default constructor
CardDeck::CardDeck(const CardDeck& other) {
	capacity = other.getCapacity();
	size = other.getSize();
	cards = new Card[capacity];
	for(int i=0; i<size; i++){
		cards[i] = other.at(i);
	}
}

//copy constructor
CardDeck& CardDeck::operator=(const CardDeck& other){
	capacity = other.getCapacity();
	size = other.getSize();
	cards = new Card[capacity];
	for(int i=0; i<size; i++){
		cards[i] = other.at(i);
	}
	return (*this);
}


CardDeck::~CardDeck(){
	delete [] cards;
}

int CardDeck::getSize() const{
	return size;
}

int CardDeck::getCapacity() const{
	return capacity;
}

Card CardDeck::at(int index) const{
	return cards[index];
}

bool isEmpty() const{
	if (size == 0){
		return true;
	}
	return false;
}

void add(Card card){
	cards[size] = card;
	size++;
}

void insert(Card card, int at){
	cards[at] = card;
	size++; 
}

// void replace(Card card, int at);
// void remove(int index);
// void swap(int i, int j);

// bool has(Card card) const;
// int count(Card card) const;

// CardDeck take(int n);
// std::string toString() const;