#include "Hash.hpp"
#include "Entries.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <chrono>

#include <sys/stat.h>

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
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
  // requires 2 arguments (i.e. ./database /path/to/input/file) && requires /path/to/input/file to exist
  if(argc != 2 or !exists(argv[1])){
    std::cout << "Error" << std::endl;
  }

  // open file (2nd arg)
  std::ifstream file;
  file.open(argv[1], std::ios::in);

  Hash h;

  std::string line;

  high_resolution_clock::time_point put1 = high_resolution_clock::now();

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
  high_resolution_clock::time_point put2 = high_resolution_clock::now();

  line = "";

  high_resolution_clock::time_point get1 = high_resolution_clock::now();
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

	  h.get(word);
  }
  high_resolution_clock::time_point get2 = high_resolution_clock::now();

  high_resolution_clock::time_point remove1 = high_resolution_clock::now();
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

	  h.remove(word);
  }
  high_resolution_clock::time_point remove2 = high_resolution_clock::now();
  high_resolution_clock::time_point t2 = high_resolution_clock::now();

  int put_duration = duration_cast<microseconds>(put2-put1).count();
  int get_duration = duration_cast<microseconds>(get2-get1).count();
  int remove_duration = duration_cast<microseconds>(remove2-remove1).count();
  int total_duration = duration_cast<microseconds>(t2-t1).count();
  std::cout << "Put duration: " << put_duration << " microseconds" << std::endl;
  std::cout << "Get duration: " << get_duration << " microseconds" << std::endl;
  std::cout << "Remove duration: " << remove_duration << " microseconds" << std::endl;
  std::cout << "Total duration: " << total_duration << " microseconds" << std::endl;

  return 0;
}