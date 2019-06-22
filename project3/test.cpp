#include <cassert>

#include "Sorter.hpp"

bool isSorted(int* const array, int size){
  return false;
}

void test1(){
  Sorter sorter;
  Mode mode = sorter.getMode();
  assert(mode == Mode::INSERTION_SORT);
}

void test2(){
  int size = 100;
  int* array = new int[size];
  for(int i = 0; i < size; i++)
    array[i] = i;

  bool b = isSorted(array, size);
  assert(b == true);
  delete [] array;
}

int main(){
  test1();
  test2();
  return 0;
}
