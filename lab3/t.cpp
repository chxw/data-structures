#include <cassert>
#include <iostream>
#include <stdexcept>
#include <string>

#include "Array.hpp"

int main(){
  Array array;

  assert(array.getSize() == 0);
  return 0;
}
