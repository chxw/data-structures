#include <cassert>
#include <string>

#include "Student.hpp"
// #include "StudentDatabase.hpp"
// #include "Course.hpp"
// #include "CourseManager.hpp"
// #include "EnrollmentManager.hpp"

void student_test(){
  Student* student = new Student();
  assert(student->toString() == "0 FIRST LAST");

  Student* student1 = new Student(6, "Chelsea", "Wang");
  assert(student1->toString() == "6 Chelsea Wang");

  Student* student2 = new Student(*student1);
  assert(student2->toString() == "6 Chelsea Wang");

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

// void test2(){
//   StudentDatabase* studentDatabase = new StudentDatabase();

//   Student* s1 = new Student(1, "John", "Smith");
//   Student* s2 = new Student(2, "David", "Smith");
//   Student* s3 = new Student(3, "Mary", "Smith");

//   studentDatabase->insert(s2);
//   studentDatabase->insert(s1);
//   studentDatabase->insert(s3);

//   std::string result = studentDatabase->toTreeString();
//   std::string expected = "[[[](1 John Smith)[]](2 David Smith)[[](3 Mary Smith)[]]]";

//   assert(result == expected);

//   delete studentDatabase;
// }

int main(){
  student_test();

  // test2();
  return 0;
}
