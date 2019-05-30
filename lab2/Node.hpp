#ifndef NODE_HPP
#define NODE_HPP

#include <string>

class Node{
public:
  Node();
  Node(int data);
  //Node(const Node& other);
  //Node& operator=(const Node& other);
  //~Node();

  int getData() const;
  Node* getNext() const;
  void setNext(Node* next);
  std::string toString() const;

private:
  int data;
  Node* next;
};

#endif
