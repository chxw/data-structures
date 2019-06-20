#ifndef STACK_HPP
#define STACK_HPP

#include "LinkedList.hpp"

class Stack{
public:
  Stack();
  //  Stack(const Stack& other);
  //  Stack& operator=(const Stack& other);
  ~Stack();

  void push(char item);
  void pop();
  char top() const;
  bool isEmpty() const;

private:
  //Your design
};

#endif
