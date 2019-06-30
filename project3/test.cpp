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

void enum_test(){
  Sorter sorter;
  Mode mode = sorter.getMode();
  assert(mode == Mode::INSERTION_SORT);
}

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

void custom(Mode m){
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

  Sorter sorter(m);
  sorter.sort(a, size);

  bool b = isSorted(a, size);
  assert(b == true);
  delete [] a;
}

void unordered(int size, Mode m){
  time_t t;
  srand((unsigned) time(&t));

  int* array = new int[size];
  for(int i = 0; i < size; i++)
    array[i] = (rand() % size) + 1;

  Sorter sorter(m);
  sorter.sort(array, size);

  bool b = isSorted(array, size);
  assert(b == true);
  delete [] array;
}

void ordered(int size, Mode m){
  int* array = new int[size];
  for(int i = 0; i < size; i++)
    array[i] = i;

  Sorter sorter(m);
  sorter.sort(array, size);

  bool b = isSorted(array, size);
  assert(b == true);
  delete [] array;
}

void almost_ordered(int size, Mode m){
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

  Sorter sorter(m);
  sorter.sort(array, size);

  bool b = isSorted(array, size);
  assert(b == true);
  delete [] array;
}

void reverse_ordered(int size, Mode m){
  int* array = new int[size];
  for(int i = size - 1; i > 0; i--)
    array[i] = i;

  Sorter sorter(m);
  sorter.sort(array, size);

  bool b = isSorted(array, size);
  assert(b == true);
  delete [] array;
}

int main(){
  enum_test();

  Mode i = Mode::INSERTION_SORT;
  Mode m = Mode::MERGE_SORT;
  Mode q  = Mode::QUICK_SORT;

  // insertion sort
  custom(i);
  unordered(5, i);
  unordered(6, i);
  unordered(30, i);
  unordered(40, i);
  unordered(50, i);
  unordered(60, i);
  unordered(80, i);
  unordered(90, i);
  unordered(95, i);
  almost_ordered(100, i);
  almost_ordered(10000000, i);
  unordered(10000000, i);
  reverse_ordered(100, i);
  reverse_ordered(10000000, i);
  ordered(100, i);
  ordered(10000000, i);

  // merge sort
  custom(m);
  unordered(5, m);
  unordered(6, m);
  unordered(30, m);
  unordered(40, m);
  unordered(50, m);
  unordered(60, m);
  unordered(80, m);
  unordered(90, m);
  almost_ordered(100, m);
  almost_ordered(10000000, m);
  unordered(10000000, m);
  reverse_ordered(100, m);
  reverse_ordered(10000000, m);
  ordered(100, m);
  ordered(10000000, m);

  // quick sort
  custom(q);
  unordered(5, q);
  unordered(6, q);
  unordered(30, q);
  unordered(40, q);
  unordered(50, q);
  unordered(60, q);
  unordered(80, q);
  unordered(90, q);
  almost_ordered(100, q);
  almost_ordered(10000000, q);
  unordered(10000000, q);
  reverse_ordered(100, q);
  reverse_ordered(10000000, q);
  ordered(100, q);
  ordered(10000000, q);


  return 0;
}
