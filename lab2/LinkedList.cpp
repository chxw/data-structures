#include <iostream>
#include <string>

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
	delete next;
	next = nullptr;
}

void LinkedList::addToFront(int data){
	Node* newbie = new Node(data);
	if (this->head == nullptr){
		this->head = newbie;
		newbie->setNext(nullptr);
	}
	else {
		newbie->setNext(head);
		this->head = newbie;
	}
}

std::string LinkedList::toString() const{
	std::string ll_string;
	Node* current = this->head;
	while(current != nullptr){
		ll_string += current->toString();
		ll_string += "->";
		current = current->getNext();
	}
	ll_string += "|";
	return ll_string;
}

void LinkedList::removeFront(){
	this->head = this->head->getNext();
}