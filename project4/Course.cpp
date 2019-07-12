#include "Course.hpp"
#include <iostream>
#include <stdexcept>

Course::Course(){
	id = "COMP-000";
	enrolled = 0;
	capacity = 1;
	data = new int[capacity];
}

Course::Course(std::string courseID, int courseCapacity){
	if (courseID.size() == 0 or courseCapacity <= 0){
		throw std::runtime_error("Not Valid");
	}	
	id = courseID;
	enrolled = 0;
	capacity = courseCapacity;
	data = new int[capacity];
}

Course::Course(const Course& other){
	id = other.id;
	enrolled = other.enrolled;
	capacity = other.capacity;
	data = new int[capacity];

	for (int i = 0; i < other.enrolled; i++){
		data[i] = other.data[i];
	}
}

Course& Course::operator=(const Course& other){
	if (&other != this){
		delete [] data;
		id = other.id;
		capacity = other.capacity;
		enrolled = other.enrolled;

		data = new int[capacity];

		for (int i = 0; i < other.enrolled; i++){
			data[i] = other.data[i];
		}
	}
	return (*this);
}

Course::~Course(){
	delete [] data;
}

bool Course::isFull() const{
	if (enrolled == capacity){
		return true;
	}
	return false;
}

bool Course::enroll(int studentID){
	if (isFull()){
		return false;
	}
	data[enrolled] = studentID;
	enrolled += 1;
	return true;
}

bool Course::drop(int studentID){
	if (isHaving(studentID) == false){
		return false;
	}

	int *temp = new int[capacity];
	int index;

	// resize data and drop studentID
	for (int i = 0; i < enrolled; i++){
		if (data[i] == studentID){
			index = i;
			break;
		}
	}

	for (int i = 0; i < enrolled - 1; i++){
		if (i >= index){
			temp[i] = data[i+1];
		}
		else{
			temp[i] = data[i];
		}
	}

	delete [] data;
	data = temp;
	temp = nullptr;

	enrolled--;
	return true;
}

bool Course::isHaving(int studentID){
	for (int i = 0; i < enrolled; i++){
		if (data[i] == studentID){
			return true;
		}
	}
	return false;
}

std::string Course::getID() const{
	return id;
}

int Course::getCapacity() const{
	return capacity;
}

int Course::getNumberOfEnrolledStudents() const{
	return enrolled;
}

int Course::getStudentIDAt(int index) const{
	return data[index];
}

std::string Course::toString() const{
	std::string s;

	s += id;
	s += " (";
	s += std::to_string(enrolled);
	s += "/";
	s += std::to_string(capacity);
	s += ")";

	return s;
}
