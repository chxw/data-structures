#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include <sys/stat.h>

#include "Hash.hpp"

// check if file exists
inline bool exists (const std::string& name){
  struct stat buffer;
  return (stat (name.c_str(), &buffer) == 0);
}

int main(int argc, char* argv[]){
  // requires 2 arguments (i.e. ./database /path/to/input/file) && requires /path/to/input/file to exist
  if(argc != 2 or !exists(argv[1])){
    std::cout << "Error" << std::endl;
    return 0;
  }

  // open file (2nd arg)
  std::ifstream file;
	file.open(argv[1], std::ios::in);

	Hash h;

	std::string line;

  // store (word, freq) in hash table
	while(std::getline(file, line)){
		std::stringstream ss(line);
		std::string cell;
    std::string row[2];
    int i = 0;

		while(getline(ss, cell, '\t')){
      row[i] = cell;
      i++;
		}
		
		std::string word = row[0];
  	int freq = std::stoi(row[1]);

  	h.put(word, freq);
	}
  std::cout << "done inserting" << std::endl;  


  // prompt user until done
  bool done = false;
  do {
    std::string line;
    std::getline(std::cin, line);

    if (line == ""){
      std::cout << "Unknown command" << std::endl;
      continue;
    }

    std::stringstream ss(line);
    std::string arg;
    std::string row[3];
    // capture number of arguments input
    int i = 0;

    while(getline(ss, arg, ' ')){
      row[i] = arg;
      i++;
    }

    std::string command = row[0];

    if (command == ":q" and i == 1){
      done = true;
    } 
    else if(command == ":p" and i == 3 and row[2].find_first_not_of("0123456789") == std::string::npos){
      std::string word = row[1];
      int freq = std::stoi(row[2]);
      if (freq < 0){
        std::cout << "Invalid" << std::endl;
      }
      else {
        h.put(word, freq);
        std::cout << "Added" << std::endl;
        // h.print();
      }

    } 
    else if (command == ":g" and i == 2){
      std::string word = row[1];
      int freq = h.get(word);

      if (freq == -1){
        std::cout << "Not found" << std::endl;
      }
      else{
        std::cout << word << " " << freq << std::endl;
      }

    } 
    else if (command == ":r" and i == 2){
      std::string word = row[1];
      int freq = h.get(word);

      if (freq == -1){
        std::cout << "Not found" << std::endl;
      }
      else if (h.remove(word)){
        std::cout << "Deleted" << std::endl;
        // h.print();
      }

    } 
    else{
      std::cout << "Unknown command" << std::endl;
    }
  } while (!done);

  h.print();
  return 0;
}
