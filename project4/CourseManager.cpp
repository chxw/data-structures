#include "CourseManager.hpp"


CourseManager::CourseManager(){
	size = 0;
	capacity = 100;
	array = new Course*[capacity];
}

CourseManager::CourseManager(const CourseManager& other){
	throw std::runtime_error("Not Implemented");
}

CourseManager& CourseManager::operator=(const CourseManager& other){
	throw std::runtime_error("Not Implemented");
}

CourseManager::~CourseManager(){
	delete [] array;
}

const Course* CourseManager::searchBy(std::string courseID) const{
	for (int i = 0; i < size; i++){
		if (array[i]->getID() == courseID){
			return array[i];
		}
	}

	return nullptr;
}

bool CourseManager::add(Course* course){
	if (course == nullptr){
		return false;
	}
	if (searchBy(course->getID()) != nullptr){
		return false;
	}
	if (size == capacity){
		throw std::runtime_error("Not Valid");
	}

	array[size] = course;
	size++;

	return true;
}

bool CourseManager::cancel(std::string courseID){
	int index;

	if (searchBy(courseID) == nullptr){
		return false;
	}

	for (int i = 0; i < size; i++){
		if (array[i]->getID() == courseID){
			delete array[i];
			index = i;
		}
	}

	Course **temp = new Course*[capacity];

	for (int i = 0; i < index; i++){
		temp[i] = array[i];
	}
	for (int i = index; i < size; i++){
		temp[i] = array[i+1];
	}

	delete [] array;
	array = temp;
	temp = nullptr;
	size--;

	return true;
}

bool CourseManager::enroll(int studentID, std::string courseID){
	for (int i = 0; i < size; i++){
		if (array[i]->getID() == courseID){
			return array[i]->enroll(studentID);
		}
	}

	return false;
}

bool CourseManager::drop(int studentID, std::string courseID){
	for (int i = 0; i < size; i++){
		if (array[i]->getID() == courseID){
			array[i]->drop(studentID);
			return true;
		}
	}

	return false;
}

void CourseManager::dropFromAllCourses(int studentID){
	for (int i = 0; i < size; i++){
		if (array[i]->isHaving(studentID)){
			array[i]->drop(studentID);
		}
	}
}

std::string CourseManager::getAllEnrolledCoursesStringOf(int studentID){
	std::string s = "";

	for (int i = 0; i < size; i++){
		if (array[i]->isHaving(studentID)){
			s += array[i]->getID();
			s += ",";
		}
	}

	s.pop_back();
	return s;
}

int CourseManager::getNumberOfCourses() const{
	return size;
}

std::string CourseManager::getCourseListString() const{
	std::string s;

	for (int i = 0; i < size; i++){
		s += array[i]->getID();
		s += ",";
	}

	s.pop_back();
	return s;
}