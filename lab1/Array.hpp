#ifndef ARRAY_HPP
#define ARRAY_HPP

class Array{
public:
  Array(); //default constructor
  Array(int capacity); //non-default (user defined) constructor
  Array(const Array& other); //copy constructor
  Array& operator(const Array& other); //assignment operator

  ~Array(); //destructor - since we are using heap memory space, we have to put enough heap when initializing a program... then destroy the memory
  void add(int i);
  int at(int index) const;

  int getCapacity() const;
  int getSize() const;
  
private:
  int* numbers;
  int size;
  int capacity;
  
};

#endif
