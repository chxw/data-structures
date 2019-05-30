#include <string>

#include "Node.hpp"

Node::Node()
  : Node(0){
}

Node::Node(int data){
  this->data = data;
  this->next = nullptr;
}

int Node::getData() const{
  return this->data;
}

Node* Node::getNext() const{
  return this->next;
}

void Node::setNext(Node* next){
  this->next = next;
}

std::string Node::toString() const{
  return std::to_string(this->data);
}
