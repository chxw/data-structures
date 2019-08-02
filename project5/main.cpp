#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include <vector>
#include <sys/stat.h>
#include <typeinfo>

#include "Hash.hpp"

inline bool exists (const std::string& name){
  struct stat buffer;
  return (stat (name.c_str(), &buffer) == 0);
}

int main(int argc, char* argv[]){
  // requires 2 arguments (i.e. ./database /path/to/input/file) && requires /path/to/input/file to exist
  if(argc != 2 or !exists(argv[1])){
    std::cout << "Error" << std::endl;
  }
  // 2 args given
  else {
    // open file (2nd arg)
    std::ifstream file;
  	file.open(argv[1], std::ios::in);

  	Hash h(1000000);

  	if (! file.is_open() ){
  		std::cout << "Failed to open file" << std::endl;
  	}
  	else{
  		std::string line;

  		while(std::getline(file, line)){
  			std::stringstream ss(line);
  			std::string cell;
  			std::vector<std::string> row;

  			while(getline(ss, cell, '\t')){
  				row.push_back(cell);
  			}
	  		
	  		std::string word = row[0];
		  	int freq = std::stoi(row[1]);

		  	h.put(word, freq);
	  	}

	  	// std::cout << std::endl;

	   	// std::cout << argv[1] << std::endl;
	}

	h.print();
	return 0;
  }
}
