#include <cassert>
#include <cstdlib>

#include "MinHeap.hpp"

#include <iostream>

// void heapsort(int* const array, int size){
// }

void insert_test(){
  MinHeap heap;
  assert(heap.isEmpty());

  heap.insert(15);
  heap.insert(0);
  heap.insert(4);
  heap.insert(16);
  heap.insert(1);
  heap.insert(50);
  heap.insert(20);
  heap.insert(-2);

  // heap.toString();

}

void extract_test(){
  MinHeap heap;

  int n = 1000;
  for(int i = n; i >= 0; i--){
    heap.insert(i);
  }


  for(int i = 0; i <= n; i++){
    // assert(heap.extractMin() == i);
    heap.extractMin();
    // std::cout << ", ";
  }

  heap.toString();

  // assert(heap.isEmpty());
}

// void test2(){
//   int size = 10000;
//   int* array = new int[size];
//   for(int i = 0; i < size; i++){
//     array[i] = i;
//   }

//   unsigned int seed = 2019;
//   std::srand(seed);
//   for(int i = 0; i < size; i++){
//     int index1 = std::rand() % size;
//     int index2 = std::rand() % size;

//     int number1 = array[index1];
//     array[index1] = array[index2];
//     array[index2] = number1;
//   }

//   heapsort(array, size);

//   for(int i = 0; i < size; i++){
//     assert(array[i] == i);
//   }

//   delete [] array;
// }

int main(){
  insert_test();
  extract_test();
  // test2();
  return 0;
}
