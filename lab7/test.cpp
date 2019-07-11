#include <cassert>
#include <cstdlib>

#include <string>
#include <iostream>

#include "MinHeap.hpp"

void heapsort(int* const array, int size){
  MinHeap heap;

  for (int i = 0; i < size; i++){
    heap.insert(array[i]);
  }

  for (int i = 0; i < size; i++){
    array[i] = heap.extractMin();
    std::cout << array[i] << std::endl;
  }
}

void test1(){
  MinHeap heap;
  assert(heap.isEmpty());

  int n = 1000;
  for(int i = n; i >= 0; i--){
    heap.insert(i);
  }

  for(int i = 0; i <= n; i++){
    assert(heap.extractMin() == i);
  }

  assert(heap.isEmpty());
}

void test2(){
  int size = 10000;
  int* array = new int[size];
  for(int i = 0; i < size; i++){
    array[i] = i;
  }

  unsigned int seed = 2019;
  std::srand(seed);
  for(int i = 0; i < size; i++){
    int index1 = std::rand() % size;
    int index2 = std::rand() % size;

    int number1 = array[index1];
    array[index1] = array[index2];
    array[index2] = number1;
  }

  heapsort(array, size);

  for(int i = 0; i < size; i++){
    assert(array[i] == i);
  }

  delete [] array;
}

int main(){
  test1();
  test2();
  return 0;
}
