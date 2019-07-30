#include "Node.hpp"

Node::Node(){
	next = nullptr;
	prev = nullptr;
	word = "";
	freq = -1;
}

Node::Node(std::string given_word, int given_freq){
	next = nullptr;
	prev = nullptr;
	word = given_word;
	freq = given_freq;
}

// Node::Node(const Node& other);

// Node& Node::operator=(const Node& other){
// 	if (&other != this){
// 		next = other.getNext();
// 		prev = other.getPrev();
// 		word = other.getWord();
// 		freq = other.getFreq();
// 	}
// 	return (*this);
// }

// Node::~Node();

std::string Node::getWord() const{
	return word;
}

void Node::setWord(std::string w){
	word = w;
}

int Node::getFreq() const{
	return freq;
}

void Node::setFreq(int f){
	freq = f;	
}

Node* Node::getNext() const{
	return next;
}

void Node::setNext(Node* node){
	next = node;
}

Node* Node::getPrev() const{
	return prev;
}

void Node::setPrev(Node* node){
	prev = node;
}