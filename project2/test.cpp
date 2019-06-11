#include <cassert>
#include <climits>
#include <iostream>
#include <stdexcept>
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

  Event* e4;
  Event event4(10,10,10, "dance");
  e4 = &event4;

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

  std::cout << "Events in order: " << std::endl;
  std::cout << e->toString() << std::endl;
  std::cout << e2->toString() << std::endl;
  std::cout << e3->toString() << std::endl;
  std::cout << e4->toString() + "\n" << std::endl;

  Scheduler* s1 = new Scheduler;
  s1->add(e);
  Scheduler s2(*s1);
  s1->add(e2);
  Scheduler s3(*s1);

  std::string message;
  try {
    s1->add(e3);
  }
  catch(std::range_error& e){
    message = e.what();
  }
  assert(message == "Event Time Conflict");

  s1->add(e4);
  Scheduler s4(*s1);

  delete s1;

  std::cout << "s2 : \n" + s2.toString() << std::endl;
  std::cout << "s3 : \n" + s3.toString() << std::endl;
  std::cout << "s4 : \n" + s4.toString() << std::endl;

  Event* e5;
  Event event5(32,60,-1, "");
  e5 = &event5;

  std::string message2;
  try {
    s4.add(e5);
  }
  catch(std::runtime_error& e){
    message2 = e.what();
  }
  assert(message2 == "Not Legal Event");

  Event* e6;
  Event event6(10, 1, 2, "shopping");
  e6 = &event6;

  s4.add(e6);
  std::cout << "s4 : \n" + s4.toString() << std::endl;
  std::cout << "number of events on day 10 : ";
  std::cout << s4.getNumberOfEventsOn(10) << std::endl;
}

int main(){
  test1();
  return 0;
}
