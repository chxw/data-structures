#ifndef BSTNODE_HPP
#define BSTNODE_HPP

#include "Student.hpp"

class BSTNode{
public:
  BSTNode();
  BSTNode(Student* sdata);
  BSTNode(const BSTNode& other);
  BSTNode& operator=(const BSTNode& other);
  ~BSTNode();

  Student* getData() const;
  BSTNode* getLeft() const;
  void setLeft(BSTNode* left);
  BSTNode* getRight() const;
  void setRight(BSTNode* right);

private:
  Student* data;
  BSTNode* left;
  BSTNode* right;
};

#endif
