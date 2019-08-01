#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include <vector>
#include <iterator>


int main(int argc, char* argv[]){
  if(argc != 2){
    std::cout << "Error" << std::endl;
  }else{
  	std::ifstream file;
  	file.open(argv[1], std::ios::in);

  	if (! file.is_open() ){
  		std::cout << "Failed to open file" << std::endl;
  	}
  	else{
  		std::string cell;

  		std::vector<std::string> row;

  		while(std::getline(file, cell, '\t')){
  			row.push_back(cell);
	  	}

	  	
	  	for (std::size_t i = 0; i < row.size(); i++){
	  		std::cout << row[i] << ",";
	  	}

	  	std::cout << std::endl;
	   	// std::cout << argv[1] << std::endl;
	}
	  return 0;
  }
}