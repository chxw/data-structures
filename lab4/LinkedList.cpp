#include <string>
#include <iostream>

#include "Node.hpp"
#include "LinkedList.hpp"

LinkedList::LinkedList(){
  this->head = nullptr;
}

LinkedList::~LinkedList(){
  Node* current = head;
  while(current != nullptr){
    Node* next = current->getNext();
    delete current;
    current = next;
  }
}

void LinkedList::addToBack(int data){
  Node* newbie = new Node(data);
  newbie->setNext(nullptr);
  
  if (head == nullptr){
    head = newbie;
  }
  else{
    Node* current = head;
    add(current, newbie);
  }
}

int LinkedList::getSize() const{
  if (head == nullptr){
    return 0;
  }
  else if (head->getNext() == nullptr){
    return 1;
  }
  else{
    Node* current = head;

    return count(current, 0);
  }
}

int LinkedList::count(Node* current, int total) const{
  if (current->getNext() == nullptr){
    return total+1;
  }
  current = current->getNext();
  return count(current, total+1);
}

void LinkedList::add(Node* current, Node* newbie){
  if (current->getNext() == nullptr){
    current->setNext(newbie);
    return;
  }
  add(current->getNext(), newbie);
}

std::string LinkedList::toStringInReverseOrder() const{
  std::string s;
  if (head == nullptr){
    return "|";
  }
  Node* current = head;
  return toString(s, current);
}

std::string LinkedList::toString(std::string s, Node* current) const{
  if(current == nullptr){
    s+="|<-";
    return s;
  }
  s+="<-";
  s+=current->toString();
  return toString(s, current->getNext());
}
