#include "hasher.hpp"

#include <iostream>
#include <string>

unsigned int generateHashCodeOf(const std::string& key){
	int h = 0;
	int partition = 64;

	for (std::string::size_type i = 0; i < key.size(); i++){
		h += (key.at(0) - '0')* partition;
	}

	return h % 16384;
}