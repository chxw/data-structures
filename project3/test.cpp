#include <cassert>

#include "Sorter.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <iostream>

bool isSorted(int* const array, int size){
  for (int i = 1; i < size; i++){
    if (array[i-1] > array[i]){
      return false;
    }
  }
  return true;
}

// void test1(){
//   Sorter sorter;
//   Mode mode = sorter.getMode();
//   assert(mode == Mode::INSERTION_SORT);
// }

void print_array(int* const array, int size){
  for (int i = 0; i < size; i++){
    std::cout << array[i];
    if(i == size - 1){
      std::cout << "\n";
    }
    else{
      std::cout << ", ";
    }
  }
}

void custom(){
  int size = 11;
  int* a = new int[size];

  a[0] = 96;
  a[1] = 11;
  a[2] = -5;
  a[3] = -1996;
  a[4] = 10;
  a[5] = 8;
  a[6] = 2;
  a[7] = 1994;
  a[8] = 0;
  a[9] = 22;
  a[10] = 46;

  Sorter sorter;
  sorter.sort(a, size);

  bool b = isSorted(a, size);
  assert(b == true);
  delete [] a;
}

void unordered(int size){
  time_t t;
  srand((unsigned) time(&t));

  int* array = new int[size];
  for(int i = 0; i < size; i++)
    array[i] = (rand() % size) + 1;

  Sorter sorter;
  sorter.sort(array, size);

  bool b = isSorted(array, size);
  assert(b == true);
  delete [] array;
}

void ordered(int size){
  int* array = new int[size];
  for(int i = 0; i < size; i++)
    array[i] = i;

  Sorter sorter;
  sorter.sort(array, size);

  bool b = isSorted(array, size);
  assert(b == true);
  delete [] array;
}

void almost_ordered(int size){
  time_t t;
  srand((unsigned) time(&t));

  int* array = new int[size];
  for(int i = 0; i < size; i++){
    if (i == (rand()%size +1) and i > 0){
      array[i] = array[i-1] + (rand()%size + 1);
    }
    else {
      array[i] = i;
    }
  }

  Sorter sorter;
  sorter.sort(array, size);

  bool b = isSorted(array, size);
  assert(b == true);
  delete [] array;
}

void reverse_ordered(int size){
  int* array = new int[size];
  for(int i = size - 1; i > 0; i--)
    array[i] = i;

  Sorter sorter;
  sorter.sort(array, size);

  bool b = isSorted(array, size);
  assert(b == true);
  delete [] array;
}

int main(){
  // test1();
  custom();
  unordered(5);
  unordered(6);
  unordered(30);
  unordered(40);
  unordered(50);
  unordered(60);
  unordered(80);
  unordered(90);
  almost_ordered(90);
  unordered(2000000);
  reverse_ordered(100);
  ordered(100);

  return 0;
}
