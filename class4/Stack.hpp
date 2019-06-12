#ifndef STACK_HPP
#define STACK_HPP

class Stack{
public:
	Stack();
	Stack(const Stack& other);
	Stack& operator=(const Stack& other);
	~Stack();

	void push(int item);
	void pop();
	int top();

private:
	//
};