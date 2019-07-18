#include <cassert>
#include <string>

#include "hasher.hpp"

void test1(){
  std::string key = "Comp15";
  unsigned int hashCode = generateHashCodeOf(key);

  unsigned int expected = 0; /* You will need to change this. */

  assert(hashCode == expected);
}

int main(){
  test1();
  return 0;
}
