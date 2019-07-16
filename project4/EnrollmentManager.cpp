#include "EnrollmentManager.hpp"


EnrollmentManager::EnrollmentManager(){
	year = 2019;
	semester = Semester::SUMMER;
}

EnrollmentManager::EnrollmentManager(int yr, Semester sem){
	year = yr;
	semester = sem;
}

EnrollmentManager::EnrollmentManager(const EnrollmentManager& other){
	throw std::runtime_error("Not Implemented");
}

EnrollmentManager& EnrollmentManager::operator=(const EnrollmentManager& other){
	throw std::runtime_error("Not Implemented");
}

// EnrollmentManager::~EnrollmentManager();

// bool registerStudent(int studentID, std::string firstName, std::string lastName);
// bool unregisterStudent(int studentID);

// bool addCourse(std::string courseID, int capacity);
// bool cancelCourse(std::string courseID);

// bool enroll(int studentID, std::string courseID);
// bool drop(int studentID, std::string courseID);

// std::string reportSummary() const;
// std::string report(int studentID) const;
// std::string report(std::string courseID) const;

// int getYear() const;
// Semester getSemester() const;
