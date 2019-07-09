#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>

class Student{
public:
  Student();
  Student(int id, std::string firstName, std::string lastName);
  Student(const Student& other);
  Student& operator=(const Student& other);
  ~Student();

  int getID() const;
  std::string getFirstName() const;
  std::string getLastName() const;
  std::string toString() const;

private:
  //your design
};

#endif
