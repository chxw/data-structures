#include "State.hpp"
#include "BTNode.hpp"

State::State(const BTNode* target){
  this->target = target;
  this->targetDone = false;
  this->leftDone = false;
  this->rightDone = false;
}

const BTNode* State::getTarget() const{
  return this->target;
}

bool State::isTargetDone() const{
  return this->targetDone;
}

void State::markTargetAsDone(){
  this->targetDone = true;
}

bool State::isLeftDone() const{
  return this->leftDone;
}

void State::markLeftAsDone(){
  this->leftDone = true;
}

bool State::isRightDone() const{
  return this->rightDone;
}

void State::markRightAsDone(){
  this->rightDone = true;
}
