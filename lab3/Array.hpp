#ifndef ARRAY_HPP
#define ARRAY_HPP

class Array{
public:
  Array();
  //Array(const Array& other);
  //Array& operator=(const Array& other);
  ~Array();

  void add(int number);
  int at(int index) const;

  int getCapacity() const;
  int getSize() const;

private:
  int* numbers;
  int size;
  int capacity;
};

#endif
