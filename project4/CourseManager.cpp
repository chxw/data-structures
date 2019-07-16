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

// ~CourseManager();

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

// bool drop(int studentID, std::string courseID);
// void dropFromAllCourses(int studentID);
// std::string getAllEnrolledCoursesStringOf(int studentID);

// int getNumberOfCourses() const;
std::string CourseManager::getCourseListString() const{
	std::string s;

	for (int i = 0; i < size; i++){
		s += array[i]->getID();
		s += ",";
	}

	return s;
}