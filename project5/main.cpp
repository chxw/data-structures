#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include <vector>

#include <typeinfo>

#include "Hash.hpp"

int main(int argc, char* argv[]){
  if(argc != 2){
    std::cout << "Error" << std::endl;
  }else{
  	std::ifstream file;
  	file.open(argv[1], std::ios::in);

  	Hash h(100000);

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
