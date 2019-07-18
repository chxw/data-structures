#include <cassert>
#include <string>
#include <iostream>

#include "hasher.hpp"

void test1(){
  std::string key;

  std::cin >> key;

  if (key == ""){
  	return;
  }

  unsigned int hashCode = generateHashCodeOf(key);

  std::cout << "h = " << hashCode << std::endl;

  // unsigned int expected = 0;  You will need to change this. 

  // assert(hashCode == expected);
}

int main(){
  test1();
  return 0;
}
