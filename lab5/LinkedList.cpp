#include <stdexcept>
#include <iostream>

#include "Node.hpp"
#include "LinkedList.hpp"

LinkedList::LinkedList(){
  this->head = nullptr;
  size = 0;
}

LinkedList::~LinkedList(){
  Node* current = head;
  while(current != nullptr){
    Node* next = current->getNext();
    delete current;
    current = next;
  }
  head = nullptr;
  size = 0;
}

char LinkedList::at(int ith) const{
	if (head == nullptr or ith >= size or ith < 0){
		throw std::range_error("Out of Range");
	}
	else if (ith == 0){
		return head->getData();
	}
	else {
		Node* current = head;
		for(int i = 0; i < ith + 1; i++){
			current = current->getNext();
		}
		return current->getData();
	}
}

void LinkedList::addToFront(char data){
	Node* newbie = new Node(data);
	if (head == nullptr){
		head = newbie;
		newbie->setNext(nullptr);
		size++;
	}
	else {
		newbie->setNext(head);
		head = newbie;
		size++;
	}
}

void LinkedList::removeFront(){
	if (head == nullptr){
		return;
	}
	else if (head->getNext() == nullptr){
		delete head;
		head = nullptr;
		size--;
	}
	else {
		Node* new_head = head->getNext();
		delete head;
		head = new_head;
		size--;
	}
}

bool LinkedList::isEmpty() const{
	if (head == nullptr){
		return true;
	}
	return false;
}