#ifndef COURSE_HPP
#define COURSE_HPP

#include <string>

class Course{
public:
  Course();
  Course(std::string id, int capacity);
  Course(const Course& other);
  Course& operator=(const Course& other);
  ~Course();

  bool isFull() const;
  bool enroll(int studentID);
  bool drop(int studentID);
  bool isHaving(int studentID);

  std::string getID() const;
  int getCapacity() const;
  int getNumberOfEnrolledStudents() const;
  int getStudentIDAt(int index) const;
  std::string toString() const;

private:
  //your design
};

#endif
