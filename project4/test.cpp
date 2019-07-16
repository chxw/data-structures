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

  assert(student3->toString() == "6 Chelsea Wang");
  assert(student2->toString() == "0 FIRST LAST");
  
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

void small_sdatabase_test(){
  //default constructor
  StudentDatabase* studentDatabase = new StudentDatabase();

  //parametrized constructor
  Student* s1 = new Student(1, "John", "Smith");
  Student* s2 = new Student(2, "David", "Smith");
  Student* s3 = new Student(3, "Mary", "Smith");
  Student* s4 = new Student(4, "Mary", "J Blige");
  Student* s5 = new Student(5, "Mary", "Magdalene");
  Student* s6 = new Student(6, "Mary", "Joseph");

  //insert
  studentDatabase->insert(s2);
  studentDatabase->insert(s1);
  studentDatabase->insert(s3);
  studentDatabase->insert(s4);
  studentDatabase->insert(s5);
  studentDatabase->insert(s6);

  //inOrder traversal
  std::string inOrder = studentDatabase->toStringInOrder();
  std::cout << inOrder << std::endl;

  //searchBy
  const Student* ptr = studentDatabase->searchBy(s1->getID());
  assert(ptr->getID() == s1->getID());
  ptr = studentDatabase->searchBy(s2->getID());
  assert(ptr->getID() == s2->getID());
  ptr = studentDatabase->searchBy(s3->getID());
  assert(ptr->getID() == s3->getID());
  ptr = studentDatabase->searchBy(s4->getID());
  assert(ptr->getID() == s4->getID());
  ptr = studentDatabase->searchBy(s5->getID());
  assert(ptr->getID() == s5->getID());
  ptr = studentDatabase->searchBy(s6->getID());
  assert(ptr->getID() == s6->getID());
  assert(studentDatabase->searchBy(0) == nullptr);

  //deleteBy test1
  studentDatabase->deleteBy(s1->getID());
  std::cout << studentDatabase->toStringInOrder() << std::endl;
  assert(studentDatabase->deleteBy(s2->getID()) == true);
  std::cout << studentDatabase->toStringInOrder() << std::endl;
  assert(studentDatabase->deleteBy(s3->getID()) == true);
  std::cout << studentDatabase->toStringInOrder() << std::endl;
  assert(studentDatabase->deleteBy(s4->getID()) == true);
  std::cout << studentDatabase->toStringInOrder() << std::endl;
  assert(studentDatabase->deleteBy(s5->getID()) == true);
  std::cout << studentDatabase->toStringInOrder() << std::endl;
  assert(studentDatabase->deleteBy(s6->getID()) == true);
  std::cout << studentDatabase->toStringInOrder() << std::endl;

  // std::string result = studentDatabase->toTreeString();
  // std::string expected = "[[[](1 John Smith)[]](2 David Smith)[[](3 Mary Smith)[]]]";

  // assert(result == expected);

  delete studentDatabase;
}

void large_sdatabase_test(){
  //default constructor
  StudentDatabase* studentDatabase = new StudentDatabase();

  //parametrized constructor
  Student* s1 = new Student(1, "John", "Smith");
  Student* s2 = new Student(2, "David", "Smith");
  Student* s3 = new Student(3, "Mary", "Smith");
  Student* s4 = new Student(4, "Mary", "J Blige");
  Student* s5 = new Student(5, "Mary", "Magdalene");
  Student* s6 = new Student(6, "Mary", "Joseph");
  Student* s7 = new Student(7, "Johnny", "Depp");
  Student* s8 = new Student(8, "Johnny", "Cash");
  Student* s9 = new Student(9, "June", "Carter");
  Student* s10 = new Student(10, "Lil", "Nas X");  

  //insert
  studentDatabase->insert(s5);
  studentDatabase->insert(s2);
  studentDatabase->insert(s1);
  studentDatabase->insert(s3);
  studentDatabase->insert(s10);
  studentDatabase->insert(s4);
  studentDatabase->insert(s6);
  studentDatabase->insert(s8);
  studentDatabase->insert(s7);
  studentDatabase->insert(s9);

  //inOrder traversal
  std::string inOrder = studentDatabase->toStringInOrder();
  std::cout << inOrder << std::endl;

  //deleteBy test1
  assert(studentDatabase->deleteBy(s10->getID()) == true);
  std::cout << studentDatabase->toStringInOrder() << std::endl;
  assert(studentDatabase->deleteBy(s2->getID()) == true);
  std::cout << studentDatabase->toStringInOrder() << std::endl;
  assert(studentDatabase->deleteBy(s3->getID()) == true);
  std::cout << studentDatabase->toStringInOrder() << std::endl;
  assert(studentDatabase->deleteBy(s9->getID()) == true);
  std::cout << studentDatabase->toStringInOrder() << std::endl;
  assert(studentDatabase->deleteBy(s5->getID()) == true);
  std::cout << studentDatabase->toStringInOrder() << std::endl;
  assert(studentDatabase->deleteBy(s6->getID()) == true);
  std::cout << studentDatabase->toStringInOrder() << std::endl;
  assert(studentDatabase->deleteBy(s4->getID()) == true);
  std::cout << studentDatabase->toStringInOrder() << std::endl;
  assert(studentDatabase->deleteBy(s1->getID()) == true);
  std::cout << studentDatabase->toStringInOrder() << std::endl;
  assert(studentDatabase->deleteBy(s8->getID()) == true);
  std::cout << studentDatabase->toStringInOrder() << std::endl;
  assert(studentDatabase->deleteBy(s7->getID()) == true);
  std::cout << studentDatabase->toStringInOrder() << std::endl;

  // std::string result = studentDatabase->toTreeString();
  // std::string expected = "[[[](1 John Smith)[]](2 David Smith)[[](3 Mary Smith)[]]]";

  // assert(result == expected);

  delete studentDatabase;
}

int main(){
  // student_test();
  // course_test();
  small_sdatabase_test();
  large_sdatabase_test();
  return 0;
}
