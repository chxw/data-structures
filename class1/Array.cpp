#include "Array.hpp"

// default constructor
Array::Array(){
  capacity = 5;
  numbers = new int[capacity];
  size = 0;
}

// non-default (user-defined) constructor
void Array::Array(int capacity){
  this->capacity = capacity;
  numbers = new int[capacity];
  size = 0;
}

// copy constructor
Array::Array(const Array& other){
  capacity = other.getCapacity();
  size = other.getSize();
  numbers = new int[capacity];
  for(int i = 0; i < size; i++){
    numbers[i] = other.at(i);
  }
}

// assignment operator
Array& Array::operator=(const Array& other){
  if (&other != this){
    capacity = other.getCapacity();
    size = other.getSize();
    numbers = new int[capacity];
    for(int i = 0; i < size; i++){
      numbers[i] =other.at(i);
    }
  }
  return (*this);
}

// destructor
Array::Array(){
  delete [] numbers;
}

int Array::getCapacity() const{
  return capacity;
}

int Array::getSize() const{
  return size;
}

void Array::add(int i){
  numbers[size] = i;
  ++size
}

int Array::at(int index){
  // if "index" is in appropriate range
  return numbers[index]
}
