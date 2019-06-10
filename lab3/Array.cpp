#include <string>
#include <iostream>
#include <stdexcept>

#include "Array.hpp"

Array::Array(){
  capacity = 5;
  numbers = new int[capacity];
  size = 0;
}

Array::~Array(){
  delete numbers;
}

int Array::getCapacity() const{
  return capacity;
}

int Array::getSize() const{
  return size;
}

void Array::add(int number){
  if (size == capacity){
    capacity = capacity*2;
  }

  int* temp = new int[capacity];
  for(int i = 0; i < size; i++){
    temp[i] = numbers[i];
  }
  delete numbers;
  numbers = temp;
  temp = NULL;

  numbers[size] = number;
  size++;
}

int Array::at(int index) const{  
  if(index < 0 or index >= size){
    std::string message = "OUT OF RANGE: ";
    message += std::to_string(index);
    throw std::range_error(message);
  }
  return numbers[index];
}
