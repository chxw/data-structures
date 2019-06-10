#include <cassert>
#include <iostream>
#include <string>

#include "Scheduler.hpp"

void test1(){
  Event* e;
  Event event;
  e = &event;
  std::string sample = event.toString();

  Event* e2;
  Event event2(30,23,59, "feed dog");
  e2 = &event2;
  std:: string sample2 = event2.toString();

  Event* e3;
  Event event3;
  e3 = &event3;
  std::string sample3 = event3.toString();

  assert(event.startBefore(e2));
  assert(event2.startAfter(e));
  assert(event3.startAtSameTime(e));
  assert(event.startBefore(30,23,59));
  assert(event2.startAfter(29,22,58));
  assert(event2.startAt(30,23,59));

  Node n1;
  n1.getData();

  Node n2(e);
  std::string sample5 = (n2.getData())->toString();
  Node n3 = n2; 
  std::string sample6 = (n3.getData())->toString();

  assert(sample5 == "[01 00:00] SAMPLE");
  assert(sample5 == sample6);

  Node* n4;
  Node node4(e2);
  n4 = &node4;

  n2.setNext(n4);
  std::string sample7 = ((n2.getNext())->getData())->toString();
  assert(sample7 == sample2);

  Scheduler s1;
  s1.add(e);

  std::cout << s1.toString() << std::endl;
}

int main(){
  test1();
  return 0;
}
