#include <cassert>
#include <climits>
#include <iostream>
#include <stdexcept>
#include <string>

#include "Array.hpp"

int add(int n1, int n2){
  int sum = n1 + n2;
  if (n1 > INT_MAX - n2) {
    throw std::overflow_error("OVERFLOW");
  }
  else if (n1 < INT_MIN + n2) {
    throw std::underflow_error("UNDERFLOW");
  }
  else {
    return sum;
  }
}

int main(){
            //index: 0               1    2  3  4  5  6  7  8  9  10 11 12  13  14
  int numbers[15] = {(INT_MIN + 10), -15, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 15, (INT_MAX - 10)};

  Array array;

  assert(array.getSize() == 0);
  assert(array.getCapacity() == 5);

  for(int i = 0; i < 15; i++){
    array.add(numbers[i]);
  }

  assert(array.getSize() == 15);
  assert(array.getCapacity() == 20);
  for(int i = 0; i < 15; i++){
    assert(array.at(i) == numbers[i]);
  }

  //===(1)
  std::string message1 = "";
  std::string expected1 = "OUT OF RANGE: 15";

  try{array.at(15);}
  catch(std::range_error& e){
    message1 = e.what();
  }


  assert(message1 == expected1);
  //===(1)

  //===(2)
  std::string message2 = "";
  std::string expected2 = "OUT OF RANGE: -1";

  try{array.at(-1);}
  catch(std::range_error& e){
    message2 = e.what();
  }


  assert(message2 == expected2);
  //===(2)

  int a9 = array.at(9);
  int a10 = array.at(10);
  int n1 = add(a9, a10);
  assert(n1 == 15);

  int a13 = array.at(13);
  int a14 = array.at(14);

  //===(3)
  std::string message3 = "";
  std::string expected3 = "OVERFLOW";

  try{add(a13, a14);}
  catch(std::overflow_error& e){
    message3 = e.what();
  }


  assert(message3 == expected3);
  //===(3)

  //===(4)
  std::string message4 = "";
  std::string expected4 = "OVERFLOW";


  try{add(a14, a13);}
  catch(std::overflow_error& e){
    message4 = e.what();
  }


  assert(message4 == expected4);
  //===(4)

  int a0 = array.at(0);
  int a1 = array.at(1);

  //===(5)
  std::string message5 = "";
  std::string expected5 = "UNDERFLOW";


  try{add(a0, a1);}
  catch(std::underflow_error& e){
    message5 = e.what();
  }


  assert(message5 == expected5);
  //===(5)

  //===(6)
  std::string message6 = "";
  std::string expected6 = "UNDERFLOW";

  try{ add(a1, a0);}
  catch(std::underflow_error& e){
    message6 = e.what();
  }



  assert(message6 == expected6);
  //===(6)

  return 0;
}
