#include "CardDeck.hpp"

//default constructor
CardDeck::CardDeck(){
	capacity = 13;
	size = 0;
	cards = new Card[size];
}

//copy constructor
CardDeck::CardDeck(const CardDeck& other) {
	capacity = other.getCapacity();
	size = other.getSize();
	cards = new Card[size];

	for(int i=0; i<size; i++){
		cards[i] = other.cards[i];
	}
}

//assignment operator
CardDeck& CardDeck::operator=(const CardDeck& other){
	if (&other != this){
		delete [] cards;
		capacity = other.getCapacity();	
		size = other.getSize();
		cards = new Card[size];

		for(int i=0; i<size; i++){
			cards[i] = other.cards[i];
		}
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

void CardDeck::replace(Card card, int at){
	cards[at] = card;
}

void CardDeck::remove(int index){
	Card *temp = new Card[size-1];

	for(int i = 0; i < index; i++){
		temp[i] = cards[i];
	}

	for(int i = index; i < size-1; i++){
			temp[i] = cards[i+1];
		}

	delete[] cards;
	cards = temp;
	temp = NULL;

	size--;
}

void CardDeck::swap(int i, int j){
	Card i_card = cards[i];
	Card j_card = cards[j];

	cards[i] = j_card;
	cards[j] = i_card;
}

bool has(Card card) const{
	for(int i = 0; i < size; i++){
		if (cards[i] == card){
			return true
		}
	}
	return false;
}

int count(Card card) const{
	int count = 0;

	for(int i = 0; i < size; i++){
		if (cards[i] == card){
			count++;
		}
	}
	return count;
}

CardDeck take(int n){
	Card *first_n = new Card[n];

	for(int i = 0; i < n-1; i++){
		first_n[i] = cards[i];
	}

	return first_n;
}

// std::string toString() const;