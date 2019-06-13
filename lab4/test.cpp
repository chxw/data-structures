#include <iostream>
#include <cassert>

#include "Node.hpp"
#include "LinkedList.hpp"

int main(){
  LinkedList linkedList;

  std::string expected1 = "|";
  assert(linkedList.toStringInReverseOrder() == expected1);

  int n = 10;
  for(int i = 1; i <= n; i++){
    linkedList.addToBack(i);
  }

  std::string expected2 = "|<-10<-9<-8<-7<-6<-5<-4<-3<-2<-1";
  assert(linkedList.toStringInReverseOrder() == expected2);

  int t = 5;
  for(int i = 0; i < t; i++){
    linkedList.removeBack();
  }

  std::string expected3 = "|<-5<-4<-3<-2<-1";
  assert(linkedList.toStringInReverseOrder() == expected3);

  return 0;
}
