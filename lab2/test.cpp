#include <iostream>
#include <cassert>

#include "Node.hpp"
#include "LinkedList.hpp"

int main(){
  LinkedList linkedList;

  int n = 10;
  for(int i = 1; i <= n; i++){
    linkedList.addToFront(i);
  }

  std::string expected1 = "10->9->8->7->6->5->4->3->2->1->|";
  assert(linkedList.toString() == expected1);

  int t = 5;
  for(int i = 0; i < t; i++){
    linkedList.removeFront();
  }

  std::string expected2 = "5->4->3->2->1->|";
  assert(linkedList.toString() == expected2);

  return 0;
}
