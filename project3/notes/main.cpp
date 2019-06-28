#include <cassert>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <iostream>

void swap(int &a, int &b){
    int hold = a;
    a = b;
    b = hold;
}

void traverse(int* const array, int key){
    int i = key - 1;
    while(array[key] < array[i]){
        std::cout << "key = ";
        std::cout << key << std::endl;

        std::cout << "i = ";
        std::cout << i << std::endl;

        if(key == 0){
            return;
        }
        else if(array[key] < array[i]){
            swap(array[i], array[key]);
        }
        key--;
        i--;
    }
}

void sort(int* const array, int size){
    int key = 1;

    for (int i = 0; i < size; i++){
        if(array[key] < array[i]){
            traverse(array, key);
        }
        key++;
    }
    std::cout << "here" << std::endl;
}

bool isSorted(int* const array, int size){
  for (int i = 0; i < size; i++){
    if (array[i] > array[i+1]){
      return false;
    }
  }
  return true;
}

void unordered(int size){
  time_t t;
  srand((unsigned) time(&t));

  int* array = new int[size];
  for(int i = 0; i < size; i++)
    array[i] = (rand() % size) + 1;

  sort(array, size);

  bool b = isSorted(array, size);
  assert(b == true);
  delete [] array;
}

void ordered(int size){
  int* array = new int[size];
  for(int i = 0; i < size; i++)
    array[i] = i;

  sort(array, size);

  bool b = isSorted(array, size);
  assert(b == true);
  delete [] array;
}

int main(){
  unordered(5);
  unordered(30);
  unordered(40);
  unordered(50);
  unordered(60);
  unordered(80);
}