#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <string>

#include "Node.hpp"

class LinkedList{
public:
  LinkedList();
  //LinkedList(const LinkedList& other);
  //LinkedList& operator=(const LinkedList& other);
  ~LinkedList();

  void addToBack(int data);
  void removeBack();
  int getSize() const;
  std::string toStringInReverseOrder() const;

private:
  Node* head;
  int count(Node* current, int total) const;
  void add(Node* current, Node* newbie);
  void remove(Node* previous, Node* current);
  std::string toString(std::string s, Node* current) const;
  std::string reverseString(std::string s) const;
};

#endif
