#include <iostream>
#include <cassert>

#include "Node.hpp"
#include "LinkedList.hpp"

int main(){
  LinkedList ll;

  int n = 10;

  for(int i = 1; i <= n; i++){
    ll.addToBack(i);
  }

  std::cout << ll.getSize() << std::endl;

  std::cout << ll.toStringInReverseOrder() << std::endl;

  return 0;
}
