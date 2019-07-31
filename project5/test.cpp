#include <cassert>
#include <iostream>

#include "Hash.hpp"
#include "Entries.hpp"

void Hash_basics(){
	Hash h;

	h.put("chelsea", 1);
	h.put("tomoki", 2);
	h.put("matt", 3);
	h.put("test", 4);

	h.print();
}

void Entries_basics(){
	Node* n = new Node();

	n->setWord("james earl carter");
	assert(n->getWord() == "james earl carter");
	n->setFreq(1);
	assert(n->getFreq() == 1);

	Node* n1 = new Node("alex turner", 2);

	assert(n1->getWord() == "alex turner");
	assert(n1->getFreq() == 2);

	n1->setNext(n);

	assert(n1->getNext()->getWord() == "james earl carter");
	assert(n1->getNext()->getFreq() == 1);

	n1->setNext(n1);
	assert(n1->getNext()->getWord() == "alex turner");
	assert(n1->getNext()->getFreq() == 2);

	n1->setNext(nullptr);

	if (n->getNext() == nullptr){
		std::cout << "n->nullptr" << std::endl;
	}
	else{
		std::cout << "n->" << n->getNext()->getWord() << std::endl;
	}

	if (n1->getNext() == nullptr){
		std::cout << "n1->nullptr" << std::endl;
	}
	else{
		std::cout << "n1->" << n1->getNext()->getWord() << std::endl;
	}

	Entries* e = new Entries();
	e->add(n);
	e->add(n1);
	e->add("chelsea", 6);
	e->add("johnny", 3);

	if (e->top() == nullptr){
		std::cout << "e is empty" << std::endl;
	}
	else{
		std::cout << "e top is " << e->top()->getWord() << std::endl;
	}

	if (e->bottom() == nullptr){
		std::cout << "e is empty" << std::endl;
	}
	else{
		std::cout << "e bottom is " << e->bottom()->getWord() << std::endl;
	}

	std::cout << e->toString() << std::endl;
}

int main(){
	Hash_basics();
	Entries_basics();

	return 0;
}
