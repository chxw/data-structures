#include "BTNode.hpp"

BTNode::BTNode(int data){
  this->data = data;
  this->left = nullptr;
  this->right = nullptr;
}

int BTNode::getData() const{
  return this->data;
}

BTNode* BTNode::getLeft() const{
  return this->left;
}

void BTNode::setLeft(BTNode* left){
  this->left = left;
}

BTNode* BTNode::getRight() const{
  return this->right;
}

void BTNode::setRight(BTNode* right){
  this->right = right;
}
