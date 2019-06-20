#include <cassert>
#include <string>
#include <iostream>

#include "Stack.hpp"


int main(){
	LinkedList ll;

	assert(ll.isEmpty() == true);

	ll.addToFront('i');
	assert(ll.isEmpty() == false);

	assert(ll.at(0) == 'i');

	std::string message;
	try {
		ll.at(1);
	}
	catch(std::range_error& e){
    	message = e.what();
	}
	assert(message == "Out of Range");

	assert(ll.isEmpty() == false);

	Stack s;
	assert(s.isEmpty() == true);
	s.push('i');
	assert(s.isEmpty() == false);

	assert(s.top() == 'i');

	s.pop();
	assert(s.isEmpty() == true);

	std::string message2;
	try {
		s.top();
	}
	catch(std::range_error& e){
    	message2 = e.what();
	}
	assert(message2 == "Out of Range");

	return 0;
}