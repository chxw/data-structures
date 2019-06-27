#ifndef STACK_HPP
#define STACK_HPP

#include "LinkedList.hpp"
#include "State.hpp"

class Stack{
public:
  Stack();
  //  Stack(const Stack& other);
  //  Stack& operator=(const Stack& other);
  ~Stack();

  void push(State* item);
  void pop();
  State* top() const;
  bool isEmpty() const;

private:
  //Your choice
};

#endif
