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

EnrollmentManager::~EnrollmentManager(){
	delete cm;
	delete sd;
}

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

bool EnrollmentManager::unregisterStudent(int studentID){
	cm->dropFromAllCourses(studentID);
	return sd->deleteBy(studentID);

}

bool EnrollmentManager::addCourse(std::string courseID, int capacity){
	if (cm->searchBy(courseID) != nullptr){
		return false;
	}

	Course* newbie = new Course (courseID, capacity);
	cm->add(newbie);
	return true;
}

bool EnrollmentManager::cancelCourse(std::string courseID){
	return cm->cancel(courseID);
}

bool EnrollmentManager::enroll(int studentID, std::string courseID){
	if ((cm->getAllEnrolledCoursesStringOf(studentID)).find(courseID) != std::string::npos){
		return false;
	}

	cm->enroll(studentID, courseID);
	return true;
}

bool EnrollmentManager::drop(int studentID, std::string courseID){
	return cm->drop(studentID, courseID);
}

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

	return s;
}

std::string EnrollmentManager::report(int studentID) const{
	std::string s;

	s += (sd->searchBy(studentID))->toString();
	s += "\n";
	s += cm->getAllEnrolledCoursesStringOf(studentID);

	return s;
}

std::string EnrollmentManager::report(std::string courseID) const{
	std::string s;

	const Course* course = cm->searchBy(courseID);
	s += course->toString();
	s += "\n";
	for (int i = 0; i < course->getNumberOfEnrolledStudents(); i++){
		s += std::to_string(course->getStudentIDAt(i));
		s += "\n";
	}

	s.pop_back();
	return s;
}

int EnrollmentManager::getYear() const{
	return year;
}

Semester EnrollmentManager::getSemester() const{
	return semester;
}
