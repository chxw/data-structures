#include "Scheduler.hpp"

#include <iostream>
#include <map>

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
  	this->add(event);
  }
  else{
    Node* current = other.head;
    while(current != nullptr){
      Node* next = current->getNext();
      Event* event = new Event(*(current->getData()));
      this->add(event);
      current = next;
    }
  }
}

Scheduler& Scheduler::operator=(const Scheduler& other){
  if(&other != this){
    this->removeAllEvents();
    year = other.getYear();
    month = other.getMonth();
    num_events = 0;
    if(other.head == nullptr){
      this->head = nullptr;
    }
    else if((other.head)->getNext() == nullptr){
  	  Event* event = new Event(*(other.head)->getData());
  	  this->add(event);
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

Scheduler::~Scheduler(){
  Node* current = head;
  while(current != nullptr){
    Node* next = current->getNext();
    delete current->getData();
    delete current;
    current = next;
  }
  head = nullptr;
}

void Scheduler::add(Event* event){
  ////// requirements check
  // map month to number of days in that month
  typedef std::map<int, int> BasePairMap;
  BasePairMap m;

  m[1] = 31;
  // for leap years
  if (year % 4 == 0){
  	if (year % 100 == 0 and year % 400 == 0){
  		m[2] = 29;
  	}
  }
  else{
  	m[2] = 28;
  }
  m[3] = 31;
  m[4] = 30;
  m[5] = 31;
  m[6] = 30;
  m[7] = 31;
  m[8] = 31;
  m[9] = 30;
  m[10] = 31;
  m[11] = 30;
  m[12] = 31;

  // given event must be in range, description must be at least one char long
  if(event->getDay() < 0 or event->getDay() > m[month] or event->getHour() < 0 or event->getHour() > 23 or 
  	event->getMinute() < 0 or event->getMinute() > 59 or (event->getDescription()).length() < 1){
  	throw std::runtime_error("Not Legal Event");
  }

  ////// ordering
  // empty list
  if (this->isEmpty()){
    Node* newbie = new Node(event);
    newbie->setNext(nullptr);

    head = newbie;

    num_events += 1;
  }
  // time conflict with head
  else if (event->startAtSameTime(head->getData())){
    throw std::range_error("Event Time Conflict");
  }
  // event before head
  else if (event->startBefore(head->getData())){
    Node* newbie = new Node(event);
    newbie->setNext(head);

    head = newbie;

    num_events += 1;
  }
  // event after head
  else if (head->getNext() == nullptr and event->startAfter(head->getData())){
    Node* newbie = new Node(event);
    head->setNext(newbie);

    num_events += 1;
  }
  // traverse through
  else{
    Node* previous = nullptr;
    Node* temp = head;

    while(temp != nullptr){
      // ∃ event that conflicts with given event
      if (event->startAtSameTime(temp->getData())){
        throw std::range_error("Event Time Conflict");
      }
      // place event before first event it starts before (given each events always added this way)
      else if (event->startBefore(temp->getData())) {
        Node* newbie = new Node(event);

        previous->setNext(newbie);
        newbie->setNext(temp);

        num_events += 1;
        return;
      }
      previous = temp;
      temp = temp->getNext();
    }
    // place event at end if it never starts before an already existing event
    Node* newbie = new Node(event);
    newbie->setNext(nullptr);
    previous->setNext(newbie);
    num_events += 1;
  }
}

std::string Scheduler::getFirstEventAfter(int day, int hour, int minute) const{
  // check empty
	if (head == nullptr){
		return "No Event Found";
	}
  // check only head
	else if (head->getNext() == nullptr){
		if (head->getData()->startAfter(day, hour, minute)){
			return head->getData()->toString();
		}
		return "No Event Found";
	}
  // traverse through
	else {
    Node* current = head;
		while(current != nullptr){
			if(current->getData()->startBefore(day, hour, minute) and current->getNext()->getData()->startAfter(day, hour, minute)){
				return current->getNext()->getData()->toString();
			}
			current = current->getNext();
		}
		return "No Event Found";
	}
}

void Scheduler::removeAllEventsOn(int day){
  if (head != nullptr){
	  if (head->getData()->getDay() == day){
	  	delete head;
	  	head = nullptr;
	  }
	  else{
	  	Node* previous = head;
 		  Node* current = head->getNext();
		  while(current != nullptr){
		    if (current->getData()->getDay() == day){
		    	previous->setNext(current->getNext());
          delete current->getData();
		    	delete current;
		    	current = previous->getNext();

		    }
		    else {
			    previous = current;
			    current = current->getNext();
			}
		  }
	  }
  }
}

void Scheduler::removeAllEvents(){
  Node* current = head;
  while(current != nullptr){
    Node* next = current->getNext();
    delete current->getData();
    delete current;
    current = next;
  }
  head = nullptr;
}

int Scheduler::getNumberOfEventsOn(int day) const{
	Node* temp = this->head;
	int count = 0;

	while(temp != nullptr){
      if (temp->getData()->getDay() == day){
      	count++;
      }
      temp = temp->getNext();
  	}
  return count;
}

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

  typedef std::map<int, std::string> BasePairMap;
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
    if (temp->getNext() != nullptr){
      s += "\n";
    }
    temp = temp->getNext();
  }

  return s;
}