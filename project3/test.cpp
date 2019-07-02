#include <cassert>

#include "Sorter.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include<stdexcept>
#include<chrono>

#include <iostream>
#include <fstream>

#include <string>

using namespace std;
using namespace std::chrono;

typedef void (*test_funct)(int, Mode);

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

  Mode m = Mode::MERGE_SORT;

  int* a = nullptr;
  int* b = new int[5];

  std::string message;
  try {
    sorter.sort(a, 1);
  }
  catch(std::invalid_argument& e){
    message = e.what();
  }
  assert(message == "Invalid Argument");

  std::string message1;
  try {
    sorter.sort(b, 0);
  }
  catch(std::invalid_argument& e){
    message1 = e.what();
  }
  assert(message1 == "Invalid Argument");

  std::string message3;
  try {
    sorter.sort(a, 1, m);
  }
  catch(std::invalid_argument& e){
    message3 = e.what();
  }
  assert(message3 == "Invalid Argument");

  std::string message4;
  try {
    sorter.sort(b, 0, m);
  }
  catch(std::invalid_argument& e){
    message4 = e.what();
  }
  assert(message4 == "Invalid Argument");
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
  for(int i = size - 1; i >= 0; i--)
    array[i] = i;

  Sorter sorter(m);
  sorter.sort(array, size);

  bool b = isSorted(array, size);
  assert(b == true);
  delete [] array;
}

int data_pt(test_funct f, Mode m, int size){
  high_resolution_clock::time_point t1 = high_resolution_clock::now();
  f(size, m);
  high_resolution_clock::time_point t2 = high_resolution_clock::now();
  int result = duration_cast<microseconds>(t2-t1).count();
  return result;
}

int main(){
  enum_test();
  throw_test();

  Mode i = Mode::INSERTION_SORT;
  Mode m = Mode::MERGE_SORT;
  Mode q  = Mode::QUICK_SORT;

  test_funct unorder = &unordered;
  test_funct order = &ordered;
  test_funct almost = &almost_ordered;
  test_funct reverse = & reverse_ordered;

  ofstream merge ("merge_sort.csv");
  ofstream insertion ("insertion_sort.csv");
  ofstream quick ("quick_sort.csv"); 

  //insertion sort
  insertion << "Size, Unordered, Ordered, Almost ordered, Reverse ordered \n";
  for (int x = 1; x < 10000000; x+=20000){
    insertion << to_string(x) + ",";
    insertion << to_string(data_pt(unorder, i, x)) + ",";
    insertion << to_string(data_pt(order, i, x)) + ",";
    insertion << to_string(data_pt(almost, i, x)) + ",";
    insertion << to_string(data_pt(reverse, i, x))+ ", \n";
  }

  //merge sort
  merge << "Size, Unordered, Ordered, Almost ordered, Reverse ordered \n";
  for (int x = 1; x < 10000000; x+=20000){
    merge << to_string(x) + ",";
    merge << to_string(data_pt(unorder, m, x)) + ",";
    merge << to_string(data_pt(order, m, x)) + ",";
    merge << to_string(data_pt(almost, m, x)) + ",";
    merge << to_string(data_pt(reverse, m, x))+ ", \n";
  }

  //quick sort
  quick << "Size, Unordered, Ordered, Almost ordered, Reverse ordered \n";
  for (int x = 1; x < 10000000; x+=20000){
    quick << to_string(x) + ",";
    quick << to_string(data_pt(unorder, q, x)) + ",";
    quick << to_string(data_pt(order, q, x)) + ",";
    quick << to_string(data_pt(almost, q, x)) + ",";
    quick << to_string(data_pt(reverse, q, x))+ ", \n";
  }

  return 0;
}
