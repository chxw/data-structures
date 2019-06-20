#include "Node.hpp"

Node::Node(char data){
  this->data = data;
  this->next = nullptr;
}

char Node::getData() const{
  return this->data;
}

Node* Node::getNext() const{
  return this->next;
}

void Node::setNext(Node* next){
  this->next = next;
}
