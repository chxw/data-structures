#include "Scheduler.hpp"

#include <iostream>
#include <map>
typedef std::map<int, std::string> BasePairMap;

Scheduler::Scheduler(){
  year = 2019;
  month = 6;
  num_events = 0;
  this->head = nullptr;
}

Scheduler::Scheduler(int y, int m){
  if (y < 0 or m > 12 or m < 1){
    throw std::range_error("Out of Range");
  }
  year = y;
  month = m;
  num_events = 0;
  this->head = nullptr;
}

Scheduler::Scheduler(const Scheduler& other){
  year = other.getYear();
  month = other.getMonth();
  num_events = 0;
  if(other.head == nullptr){
    this->head = nullptr;
  }
  else if((other.head)->getNext() == nullptr){
  	Event* event = new Event(*((other.head)->getData()));
  	Node* newbie = new Node(event);
  	this->head = newbie;
  }
  else{
    Node* current = other.head;
    while(current != nullptr){
      Node* next = current->getNext();
      Event* event = new Event(*(current->getData()));
      this->add(event);
      event = nullptr;
      current = next;
    }
  }
}

Scheduler& Scheduler::operator=(const Scheduler& other){
  if(&other != this){
    year = other.getYear();
    month = other.getMonth();
    num_events = 0;
    if(other.head == nullptr){
      this->head = nullptr;
    }
    else if((other.head)->getNext() == nullptr){
  	  Event* event = new Event(*(other.head)->getData());
  	  Node* newbie = new Node(event);
  	  this->head = newbie;
    }
    else{
      Node* current = other.head;
      while(current != nullptr){
        Node* next = current->getNext();
        Event* event = new Event(*(current)->getData());
  	    this->add(event);
        current = next;
      }
    }
  }
  return(*this);
}

// Scheduler::~Scheduler(){
//   Node* current = head;
//   while(current != nullptr){
//     Node* next = current->getNext();
//     delete current;
//     current = next;
//   }
// }

void Scheduler::add(Event* event){
  Node* previous = nullptr;
  Node* temp = head;
  Node* newbie = new Node(event);
  newbie->setNext(nullptr);

  // ordering
  if (this->isEmpty()){
    head = newbie;
    num_events += 1;
  }
  else if (event->startAtSameTime(head->getData())){
    throw std::range_error("Event Time Conflict");
  }
  else if (event->startBefore(head->getData())){
    newbie->setNext(head);
    head = newbie;
    num_events += 1;
  }
  else if (head->getNext() == nullptr and event->startAfter(head->getData())){
    head->setNext(newbie);
    num_events += 1;
  }
  else{
    while(temp != nullptr){
      if (event->startAtSameTime(temp->getData())){
        throw std::range_error("Event Time Conflict");
      }
      else if (event->startBefore(temp->getData()) or event->startAtSameTime(temp->getData())){
        previous->setNext(newbie);
        newbie->setNext(temp);
        num_events += 1;
        return;
      }
      previous = temp;
      temp = temp->getNext();
    }
    previous->setNext(newbie);
    num_events += 1;
  }
}

// std::string Scheduler::getFirstEventAfter(int day, int hour, int minute) const{
// void removeAllEventsOn(int day);
// void removeAllEvents();

// int getNumberOfEventsOn(int day) const;
int Scheduler::getNumberOfEvents() const{
  return num_events;
}

bool Scheduler::isEmpty() const{
  if (num_events == 0){
    return true;
  }
  return false;
}

int Scheduler::getYear() const{
	return year;
}

int Scheduler::getMonth() const{
	return month;
}

std::string Scheduler::toString() const{
  std::string s;
  Node* temp = this->head;

  BasePairMap m;

  //map number to month name
  m[1] = "Jan";
  m[2] = "Feb";
  m[3] = "Mar";
  m[4] = "Apr";
  m[5] = "May";
  m[6] = "Jun";
  m[7] = "Jul";
  m[8] = "Aug";
  m[9] = "Sep";
  m[10] = "Oct";
  m[11] = "Nov";
  m[12] = "Dec";

  s += std::to_string(year);
  s += " ";
  s += m[month];
  s += ".";
  s += "\n";

  while(temp != nullptr){
    s += (temp->getData())->toString();
    s += "\n";
    temp = temp->getNext();
  }

  return s;
}