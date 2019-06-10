#include "Scheduler.hpp"

#include <iostream>
#include <map>
typedef std::map<int, std::string> BasePairMap;

Scheduler::Scheduler(){
  year = 2019;
  month = 6;
  this->head = nullptr;
}

Scheduler::Scheduler(int y, int m){
  year = y;
  month = m;
  this->head = nullptr;
}

// Scheduler::Scheduler(const Scheduler& other){
//   year = other.getYear();
//   month = other.getMonth();
//   if(other.head == nullptr){
//     this->head = nullptr;
//   }
//   else{
//     Node* current = other.head;
//     while(current != nullptr){
//       Node* next = current->getNext();
//       this->add(current.getData());
//       current = next;
//     }
//   }
// }

// Scheduler& Scheduler::operator=(const Scheduler& other){
//   if(&other != this){
//     y = other.getYear();
//     m = other.getMonth();
//     if (other.isEmpty()){
//       this->head = nullptr;
//     }
//     else{
//       this->head = other.getFirstEventAfter(-1, -1, -1);
//     }
//   }
// }

// Scheduler::~Scheduler(){
//   Node* current = head;
//   while(current != nullptr){
//     Node* next = current->getNext();
//     delete current;
//     current = next;
//   }
// }

void Scheduler::add(Event* event){
  Node* temp = head;
  Node* n = new Node;
  Node node(event);
  n = &node;

  if (temp != NULL){
    while(temp != nullptr){
      temp = temp->getNext();
    }
    temp->setNext(n);
    n = nullptr;
  }
  else{
    head = n;
  }

}

// std::string Scheduler::getFirstEventAfter(int day, int hour, int minute) const{
//   Node* current = head;
//   while(current != nullptr){
//     Node* next = current->getNext();
//     delete current;
//     current = next;
// }

// void removeAllEventsOn(int day);
// void removeAllEvents();

// int getNumberOfEventsOn(int day) const;
// int getNumberOfEvents() const;
// bool isEmpty() const;

// int getYear() const;
// int getMonth() const;

std::string Scheduler::toString() const{
  std::string s;
  // Node* temp = head;

  BasePairMap m;

  //map number to card rank
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
  s += std::to_string(month);
  s += ".";

  s += (head->getData()->toString());

  // if (temp->getNext() == NULL){
  //   s += (temp->getData())->toString();
  // }
  // else if (temp != NULL){
  //   while(temp != nullptr){
  //     s += (temp->getData())->toString();
  //     temp = temp->getNext();
  //   }
  // }
  // else {
  //   s += (head->getData())->toString();
  // }

  return s;
}