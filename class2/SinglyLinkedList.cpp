#include <string>
#include "SinglyLinkedList.hpp"

SinglyLinkedList::SinglyLinkedList(){
	this->head = nullptr;
}

// SinglyLinkedList::~SinglyLinkedList(){
// 	//to do
// }

void SinglyLinkedList::addToBack(int data){
	Node* newbie = new Node(data);
	if (this->head == nullptr){
		this->head = newbie;
	}
	else {
		Node* current = this->head;
		while(current->getNext() != nullptr){
			current = current->getNext();
		}
		current->setNext(newbie);
	}
}

std::string SinglyLinkedList::toString() const{
	//to do
	return "";
}