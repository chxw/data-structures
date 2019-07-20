#include "Student.hpp"
#include <iostream>

Student::Student(){
	id = 0;
	first = "FIRST";
	last = "LAST";
}

Student::Student(int given_id, std::string firstName, std::string lastName){
	if (given_id < 0 or firstName.length() == 0 or lastName.length() == 0){
		throw std::runtime_error("Not Valid");
	}
	id = given_id;
	first = firstName;
	last = lastName;
}

Student::Student(const Student& other){
	id = other.id;
	first = other.first;
	last = other.last;
}

Student& Student::operator=(const Student& other){
	if (&other != this){
		id = other.id;
		first = other.first;
		last = other.last;
	}
	return (*this);
}

Student::~Student(){
	
}

int Student::getID() const{
	return id;
}

std::string Student::getFirstName() const{
	return first;
}

std::string Student::getLastName() const{
	return last;
}

std::string Student::toString() const{
	std::string s;

	s += std::to_string(id);
	s += " ";
	s += first;
	s += " ";
	s += last;

	return s;
}
