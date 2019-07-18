#include <cassert>
#include <string>
#include <iostream>

#include "hasher.hpp"

void test1(){
  std::string key = "Comp15";

  if (key == ""){
  	return;
  }

  unsigned int hashCode = generateHashCodeOf(key);

  unsigned int expected = 13226;

  assert(hashCode == expected);
}

int main(){
  test1();
  return 0;
}
