#include <cassert>
#include <string>
#include <iostream>

#include "BTNode.hpp"
#include "State.hpp"
#include "Stack.hpp"

std::string preOrder(const BTNode* current){
  if (current == nullptr){
    return "";
  }

  std::string order;

  order += std::to_string(current->getData());
  order += preOrder(current->getLeft());
  order += preOrder(current->getRight());

  return order;
}

std::string inOrder(const BTNode* current){
  if (current == nullptr){
    return "";
  }

  std::string order;

  order += inOrder(current->getLeft());
  order += std::to_string(current->getData());
  order += inOrder(current->getRight());

  return order;
}

std::string postOrder(const BTNode* current){
  if (current == nullptr){
    return "";
  }

  std::string order;

  order += postOrder(current->getLeft());
  order += postOrder(current->getRight());
  order += std::to_string(current->getData());

  return order;
}

std::string preOrderByLoop(const BTNode* root){
  if (root == nullptr){
    return "";
  }

  State* c = new State(root);
  Stack stack;
  std::string result = "";

  stack.push(c);

  while(!stack.isEmpty()){
    if (!stack.top()->isTargetDone()){
      result += std::to_string(stack.top()->getTarget()->getData());
      stack.top()->markTargetAsDone();
    }
    else if (!stack.top()->isLeftDone()){
      if (stack.top()->getTarget()->getLeft() == nullptr){
        stack.top()->markLeftAsDone();
      }
      else{
        State* l = new State(stack.top()->getTarget()->getLeft());
        stack.top()->markLeftAsDone();
        stack.push(l);
        continue;
      }
    }
    else if (!stack.top()->isRightDone()){
      if (stack.top()->getTarget()->getRight() == nullptr){
        stack.top()->markRightAsDone();
      }
      else{
        State* r = new State(stack.top()->getTarget()->getRight());
        stack.top()->markRightAsDone();
        stack.push(r);
        continue;
      }
    }
    else if (stack.top()->isTargetDone() and stack.top()->isLeftDone() and stack.top()->isRightDone()){
      stack.pop();
    }
  }
  return result;
}

std::string inOrderByLoop(const BTNode* root){
  if (root == nullptr){
    return "";
  }

  State* c = new State(root);
  Stack stack;
  std::string result = "";

  stack.push(c);

  while(!stack.isEmpty()){
    if (!stack.top()->isLeftDone()){
      if (stack.top()->getTarget()->getLeft() == nullptr){
        stack.top()->markLeftAsDone();
      }
      else{
        State* l = new State(stack.top()->getTarget()->getLeft());
        stack.top()->markLeftAsDone();
        stack.push(l);
        continue;
      }
    }
    else if (!stack.top()->isTargetDone()){
      result += std::to_string(stack.top()->getTarget()->getData());
      stack.top()->markTargetAsDone();
    }
    else if (!stack.top()->isRightDone()){
      if (stack.top()->getTarget()->getRight() == nullptr){
        stack.top()->markRightAsDone();
      }
      else{
        State* r = new State(stack.top()->getTarget()->getRight());
        stack.top()->markRightAsDone();
        stack.push(r);
        continue;
      }
    }
    else if (stack.top()->isTargetDone() and stack.top()->isLeftDone() and stack.top()->isRightDone()){
      stack.pop();
    }
  }
  return result;
}

std::string postOrderByLoop(const BTNode* root){
  if (root == nullptr){
    return "";
  }

  State* c = new State(root);
  Stack stack;
  std::string result = "";

  stack.push(c);

  while(!stack.isEmpty()){
    if (!stack.top()->isLeftDone()){
      if (stack.top()->getTarget()->getLeft() == nullptr){
        stack.top()->markLeftAsDone();
      }
      else{
        State* l = new State(stack.top()->getTarget()->getLeft());
        stack.top()->markLeftAsDone();
        stack.push(l);
        continue;
      }
    }
    else if (!stack.top()->isRightDone()){
      if (stack.top()->getTarget()->getRight() == nullptr){
        stack.top()->markRightAsDone();
      }
      else{
        State* r = new State(stack.top()->getTarget()->getRight());
        stack.top()->markRightAsDone();
        stack.push(r);
        continue;
      }
    }
    else if (!stack.top()->isTargetDone()){
      result += std::to_string(stack.top()->getTarget()->getData());
      stack.top()->markTargetAsDone();
    }
    else if (stack.top()->isTargetDone() and stack.top()->isLeftDone() and stack.top()->isRightDone()){
      stack.pop();
    }
  }
  return result;
}


void test(const BTNode* root, std::string expected4PreOrder, std::string expected4InOrder, std::string expected4PostOrder){
  assert(preOrder(root) == expected4PreOrder);
  assert(inOrder(root) == expected4InOrder);
  assert(postOrder(root) == expected4PostOrder);

  assert(preOrderByLoop(root) == expected4PreOrder);
  assert(inOrderByLoop(root) == expected4InOrder);
  // assert(postOrderByLoop(root) == expected4PostOrder);
}

int main(){
  BTNode* zero = new BTNode(0);
  BTNode* one = new BTNode(1);
  BTNode* two = new BTNode(2);
  BTNode* three = new BTNode(3);
  BTNode* four = new BTNode(4);
  BTNode* five = new BTNode(5);
  BTNode* six = new BTNode(6);
  BTNode* seven = new BTNode(7);
  BTNode* eight = new BTNode(8);
  BTNode* nine = new BTNode(9);

  test(nullptr, "", "", "");
  test(zero, "0", "0", "0");

  one->setLeft(zero);
  test(one, "10", "01", "01");

  two->setLeft(one);
  test(two, "210", "012", "012");

  two->setRight(four);
  test(two, "2104", "0124", "0142");

  four->setLeft(three);
  test(two, "21043", "01234", "01342");

  four->setRight(five);
  test(two, "210435", "012345", "013542");

  six->setLeft(two);
  test(six, "6210435", "0123456", "0135426");

  six->setRight(seven);
  test(six, "62104357", "01234567", "01354276");

  seven->setRight(nine);
  test(six, "621043579", "012345679", "013542976");

  nine->setLeft(eight);
  test(six, "6210435798", "0123456789", "0135428976");

  delete zero;
  delete one;
  delete two;
  delete three;
  delete four;
  delete five;
  delete six;
  delete seven;
  delete eight;
  delete nine;

  return 0;
}
