#include "Card.hpp"
#include <map>

typedef std::map<int, std::string> BasePairMap;

//default constructor
Card::Card(){
	suit = "SPADE";
	number = 1;
}

//non-default constructor
Card::Card(std::string suit, int number){
	this->suit = suit;
	this->number = number;
}

//copy constructor
Card::Card(const Card& other){
	suit = other.getSuit();
	number = other.getNumber();
}

//assignment operator
Card& Card::operator=(const Card& other){
	if(&other != this){
		suit = other.getSuit();
		number = other.getNumber();
	}
	return (*this);
}

std::string Card::getSuit() const{
	return suit;
}

int Card::getNumber() const{
	return number;
}

bool Card::equals(Card card) const{
	if (this->suit == card.suit and this->number == card.number){
		return true;
	}
	return false;
}

std::string Card::toString() const{
	std::string sn;
	BasePairMap m;

	//map number to card rank
	m[1] = "A";
	m[2] = "2";
	m[3] = "3";
	m[4] = "4";
	m[5] = "5";
	m[6] = "6";
	m[7] = "7";
	m[8] = "8";
	m[9] = "9";
	m[10] = "X";
	m[11] = "J";
	m[12] = "Q";
	m[13] = "K";

	//string concatenation for sn format
	sn = this->suit.at(0)+m[this->number];

	return sn;
}