#include <cassert>
#include <string>

#include "Stack.hpp"

bool isBalanced(std::string parentheses){
  return false;
}

int main(){
  bool b1 = isBalanced("");
  assert(b1 == true);

  bool b2 = isBalanced("()");
  assert(b2 == true);

  bool b3 = isBalanced("(())");
  assert(b3 == true);

  bool b4 = isBalanced("((()))");
  assert(b4 == true);

  bool b5 = isBalanced("()()");
  assert(b5 == true);

  bool b6 = isBalanced("(()())");
  assert(b6 == true);

  bool b7 = isBalanced("(()()(()))");
  assert(b7 == true);

  bool b8 = isBalanced("(");
  assert(b8 == false);

  bool b9 = isBalanced(")");
  assert(b9 == false);

  bool b10 = isBalanced(")(");
  assert(b10 == false);

  bool b11 = isBalanced("()())");
  assert(b11 == false);

  bool b12 = isBalanced("()(()");
  assert(b12 == false);

  bool b13 = isBalanced("())(()");
  assert(b13 == false);

  bool b14 = isBalanced("(((((((((()))))))))");
  assert(b14 == false);

  bool b15 = isBalanced("()())()()()()()()()()()(()");
  assert(b15 == false);

  bool b16 = isBalanced("abc");
  assert(b16 == false);

  bool b17 = isBalanced("(a)");
  assert(b17 == false);

  return 0;
}
