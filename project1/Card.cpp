#include "Card.hpp"

//default constructor
Card::Card(){
	suit = "SPADE";
	number = 1;
}

//non-default constructor
void Card::Card(std::string suit, int number){
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
	if this->suit == card->suit and this->number == card->number:
		return true;
	return false;
}

// std::string Card::toString() const{
// 	cout << this->suit[0] << endl;
// }