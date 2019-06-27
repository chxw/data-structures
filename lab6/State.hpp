#ifndef STATE_HPP
#define STATE_HPP

#include "BTNode.hpp"

class State{
public:
  //  State();
  State(const BTNode* target);
  //  State(const State& other);
  //  State& operator=(const State& other);
  //  ~State();

  const BTNode* getTarget() const;
  bool isTargetDone() const;
  void markTargetAsDone();
  bool isLeftDone() const;
  void markLeftAsDone();
  bool isRightDone() const;
  void markRightAsDone();

private:
  const BTNode* target;
  bool targetDone;
  bool leftDone;
  bool rightDone;
};

#endif
