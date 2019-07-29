#include "Node.cpp"

Node::Node(){
	next = nullptr;
	prev = nullptr;
	word = "";
	freq = -1;
}

// Node::Node(std::string word, int freq);
// Node::Node(const Node& other);
// Node::Node& operator=(const Node& other);
// Node::~Node();

std::string Node::getWord() const{
	return word;
}

int Node::getFreq() const{
	return freq;
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