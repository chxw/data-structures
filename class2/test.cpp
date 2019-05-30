#include <iostream>
#include <string>
#include "Node.cpp"
#include "SinglyLinkedList.cpp"

int main(){
	Node* n1 = new Node(2);
	Node* n2 = new Node(1);
	Node* n3 = new Node(0);

	n1->setNext(n2);
	n2->setNext(n3);

	// std::cout << n1->toString() << std::endl;
	// std::cout << n1->getNext()->toString() << std::endl;
	// std::cout << n1->getNext()->getNext()->toString() << std::endl;

	SinglyLinkedList linkedList;

	linkedList.addToBack(2);
	linkedList.addToBack(1);
	linkedList.addToBack(0);
	std::cout << linkedList.toString() << std::endl;


	return 0;
}