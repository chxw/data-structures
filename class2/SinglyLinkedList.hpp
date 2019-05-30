#ifndef SINGLYLINKEDLIST_HPP
#define SINGLYLINKEDLIST_HPP


#include "Node.hpp"

class SinglyLinkedList{

public:
	SinglyLinkedList();
	// SinglyLinkedList(const SinglyLinkedList& other);
	// SinglyLinkedList& operator=(const SinglyLinkedList& other);
	// ~SinglyLinkedList();

	void addToBack(int data);
	std::string toString() const;

private:
	Node* head;
};

#endif