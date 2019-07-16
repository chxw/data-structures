#ifndef STUDENTDATABASE_HPP
#define STUDENTDATABASE_HPP

#include <string>
#include <iostream>
#include <stdexcept>

#include "BSTNode.hpp"
#include "Student.hpp"

class StudentDatabase{
public:
  StudentDatabase();
  // StudentDatabase(const StudentDatabase& other);
  StudentDatabase& operator=(const StudentDatabase& other);
  // ~StudentDatabase();

  const Student* searchBy(int studentID) const;
  bool insert(Student* student);
  bool deleteBy(int studentID);
  void balance();

  bool isEmpty() const;
  int getNumberOfStudents() const;
  std::string toStringInOrder() const;
  // std::string toTreeString() const;

private:
  BSTNode* root;
  int num_students;
  BSTNode** arr;

  BSTNode* find_parent(int studentID);
  void inOrderArray(BSTNode* current, BSTNode** arr);
  BSTNode* createBalancedTree(BSTNode** arr, int start, int end);
  BSTNode* min_node(BSTNode* current);
  bool place(BSTNode* current, BSTNode* newbie);
  BSTNode* delete_current(int key, BSTNode* current, BSTNode* previous);
  std::string inOrder(const BSTNode* current) const;
};

#endif
