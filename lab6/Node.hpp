#ifndef NODE_HPP
#define NODE_HPP

#include "State.hpp"

class Node{
public:
  //  Node();
  Node(State* data);
  //  Node(const Node& other);
  //  Node& operator=(const Node& other);
  //  ~Node();

  State* getData() const;
  Node* getNext() const;
  void setNext(Node* next);

private:
  State* data;
  Node* next;
};

#endif
