#include <iostream>

#include "Hash.hpp"
#include "Entries.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <chrono>

#include <sys/stat.h>
#include <typeinfo>

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;
using namespace std::chrono;

// check if file exists
inline bool exists (const std::string& name){
  struct stat buffer;
  return (stat (name.c_str(), &buffer) == 0);
}

int main(int argc, char* argv[]){
  // requires 2 arguments (i.e. ./database /path/to/input/file) && requires /path/to/input/file to exist
  if(argc != 2 or !exists(argv[1])){
    std::cout << "Error" << std::endl;
  }

  // open file (2nd arg)
  std::ifstream file;
  file.open(argv[1], std::ios::in);

  Hash h;

  std::string line;

  high_resolution_clock::time_point t1 = high_resolution_clock::now();

  // store (word, freq) in hash table
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

  high_resolution_clock::time_point t2 = high_resolution_clock::now();
  int duration = duration_cast<microseconds>(t2-t1).count();
  std::cout << "Duration: " << duration << " microseconds" << std::endl;

  // h.print();

  return 0;
}