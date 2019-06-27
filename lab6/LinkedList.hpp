#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include "Node.hpp"
#include "State.hpp"

class LinkedList{
public:
  LinkedList();
  //  LinkedList(const LinkedList& other);
  //  LinkedList& operator=(const LinkedList& other);
  ~LinkedList();

  State* at(int ith) const;
  void addToFront(State* data);
  void removeFront();
  bool isEmpty() const;

private:
  //your design
};

#endif
