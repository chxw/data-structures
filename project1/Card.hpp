#ifndef CARD_HPP
#define CARD_HPP

#include <string>
#include <iostream>

class Card{
public:
  Card();
  Card(std::string suit, int number);
  Card(const Card& other);
  Card& operator=(const Card& other);

  std::string getSuit() const;
  int getNumber() const;
  bool equals(Card card) const;
  std::string toString() const;

private:
	std::string suit;
	int number;
};

#endif

