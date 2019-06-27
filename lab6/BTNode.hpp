#ifndef BTNODE_HPP
#define BTNODE_HPP

class BTNode{
public:
  //  BTNode();
  BTNode(int data);
  //  BTNode(const BTNode& other);
  //  BTNode& operator=(const BTNode& other);
  //  ~BTNode();

  int getData() const;
  BTNode* getLeft() const;
  void setLeft(BTNode* left);
  BTNode* getRight() const;
  void setRight(BTNode* right);

private:
  int data;
  BTNode* left;
  BTNode* right;
};

#endif
