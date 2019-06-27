#include "Node.hpp"
#include "State.hpp"

Node::Node(State* data){
  this->data = data;
  this->next = nullptr;
}

State* Node::getData() const{
  return this->data;
}

Node* Node::getNext() const{
  return this->next;
}

void Node::setNext(Node* next){
  this->next = next;
}
