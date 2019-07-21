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
  StudentDatabase(const StudentDatabase& other);
  StudentDatabase& operator=(const StudentDatabase& other);
  ~StudentDatabase();

  const Student* searchBy(int studentID) const;
  bool insert(Student* student);
  bool deleteBy(int studentID);
  void balance();

  bool isEmpty() const;
  int getNumberOfStudents() const;
  std::string toStringInOrder() const;
  std::string toTreeString() const;


private:
  BSTNode* root;
  BSTNode** arr;
  int num_students;

  void destruct(BSTNode* current);

  bool isBalanced();
  bool checkBalance(BSTNode* current);

  void printTree() const;
  void postOrder(const BSTNode* current, int indent) const;
  
  void printString(const BSTNode* current, std::string& s) const;

  BSTNode* find_parent(BSTNode* child) const;
  int find_height(const BSTNode* current) const;

  void inOrderArray(BSTNode* current);
  BSTNode* createBalancedTree(BSTNode** arr, int start, int end);

  BSTNode* min_node(BSTNode* current);
  void place(BSTNode* current, Student* student);
  BSTNode* delete_current(int key, BSTNode* current, BSTNode* previous);

  std::string inOrder(const BSTNode* current, std::string& order) const;
};

#endif
