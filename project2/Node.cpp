#include "Node.hpp"
#include <iostream>

Node::Node(){
	data = nullptr;
	next = nullptr;
}
Node::Node(Event* d){
	data = new Event;
	data = d;
	next = nullptr;
}

Node::Node(const Node& other){
	data = other.getData();
	next = other.getNext();
}

Node& Node::operator=(const Node& other){
	throw std::runtime_error("Not Implemented");
	if(&other != this){
		data = other.getData();
		next = other.getNext();
	}
	return(*this);
}

Node::~Node(){

}

Event* Node::getData() const{
	return data;
}

Node* Node::getNext() const{
	return next;
}

void Node::setNext(Node* n){
	next = n;
}
