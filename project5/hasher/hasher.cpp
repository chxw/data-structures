#include "hasher.hpp"

#include <iostream>
#include <string>
#include <math.h> 

unsigned int generateHashCodeOf(const std::string& key){
	int h = 0;
	int length = 0;
	int base = 33;
	int num_buckets = 16384;

	for (std::string::size_type i = 0; i < key.size(); i++){
		length++;
	}

	for (int i = 0; i < length; i++){
		h += (key.at(i) - '0') * pow(base, length - (i+1));
	}

	return (h%num_buckets + num_buckets)%num_buckets;
}
