#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include <vector>
#include <iterator>

#include <stdio.h>
#include <string.h>

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
  		std::string line;

  		while(std::getline(file, line, '\t')){
  			std::vector<std::string> row;

  			row.push_back(line);

  			for(auto v: row){
  				std::cout << v << ",";
  			}

  			std::cout << std::endl;
	  		}
	    // std::cout << argv[1] << std::endl;
	  	}
	  return 0;
	}
}