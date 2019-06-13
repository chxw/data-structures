#include "Card.hpp"
#include "CardDeck.hpp"

//default constructor
CardDeck::CardDeck(){
	capacity = 13;
	size = 0;
	cards = new Card[capacity];
}

//copy constructor
CardDeck::CardDeck(const CardDeck& other) {
	capacity = other.getCapacity();
	size = other.getSize();
	cards = new Card[capacity];

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
		cards = new Card[capacity];

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
	if (size == capacity){
		capacity += 13;

		Card *temp = new Card[capacity];

		for(int i = 0; i < size; i++){
			temp[i] = cards[i];
		}

		delete[] cards;
		cards = temp;
		temp = NULL;
	}

	cards[size] = card;
	size++;
}

void CardDeck::insert(Card card, int at){
	if (size == 0 or at == size) {
		this->add(card);
		return;
	}

	if (size == capacity){
		capacity += 13;
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
	Card *temp = new Card[capacity];

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

bool CardDeck::has(Card card) const{
	for(int i = 0; i < size; i++){
		if (cards[i].equals(card)){
			return true;
		}
	}
	return false;
}

int CardDeck::count(Card card) const{
	int count = 0;

	for(int i = 0; i < size; i++){
		if (cards[i].equals(card)){
			count++;
		}
	}
	return count;
}

CardDeck CardDeck::take(int n){
	CardDeck first_n;

	for(int i = 0; i < n; i++){
		first_n.add(cards[i]);
	}

	for(int i = 0; i < n; i++){
		this->remove(0);
	}

	return first_n;
}

std::string CardDeck::toString() const{
	std::string sn_deck;

	for(int i = 0; i < size; i++){
		sn_deck += cards[i].toString();
		if(i != size-1) { sn_deck += ", "; }
	}
	return sn_deck;
}
