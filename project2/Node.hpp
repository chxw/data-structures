#ifndef NODE_HPP
#define NODE_HPP

#include "Event.hpp"

class Node{
public:
  Node();
  Node(Event* d);
  Node(const Node& other);
  Node& operator=(const Node& other);
  ~Node();

  Event* getData() const;
  Node* getNext() const;
  void setNext(Node* n);

private:
  Event* data;
  Node* next;
};

#endif
