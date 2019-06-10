#ifndef SCHEDULER_HPP
#define SCHEDULER_HPP

#include <string>
#include "Event.hpp"
#include "Node.hpp"

class Scheduler{
public:
  Scheduler();
  Scheduler(int y, int m);
  Scheduler(const Scheduler& other);
  Scheduler& operator=(const Scheduler& other);
  // ~Scheduler();

  void add(Event* event);
  // std::string getFirstEventAfter(int day, int hour, int minute) const;

  // void removeAllEventsOn(int day);
  // void removeAllEvents();

  // int getNumberOfEventsOn(int day) const;
  int getNumberOfEvents() const;
  bool isEmpty() const;

  int getYear() const;
  int getMonth() const;
  std::string toString() const;

private:
  int year;
  int month;
  int num_events;
  Node* head;
};

#endif
