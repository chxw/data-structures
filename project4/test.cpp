#include <cassert>
#include <string>

#include "Student.hpp"
#include "StudentDatabase.hpp"
#include "Course.hpp"
#include "CourseManager.hpp"
#include "EnrollmentManager.hpp"

void test1(){
  Student* student = new Student();
  assert(student->toString() == "0 FIRST LAST");
  delete student;
}

void test2(){
  StudentDatabase* studentDatabase = new StudentDatabase();

  Student* s1 = new Student(1, "John", "Smith");
  Student* s2 = new Student(2, "David", "Smith");
  Student* s3 = new Student(3, "Mary", "Smith");

  studentDatabase->insert(s2);
  studentDatabase->insert(s1);
  studentDatabase->insert(s3);

  std::string result = studentDatabase->toTreeString();
  std::string expected = "[[[](1 John Smith)[]](2 David Smith)[[](3 Mary Smith)[]]]";

  assert(result == expected);

  delete studentDatabase;
}

int main(){
  test1();
  test2();
  return 0;
}
