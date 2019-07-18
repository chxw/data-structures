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
  std::string toTreeString() const;

  void printTree() const;

private:
  BSTNode* root;
  int num_students;

  bool isBalanced();
  bool checkBalance(BSTNode* current);

  void postOrder(const BSTNode* current, int indent) const;
  void printString(const BSTNode* current, std::string& s) const;

  BSTNode* find_parent(BSTNode* child) const;
  int find_depth(const BSTNode* node) const;

  void inOrderArray(BSTNode* current, BSTNode** arr);
  BSTNode* createBalancedTree(BSTNode** arr, int start, int end);

  BSTNode* min_node(BSTNode* current);
  bool place(BSTNode* current, BSTNode* newbie);
  BSTNode* delete_current(int key, BSTNode* current, BSTNode* previous);

  std::string inOrder(const BSTNode* current) const;
};

#endif
