#include <cassert>

#include "Sorter.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include<stdexcept>
#include<chrono>

#include <iostream>

using namespace std;
using namespace std::chrono;

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

  Mode insertion = Mode::INSERTION_SORT;
  Mode merge = Mode::MERGE_SORT;
  Mode quick = Mode::QUICK_SORT;

  int size = 5;
  int* a = new int[size];

  a[0] = 4;
  a[1] = -2;
  a[2] = 16;
  a[3] = 48;
  a[4] = -52;

  Mode mode = sorter.getMode();
  assert(mode == insertion);

  sorter.sort(a, size, merge);

  sorter.set(merge);
  Mode mode2 = sorter.getMode();
  assert(mode2 == merge);

  sorter.sort(a, size, quick);


  sorter.set(quick);
  Mode mode3 = sorter.getMode();
  assert(mode3 == quick);

  sorter.sort(a, size, insertion);

  delete[] a;
}

void throw_test(){
  Sorter sorter;

  int* a = nullptr;
  int* b = new int[5];

  std::string message;
  try {
    sorter.sort(a, 1);
  }
  catch(std::range_error& e){
    message = e.what();
  }
  assert(message == "Invalid Argument");

  std::string message1;
  try {
    sorter.sort(b, 0);
  }
  catch(std::range_error& e){
    message1 = e.what();
  }
  assert(message1 == "Invalid Argument");
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

void time_test(Mode m){
  high_resolution_clock::time_point t1 = high_resolution_clock::now();
  unordered(5, m);
  high_resolution_clock::time_point t2 = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(t2-t1).count();
  cout << "unordered (small N): ";
  cout << duration;
  cout << " ms" << endl;

  high_resolution_clock::time_point t3 = high_resolution_clock::now();
  unordered(2000000, m);
  high_resolution_clock::time_point t4 = high_resolution_clock::now();
  auto duration1 = duration_cast<microseconds>(t4-t3).count();
  cout << "unordered (large N): ";
  cout << duration1;
  cout << " ms" << endl;

  high_resolution_clock::time_point t5 = high_resolution_clock::now();
  almost_ordered(5, m);
  high_resolution_clock::time_point t6 = high_resolution_clock::now();
  auto duration2 = duration_cast<microseconds>(t6-t5).count();
  cout << "almost_ordered (small N): ";
  cout << duration2;
  cout << " ms" << endl;

  high_resolution_clock::time_point t7 = high_resolution_clock::now();
  almost_ordered(2000000, m);
  high_resolution_clock::time_point t8 = high_resolution_clock::now();
  auto duration3 = duration_cast<microseconds>(t8-t7).count();
  cout << "almost_ordered (large N): ";
  cout << duration3;
  cout << " ms" << endl;

  high_resolution_clock::time_point t9 = high_resolution_clock::now();
  reverse_ordered(5, m);
  high_resolution_clock::time_point t10 = high_resolution_clock::now();
  auto duration4 = duration_cast<microseconds>(t10-t9).count();
  cout << "reverse_ordered (small N): ";
  cout << duration4;
  cout << " ms" << endl;

  high_resolution_clock::time_point t11 = high_resolution_clock::now();
  reverse_ordered(2000000, m);
  high_resolution_clock::time_point t12 = high_resolution_clock::now();
  auto duration5 = duration_cast<microseconds>(t12-t11).count();
  cout << "reverese_ordered (large N): ";
  cout << duration5;
  cout << " ms" << endl;

  high_resolution_clock::time_point t13 = high_resolution_clock::now();
  ordered(5, m);
  high_resolution_clock::time_point t14 = high_resolution_clock::now();
  auto duration6 = duration_cast<microseconds>(t14-t13).count();
  cout << "already_ordered (small N): ";
  cout << duration6;
  cout << " ms" << endl;

  high_resolution_clock::time_point t15 = high_resolution_clock::now();
  ordered(2000000, m);
  high_resolution_clock::time_point t16 = high_resolution_clock::now();
  auto duration7 = duration_cast<microseconds>(t16-t15).count();
  cout << "already_ordered (large N): ";
  cout << duration7;
  cout << " ms" << endl;
}

int main(){
  enum_test();
  throw_test();

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
  almost_ordered(2000000, i);
  unordered(2000000, i);
  reverse_ordered(100, i);
  reverse_ordered(2000000, i);
  ordered(100, i);
  ordered(2000000, i);

  cout << "INSERTION_SORT*****************" << endl;
  time_test(i);

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
  almost_ordered(2000000, m);
  unordered(2000000, m);
  reverse_ordered(100, m);
  reverse_ordered(2000000, m);
  ordered(100, m);
  ordered(2000000, m);

  cout << "MERGE_SORT*****************" << endl;
  time_test(m);

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
  almost_ordered(2000000, q);
  unordered(2000000, q);
  reverse_ordered(100, q);
  reverse_ordered(2000000, q);
  ordered(100, q);
  ordered(2000000, q);

  cout << "QUICK_SORT*****************" << endl;
  time_test(q);

  return 0;
}
