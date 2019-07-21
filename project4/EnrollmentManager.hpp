#ifndef ENROLLMENTMANAGER_HPP
#define ENROLLMENTMANAGER_HPP

#include <string>

#include "StudentDatabase.hpp"
#include "CourseManager.hpp"

enum class Semester{
  SPRING,
  SUMMER,
  FALL
};

class EnrollmentManager{
public:
  EnrollmentManager();
  EnrollmentManager(int yr, Semester sem);
  EnrollmentManager(const EnrollmentManager& other);
  EnrollmentManager& operator=(const EnrollmentManager& other);
  ~EnrollmentManager();

  bool registerStudent(int studentID, std::string firstName, std::string lastName);
  bool unregisterStudent(int studentID);

  bool addCourse(std::string courseID, int capacity);
  bool cancelCourse(std::string courseID);

  bool enroll(int studentID, std::string courseID);
  bool drop(int studentID, std::string courseID);

  std::string reportSummary() const;
  std::string report(int studentID) const;
  std::string report(std::string courseID) const;

  void printTree() const;

  int getYear() const;
  Semester getSemester() const;

private:
  //your design
  int year;
  Semester semester;

  StudentDatabase* sd;
  CourseManager* cm;
};

#endif
