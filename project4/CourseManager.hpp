#ifndef COURSEMANAGER_HPP
#define COURSEMANAGER_HPP

#include <string>
#include <stdexcept>

#include "Course.hpp"

class CourseManager{
public:
  CourseManager();
  CourseManager(const CourseManager& other);
  CourseManager& operator=(const CourseManager& other);
  ~CourseManager();

  const Course* searchBy(std::string courseID) const;
  bool add(Course* course);
  bool cancel(std::string courseID);

  bool enroll(int studentID, std::string courseID);
  bool drop(int studentID, std::string courseID);
  void dropFromAllCourses(int studentID);
  std::string getAllEnrolledCoursesStringOf(int studentID);

  int getNumberOfCourses() const;
  std::string getCourseListString() const;

private:
  //your design
  Course **array;
  int size;
  int capacity;
};

#endif
