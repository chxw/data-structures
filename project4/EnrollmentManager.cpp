#include "EnrollmentManager.hpp"


EnrollmentManager::EnrollmentManager(){
	year = 2019;
	semester = Semester::SUMMER;
	sd = new StudentDatabase();
	cm = new CourseManager();
}

EnrollmentManager::EnrollmentManager(int yr, Semester sem){
	if (yr < 0){
		throw std::runtime_error("Not Valid");
	}

	year = yr;
	semester = sem;
	sd = new StudentDatabase();
	cm = new CourseManager();
}

EnrollmentManager::EnrollmentManager(const EnrollmentManager& other){
	throw std::runtime_error("Not Implemented");
}

EnrollmentManager& EnrollmentManager::operator=(const EnrollmentManager& other){
	throw std::runtime_error("Not Implemented");
}

// EnrollmentManager::~EnrollmentManager();

bool EnrollmentManager::registerStudent(int studentID, std::string firstName, std::string lastName){
	if (sd->searchBy(studentID) != nullptr){
		return false;
	}

	Student* newbie = new Student(studentID, firstName, lastName);

	sd->insert(newbie);

	if (sd->getNumberOfStudents() % 100 == 0){
		sd->balance();
	}

	return true;
}

// bool unregisterStudent(int studentID);

bool EnrollmentManager::addCourse(std::string courseID, int capacity){
	if (cm->searchBy(courseID) != nullptr){
		return false;
	}

	Course* newbie = new Course (courseID, capacity);
	cm->add(newbie);
	return true;
}

// bool cancelCourse(std::string courseID);

// bool enroll(int studentID, std::string courseID);
// bool drop(int studentID, std::string courseID);

std::string EnrollmentManager::reportSummary() const{
	std::string s;

	if (semester == Semester::SUMMER){
		s += "Summer ";
	}
	else if (semester == Semester::SPRING){
		s += "Spring ";
	}
	else if (semester == Semester::FALL){
		s += "Fall ";
	}

	s += std::to_string(year);
	s += "\n";
	s += "Students: ";
	s += std::to_string(sd->getNumberOfStudents());
	s += "\n";
	s += sd->toStringInOrder();
	s += "\n";
	s += "Courses: ";
	s += std::to_string(cm->getNumberOfCourses());
	s += "\n";
	s += cm->getCourseListString();

}

// std::string report(int studentID) const;
// std::string report(std::string courseID) const;

// int getYear() const;
// Semester getSemester() const;
