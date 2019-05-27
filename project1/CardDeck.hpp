#ifndef CARDDECK_HPP
#define CARDDECK_HPP

#include <string>
#include <iostream>

class CardDeck{
public:
  CardDeck();
  CardDeck(const CardDeck& other);
  CardDeck& operator=(const CardDeck& other);
  ~CardDeck();

  int getSize() const;
  int getCapacity() const;

  Card at(int index) const;
  bool isEmpty() const;

  void add(Card card);
  void insert(Card card, int at);
  // void replace(Card card, int at);
  // void remove(int index);
  // void swap(int i, int j);

  // bool has(Card card) const;
  // int count(Card card) const;

  // CardDeck take(int n);
  // std::string toString() const;

private:
  int capacity;
  int size;
  Card* cards;
};

#endif
