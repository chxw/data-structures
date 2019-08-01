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

	assert(n->getNext() == nullptr);
	assert(n1->getNext() == nullptr);

	Entries* e = new Entries();
	e->add(n);
	e->add(n1);
	e->add("chelsea", 6);
	e->add("johnny", 3);

	assert(e->top()->getWord() == "james earl carter");

	if (e->top() == nullptr){
		std::cout << "e is empty" << std::endl;
	}
	else{
		assert(e->top()->getWord() == "james earl carter");
	}

	assert(e->top()->getWord() == n->getWord());
	assert(e->bottom()->getWord() == "johnny");

	assert(e->toString() == "james earl carter<->alex turner<->chelsea<->johnny");

}

void Integration_basics(){
	Hash h(5);

	h.put("chelsea", 1);
	h.put("tomoki", 2);
	h.put("matt", 3);
	h.put("test", 4);
	h.put("johnny", 5);
	h.put("britneysbackbetch", 6);
	h.put("dixiechicksandbeyonce", 7);

	h.print();
}

int main(){
	Hash_basics();
	Entries_basics();
	Integration_basics();

	return 0;
}
