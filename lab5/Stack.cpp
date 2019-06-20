#include <stdexcept>

#include "Stack.hpp"
#include "LinkedList.hpp"

// Stack::Stack();
//  Stack(const Stack& other);
//  Stack& operator=(const Stack& other);
// Stack::~Stack();

void Stack::push(char item){
	ll.addToFront(item);
}

void Stack::pop(){
	ll.removeFront();
}

char Stack::top() const{
	if (ll.isEmpty()){
		throw std::range_error("Out of Range");
	}
	return ll.at(0);
}

bool Stack::isEmpty() const{
	return ll.isEmpty();
}