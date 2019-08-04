#include "Node.hpp"
#include <stdexcept>

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

Node::Node(const Node& other){
	next = other.getNext();
	prev = other.getPrev();
	word = other.getWord();
	freq = other.getFreq();
}

Node& Node::operator=(const Node& other){
	// to suppress warnings
	(void)other;
	throw std::runtime_error("Not Implemented");
}

Node::~Node(){
	next = nullptr;
	prev = nullptr;
}

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