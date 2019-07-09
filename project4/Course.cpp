#include "Course.hpp"

Course::Course(){
	id = "COMP-000";
	capacity = 1;
	data = new int[capacity];
	enrolled = 0;
}

Course::Course(std::string courseID, int courseCapacity){
	if (courseID.size() == 0 or courseCapacity <= 0){
		throw std::runtime_error("Not Valid");
	}
	id = courseID;
	capacity = courseCapacity;
}

Course::Course(const Course& other){
	id = other.id;
	capacity = other.capacity;
}

Course& Course::operator=(const Course& other){
	if (&other != this){
		id = other.id;
		capacity = other.capacity;
	}
	return (*this);
}

Course::~Course(){

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
	enrolled++;
	return true;
}

bool Course::drop(int studentID){
	if (isHaving(studentID) == false){
		return false;
	}

	int *temp = new int[capacity];
	bool passed = false;

	// resize and drop studentID
	for (int i = 0; i < capacity; i++){
		if (data[i] == studentID){
			passed = true;
			continue;
		}
		if (!passed){
			temp[i] = data[i];
		}
		else if (passed){
			temp[i] = data[i+1];
		}
	}

	return true;
}

bool Course::isHaving(int studentID){
	for (int i = 0; i < capacity; i++){
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
	s += enrolled;
	s += "/";
	s += capacity;
	s += ")";

	return s;
}