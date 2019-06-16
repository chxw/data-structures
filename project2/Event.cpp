#include "Event.hpp"
#include <iostream>

Event::Event(){
	dd = 1;
	HH = 0;
	MM = 0;
	desc = "SAMPLE";
}

Event::Event(int day, int hour, int minute, std::string description){
	dd = day;
	HH = hour;
	MM = minute;
	desc = description;
}

Event::Event(const Event& other){
	dd = other.getDay();
	HH = other.getHour();
	MM = other.getMinute();
	desc = other.getDescription();
}

Event& Event::operator=(const Event& other){
	if(&other != this){
		dd = other.getDay();
		HH = other.getHour();
		MM = other.getMinute();
		desc = other.getDescription();
	}
	return(*this);
}

Event::~Event(){
	
}

bool Event::startBefore(const Event* another) const{
	if(another == nullptr)	{
		return false;
	}
	// return true if other event starts after this event
	else if(another->getDay() > dd){
		return true;
	}
	else if(another->getDay() == dd){
		if(another->getHour() > HH){
			return true;
		}
		else if(another->getHour() == HH){
			if(another->getMinute() > MM){
				return true;
			}
		}
	}
	return false;
}

bool Event::startAfter(const Event* another) const{
	if(another == nullptr){
		return false;
	}
	// return true if other event starts before this event
	else if(another->startBefore(this)){
		return true;
	}
	return false;
}

bool Event::startAtSameTime(const Event* another) const{
	if(another == nullptr){
		return false;
	}
	else if(another->getDay() == dd and another->getHour() == HH and another->getMinute() == MM){
		return true;
	}
	return false;
}

bool Event::startBefore(int day, int hour, int minute) const{
	Event* e;
	Event event(day, hour, minute, "SAMPLE");
	e = &event;

	return this->startBefore(e);
}

bool Event::startAfter(int day, int hour, int minute) const{
	Event* e;
	Event event(day, hour, minute, "SAMPLE");
	e = &event;

	return this->startAfter(e);
}

bool Event::startAt(int day, int hour, int minute) const{
	Event* e;
	Event event(day, hour, minute, "SAMPLE");
	e = &event;

	return this->startAtSameTime(e);
}

int Event::getDay() const{
	return dd;
}

int Event::getHour() const{
	return HH;
}

int Event::getMinute() const{
	return MM;
}

std::string Event::getDescription() const{
	return desc;
}

std::string Event::toString() const{
	std::string s;

	s += "[";
	if (dd < 10){
		s += "0";
	}
	s += std::to_string(dd);
	s += " ";
	if (HH < 10){
		s += "0";
	}
	s += std::to_string(HH);
	s += ":";
	if (MM < 10){
		s += "0";
	}
	s += std::to_string(MM);
	s += "] ";
	s += desc;

	return s;
}