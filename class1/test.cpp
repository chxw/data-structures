#include <cassert>
#include "Array.hpp"

int main(){
  Array a;
  a.add(0);
  a.add(1);
  a.add(2);

  Array a2 = a;

  Array a3;
  a3 = a2; 

  assert(a3.getSize() == a2.getSize());
  return 0;
}
