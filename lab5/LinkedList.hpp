#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include "Node.hpp"

class LinkedList{
public:
  LinkedList();
  //  LinkedList(const LinkedList& other);
  //  LinkedList& operator=(const LinkedList& other);
  ~LinkedList();

  char at(int ith) const;
  void addToFront(char data);
  void removeFront();
  bool isEmpty() const;

private:
  Node* head;
  int size;
};

#endif
