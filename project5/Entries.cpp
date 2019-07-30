#include "Entries.hpp"

Entries::Entries(){
	this->head = nullptr;
	this->tail = nullptr;
}

Entries::Entries(std::string word, int freq){
	Node* newbie = new Node(word, freq);
	this->head =
}

Entries::Entries(const Entries& other);
Entries& Entries::operator=(const Entries& other);
Entries::~Entries();

void Entries::add(std::string w, int f);
Node* Entries::top();
Node* Entries::bottom();

std::string Entries::toString() const;