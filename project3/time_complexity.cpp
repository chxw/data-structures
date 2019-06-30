#include <chrono>
#include <iostream>

#include "?????.hpp"

int main(){
  int n = 1000000; //one million
  ?????* container = new ?????(n);

  while(true){
    int index = -1;
    std::cout << "index: ";
    std::cin >> index;

    if(!std::cin.fail() && (0 <= index && index < n)){

      std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
      int value = container->at(index);
      std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

      std::cout << "value: " << value << std::endl;
      std::cout << "elapsed time [nanosecond]: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << std::endl;
      std::cout << "---" << std::endl;
    }else{
      std::cout << "=== (Input must be between 0 and " << (n - 1) << ") ===" << std::endl;
      break;
    }
  }

  delete container;
  return 0;
}
