#include "BSTNode.hpp"
#include <stdexcept>

BSTNode::BSTNode(){
	data = nullptr;
	left = nullptr;
	right = nullptr;
}

BSTNode::BSTNode(Student* sdata){
	data = sdata;
	left = nullptr;
	right = nullptr;
}

BSTNode::BSTNode(const BSTNode& other){
	data = other.data;
	left = other.left;
	right = other.right;
}

BSTNode& BSTNode::operator=(const BSTNode& other){
	throw std::runtime_error("Not Implemented");
}

BSTNode::~BSTNode(){
	delete data;
	left = nullptr;
	right = nullptr;
}

Student* BSTNode::getData() const{
	return data;
}

BSTNode* BSTNode::getLeft() const{
	return left;
}

void BSTNode::setLeft(BSTNode* l){
	left = l;
}

BSTNode* BSTNode::getRight() const{
	return right;
}

void BSTNode::setRight(BSTNode* r){
	right = r;
}
