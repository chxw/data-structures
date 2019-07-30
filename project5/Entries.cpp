#include "Entries.hpp"

#include <iostream>

Entries::Entries(){
	head = nullptr;
	tail = nullptr;
	num_entries = 0;
}

Entries::Entries(std::string word, int freq){
	Node* newbie = new Node(word, freq);
	head = newbie;
	tail = newbie;

	num_entries = 0;
}

// Entries::Entries(const Entries& other){}
// Entries& Entries::operator=(const Entries& other);
// Entries::~Entries();

void Entries::add(std::string w, int f){
	Node* newbie = new Node(w, f);
	newbie->setNext(nullptr);

	// empty
	if (head == nullptr){
		newbie->setPrev(nullptr);

		head = newbie;
		tail = newbie;

		num_entries += 1;
	}
	// not empty
	else{
		newbie->setPrev(tail);

		tail->setNext(newbie);

		tail = newbie;
		num_entries += 1;
	}
}

void Entries::add(Node* newbie){
	// empty
	if (head == nullptr){
		newbie->setNext(nullptr);
		newbie->setPrev(nullptr);

		head = newbie;
		tail = newbie;

		num_entries += 1;
	}
	// not empty
	else{
		tail->setNext(newbie);

		newbie->setNext(nullptr);
		newbie->setPrev(tail);

		tail = newbie;
		num_entries += 1;
	}
}

void Entries::remove(std::string w){
	if (head != nullptr){
		if (head->getNext() == nullptr){
			delete head;
			return;
		}
		else if (tail->getWord() == w){
			Node* new_tail = tail->getNext();
			delete tail;
			tail = new_tail;
			return;
		}
		else{
			Node* previous = head;
			Node* current = head->getNext();
			while (current != nullptr){
				if (current->getWord() == w){
					previous->setNext(current->getNext());
					delete current;
					return;
				}
				previous = current;
				current = current->getNext();
			}
		}
	}
}

Node* Entries::top(){
	return head;
}

Node* Entries::bottom(){
	return tail;
}

std::string Entries::toString() const{
	if (head == nullptr){
		return "empty";
	}

	std::string s;

	Node* previous = nullptr;
	Node* current = head;
	while (current != nullptr){
		s += current->getWord()+"<->";
		std::cout << s;
		previous = current;
		current = current->getNext();
	}

	s.pop_back();
	s.pop_back();
	s.pop_back();

	return s;
}