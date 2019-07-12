#ifndef STUDENTDATABASE_HPP
#define STUDENTDATABASE_HPP

#include <string>

#include "BSTNode.hpp"
#include "Student.hpp"

class StudentDatabase{
public:
  StudentDatabase();
  // StudentDatabase(const StudentDatabase& other);
  StudentDatabase& operator=(const StudentDatabase& other);
  // ~StudentDatabase();

  // const Student* searchBy(int studentID) const;
  bool insert(Student* student);
  // bool deleteBy(int studentID);
  // void balance();

  bool isEmpty() const;
  int getNumberOfStudents() const;
  std::string toStringInOrder() const;
  // std::string toTreeString() const;

private:
  BSTNode* root;
  int num_students;
  void place(BSTNode* current, BSTNode* newbie);
  std::string inOrder(const BSTNode* current) const;
};

#endif
