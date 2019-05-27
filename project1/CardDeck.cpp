#include "CardDeck.hpp"

//default constructor
CardDeck::CardDeck(){
	capacity = 13;
	size = 0;
	Card *cards = new Card[size];
}

//non-default constructor
CardDeck::CardDeck(const CardDeck& other) {
	std::cout << "here" << std::endl;
	capacity = other.getCapacity();
	size = other.getSize();
	std::cout << size << std::endl;
	Card *cards = new Card[size];
	for(int i=0; i<size; i++){
		std::cout << i << std::endl;
		std::cout << (other.at(i)).toString() << std::endl;
		cards[i] = other.at(i);
	}
}

//copy constructor
CardDeck& CardDeck::operator=(const CardDeck& other){
	capacity = other.getCapacity();
	size = other.getSize();
	Card *cards = new Card[size];
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

bool CardDeck::isEmpty() const{
	if (size == 0){
		return true;
	}
	return false;
}

void CardDeck::add(Card card){
	Card *temp = new Card[size+1];

	for (int i = 0; i<size; i++){
		temp[i] = cards[i];
	}

	delete[] cards;
	cards = temp;
	temp = NULL;

	cards[size] = card;
	size++;
}

void CardDeck::insert(Card card, int at){
	if (size == 0) {
		cards[at] = card;
		return;
	}
	Card *temp = new Card[capacity];
	for(int i = 0; i < at; i++){
		temp[i] = cards[i];
	}
	temp[at] = card;
	for(int i = at+1; i < size+1; i++){
		temp[i] = cards[i-1];
	}

	delete[] cards;
	cards = temp;
	temp = NULL;
	size++;
}

// void replace(Card card, int at);
// void remove(int index);
// void swap(int i, int j);

// bool has(Card card) const;
// int count(Card card) const;

// CardDeck take(int n);
// std::string toString() const;