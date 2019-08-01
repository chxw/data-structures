#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main(int argc, char* argv[]){
  if(argc != 2){
    std::cout << "Error" << std::endl;
  }else{
  	std::ifstream file;
  	if (! file.is_open()){
  		std::cout << "Failed to open file" << std::endl;
  	}
  	else{
  		file.open(argv[1], std::ios::in);
  	}
    std::cout << argv[1] << std::endl;
  }
  return 0;
}
