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

  void addToFront(int data);
  void removeFront();
  std::string toString() const;

private:
  Node* head;
};

#endif
