#include <cassert>

#include "Sorter.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <iostream>

bool isSorted(int* const array, int size){
  for (int i = 0; i < size; i++){
    if (array[i] > array[i+1]){
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

void test2(){
  int size = 100;
  int* array = new int[size];
  for(int i = 0; i < size; i++)
    array[i] = i;

  Sorter sorter;
  sorter.sort(array, size);

  bool b = isSorted(array, size);
  assert(b == true);
  delete [] array;
}

void test3(){
  int size = 6;
  int* a = new int[size];

  a[0] = 96;
  a[1] = 11;
  a[2] = -5;
  a[3] = -1996;
  a[4] = 10;
  a[5] = 99999;

  Sorter sorter;
  sorter.sort(a, size);

  bool b = isSorted(a, size);
  assert(b == true);
  delete [] a;
}

void unordered_30(){
  time_t t;
  srand((unsigned) time(&t));

  int size = 30;
  int* array = new int[size];
  for(int i = 0; i < size; i++)
    array[i] = (rand()%100)+1;

  Sorter sorter;
  sorter.sort(array, size);

  bool b = isSorted(array, size);
  assert(b == true);
  delete [] array;
}

void unordered_60(){
  time_t t;
  srand((unsigned) time(&t));

  int size = 60;
  int* array = new int[size];
  for(int i = 0; i < size; i++)
    array[i] = (rand()%100)+1;

  Sorter sorter;
  sorter.sort(array, size);

  bool b = isSorted(array, size);
  assert(b == true);
  delete [] array;
}

void unordered_70(){
  time_t t;
  srand((unsigned) time(&t));

  int size = 70;
  int* array = new int[size];
  for(int i = 0; i < size; i++)
    array[i] = (rand()%100)+1;

  Sorter sorter;
  sorter.sort(array, size);

  bool b = isSorted(array, size);
  assert(b == true);
  delete [] array;
}

void unordered_90(){
  time_t t;
  srand((unsigned) time(&t));

  int size = 90;
  int* array = new int[size];
  for(int i = 0; i < size; i++)
    array[i] = (rand()%100)+1;

  Sorter sorter;
  sorter.sort(array, size);

  bool b = isSorted(array, size);
  assert(b == true);
  delete [] array;
}


int main(){
  // test1();
  test2();
  test3();
  unordered_30();
  unordered_60();
  unordered_70();
  unordered_90();
  return 0;
}
