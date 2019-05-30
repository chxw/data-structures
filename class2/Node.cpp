#ifndef NODE_CPP
#define NODE_CPP

#include "Node.hpp"

Node::Node(){
	this-> data = 0;
	this-> next = nullptr;
}

Node::Node(int data){
	this->data = data;
	this->next = nullptr;
}

int Node::getData() const{
	return this->data;
}

Node* Node::getNext() const{
	return this->next;
}

void Node::setNext(Node* node){
	this->next = node;
}

std::string Node::toString() const{
	return std::to_string(this->data);
}

#endif