#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include<vector>

int main(int argc, char* argv[]){
  if(argc != 2){
    std::cout << "Error" << std::endl;
  }else{
  	std::ifstream file;
  	if (! file.is_open()){
  		std::cout << "Failed to open file" << std::endl;
  	}
  	else{
  		// file.open(argv[1], std::ios::in);
  		std::string line;

  		while(std::getline(file, line)){
  			std::vector<string> row;
  			split(line, '\t', row);

  			std::string word = row.at(0);
  			int freq = row.at(1);

  			std::cout << "word is " << word << std::endl;
  			std::cout << "freq is " << freq << std::endl;
  		}
  	}
    std::cout << argv[1] << std::endl;
  }
  return 0;
}
