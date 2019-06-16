#include <cassert>
#include <climits>
#include <iostream>
#include <stdexcept>
#include <string>

#include "Scheduler.hpp"

void deep_copy(){
  Event* e = new Event();
  std::string sample = e->toString();

  Event* e2 = new Event(30,23,59, "feed dog");
  std:: string sample2 = e2->toString();

  Event* e3 = new Event();
  std::string sample3 = e3->toString();

  Event* e4 = new Event(10,10,10, "dance");

  Event* e5 = new Event(6, 2, 35, "birthday");

  Event* e6 = new Event(6, 9, 0, "get drink");

  assert(e->startBefore(e2));
  assert(e2->startAfter(e));
  assert(e3->startAtSameTime(e));
  assert(e->startBefore(30,23,59));
  assert(e2->startAfter(29,22,58));
  assert(e2->startAt(30,23,59));

  std::cout << "Events in order: " << std::endl;
  std::cout << e->toString() << std::endl;
  std::cout << e2->toString() << std::endl;
  std::cout << e3->toString() << std::endl;
  std::cout << e4->toString() + "\n" << std::endl;

  Scheduler s1;
  s1.add(e);
  Scheduler s2(s1);
  s1.add(e2);
  Scheduler s3 = s1;

  std::string message;
  try {
    s1.add(e3);
  }
  catch(std::range_error& e){
    message = e.what();
  }
  assert(message == "Event Time Conflict");
  delete e3;

  s1.add(e4);
  Scheduler s4(s1);

  s1.add(e5);
  s1.add(e6);

  Scheduler* s1_copy = new Scheduler(s1);

  std::cout << "\n Deep copy test \n";

  std::cout << "s1 : \n" + s1.toString() << std::endl;
  std::cout << "s1_copy : \n" + s1_copy->toString() << std::endl;
  std::cout << "s2 : \n" + s2.toString() << std::endl;
  std::cout << "s3 : \n" + s3.toString() << std::endl;
  std::cout << "s4 : \n" + s4.toString() << std::endl;
  
  delete s1_copy;
  s1.removeAllEvents();

  std::cout << "\n Remove events in s1 && delete s1_copy \n";

  std::cout << "s1 : \n" + s1.toString() << std::endl;
  std::cout << "s2 : \n" + s2.toString() << std::endl;
  std::cout << "s3 : \n" + s3.toString() << std::endl;
  std::cout << "s4 : \n" + s4.toString() << std::endl;

  std::cout << "\n ================ End of deep copy test ================ \n";
}

void logic_test(){
  std::cout << "\n Logic test \n" << std::endl;

  Event* e = new Event();
  Event* e2 = new Event(30,23,59, "feed dog");
  Event* e3 = new Event();
  Event* e4 = new Event(10,10,10, "dance");
  Event* e5 = new Event(6, 2, 35, "birthday");
  Event* e6 = new Event(6, 9, 0, "get drink");
  Event* e7 = new Event(32,60,-1, "");
  Event* e8 = new Event(10, 1, 2, "shopping");

  Scheduler s4;
  s4.add(e);
  s4.add(e2);

  std::string message;
  try {
    s4.add(e3);
  }
  catch(std::range_error& e){
    message = e.what();
  }
  assert(message == "Event Time Conflict");
  delete e3;

  s4.add(e4);
  s4.add(e5);
  s4.add(e6);

  std::string message2;
  try {
    s4.add(e7);
  }
  catch(std::runtime_error& e){
    message2 = e.what();
  }
  assert(message2 == "Not Legal Event");
  delete e7;

  s4.add(e8);

  std::cout << "s4 : \n" + s4.toString() << std::endl;

  std::cout << "\n number of events on day 10 : ";
  std::cout << s4.getNumberOfEventsOn(10) << std::endl;

  std::cout << "\n first event after [10 00:00] : ";
  std::cout << s4.getFirstEventAfter(10, 0, 0) << std::endl;

  std::cout << "\n remove all events on 10 : ";
  s4.removeAllEventsOn(10);
  std::cout << "\n s4 : \n" + s4.toString() << std::endl;

  std::cout << "\n number of events on day 10 : ";
  std::cout << s4.getNumberOfEventsOn(10) << std::endl;

  std::cout << "\n remove all events : ";
  s4.removeAllEvents();
  std::cout << "\n s4 : \n" + s4.toString() << std::endl;

  std::cout << "\n remove all events on 0 : ";
  s4.removeAllEventsOn(0);
  std::cout << "\n s4 : \n" + s4.toString() << std::endl;

  std::cout << "\n ================ End of logic test ================ \n"; 
}

int main(){
  deep_copy();
  logic_test();
  return 0;
}
