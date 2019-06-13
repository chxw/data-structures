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
  else if (head->getNext() == nullptr){
    head->setNext(newbie);
  }
  else{
    Node* current = head;
    add(current, newbie);
  }
}

void LinkedList::add(Node* current, Node* newbie){
  if (current->getNext() == nullptr){
    current->setNext(newbie);
    return;
  }
  add(current->getNext(), newbie);
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

void LinkedList::removeBack(){
  if (head == nullptr){
    return;
  }
  else if (head->getNext() == nullptr){
    delete head;
    head = nullptr;
    return;
  }
  else{
    Node* previous = head;
    Node* current = head->getNext();
    remove(previous, current);
    return;
  }
}

void LinkedList::remove(Node* previous, Node* current){
  if (current->getNext() == nullptr){
    delete current;
    previous->setNext(nullptr);
    return;
  }
  previous = current;
  current = current->getNext();
  remove(previous, current);
}

std::string LinkedList::toStringInReverseOrder() const{
  std::string s;
  if (head == nullptr){
    return "|";
  }
  Node* current = head;
  s += toString(s, current);
  s.insert(0, "|<-");
  return s;
}


std::string LinkedList::toString(std::string s, Node* current) const{
  if(current == nullptr){
    return s;
  }
  else if (current == head){
    s.insert(0, current->toString());
    return toString(s, current->getNext());
  }
  else {
    s.insert(0, current->toString()+"<-");
    return toString(s, current->getNext());
  }
}

