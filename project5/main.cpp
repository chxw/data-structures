#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main(int argc, char* argv[]){
  if(argc != 2){
    std::cout << "Error" << std::endl;
  }else{
    std::cout << argv[1] << std::endl;
  }
  return 0;
}
