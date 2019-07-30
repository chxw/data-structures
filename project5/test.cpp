#include <cassert>
#include <iostream>

#include "Hash.hpp"

void basics(){
	Hash h;

	h.put("chelsea", 1);
	h.put("tomoki", 2);
	h.put("matt", 3);
	h.put("test", 4);

	h.print();

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
}

int main(){
	basics();

	return 0;
}
