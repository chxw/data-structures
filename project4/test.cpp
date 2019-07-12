#include <cassert>
#include <string>
#include <climits>
#include <stdexcept>

#include <iostream>

#include "Student.hpp"
#include "StudentDatabase.hpp"
#include "Course.hpp"
// #include "CourseManager.hpp"
// #include "EnrollmentManager.hpp"

void student_test(){
  //default constructor
  Student* student = new Student();
  assert(student->toString() == "0 FIRST LAST");

  // parametrized constructor
  Student* student1 = new Student(6, "Chelsea", "Wang");
  assert(student1->toString() == "6 Chelsea Wang");

  // copy constructor
  Student* student2 = new Student(*student1);
  assert(student2->toString() == "6 Chelsea Wang");

  //assignment operator
  Student* student3 = new Student();
  *student3 = *student1;
  *student2 = *student;
  assert(student3->toString() == "6 Chelsea Wang");
  assert(student2->toString() == "0 FIRST LAST");

  delete student;
  delete student1;
  delete student2;
  delete student3;
}

void course_test(){
  //default constructor
  Course* course = new Course();
  assert(course->toString() == "COMP-000 (0/1)");

  //parametrized constructor
  //catch exceptions
  std::string message;
  try{
    Course* course_fail = new Course("COMP-20", 0);
  }
  catch(std::runtime_error& e){
    message = e.what();
  }
  assert(message == "Not Valid");

  std::string message1;
  try{
    Course* course_fail1 = new Course("", 1);
  }
  catch(std::runtime_error& e){
    message1 = e.what();
  }
  assert(message1 == "Not Valid");

  Course* course1 = new Course("COMP-15", 50);
  assert(course1->toString() == "COMP-15 (0/50)");
  assert(course1->getID() == "COMP-15");

  assert(course1->isFull() == false);
  assert(course1->getCapacity() == 50);

  for (int i = 0; i < 50; i++){
    course1->enroll(i);
  }

  assert(course1->isFull() == true);
  assert(course1->isHaving(0) == true);
  assert(course1->isHaving(50) == false);
  assert(course1->getNumberOfEnrolledStudents() == 50);
  assert(course1->getStudentIDAt(49) == 49);

  course1->drop(30);
  assert(course1->isFull() == false);
  assert(course1->getNumberOfEnrolledStudents() == 49);

  assert(course1->getStudentIDAt(30) == 31);

  course1->drop(0);
  assert(course1->getStudentIDAt(0) == 1);

  course1->drop(49);
  assert(course1->getNumberOfEnrolledStudents() == 47);

  //copy constructor
  Course* course2 = new Course(*course1);
  assert(course2->toString() == "COMP-15 (47/50)");

  //assignment operator
  *course1 = *course;
  assert(course1->toString() == "COMP-000 (0/1)");

  delete course;
  delete course1;
  delete course2;
}

void sdatabase_test(){
  StudentDatabase* studentDatabase = new StudentDatabase();

  Student* s1 = new Student(1, "John", "Smith");
  Student* s2 = new Student(2, "David", "Smith");
  Student* s3 = new Student(3, "Mary", "Smith");
  Student* s4 = new Student(4, "Mary", "J Blige");
  Student* s5 = new Student(5, "Mary", "Magdalene");
  Student* s6 = new Student(6, "Mary", "Joseph");

  studentDatabase->insert(s2);
  studentDatabase->insert(s1);
  studentDatabase->insert(s3);
  studentDatabase->insert(s4);
  studentDatabase->insert(s5);
  studentDatabase->insert(s6);


  std::string inOrder = studentDatabase->toStringInOrder();
  std::cout << inOrder << std::endl;

  const Student* ptr = studentDatabase->searchBy(s2->getID());
  assert(ptr->getID() == s2->getID());

  ptr = studentDatabase->searchBy(-100);
  assert(ptr == nullptr);

  // std::string result = studentDatabase->toTreeString();
  // std::string expected = "[[[](1 John Smith)[]](2 David Smith)[[](3 Mary Smith)[]]]";

  // assert(result == expected);

  delete studentDatabase;
}

int main(){
  student_test();
  course_test();
  sdatabase_test();
  return 0;
}
