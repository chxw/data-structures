#include "hasher.hpp"

#include <iostream>
#include <string>
#include <math.h> 

unsigned int generateHashCodeOf(const std::string& key){
	unsigned int h = 0;
	unsigned int length = 0;
	unsigned int base = 33;
	unsigned int num_buckets = 16384;

	for (std::string::size_type i = 0; i < key.size(); i++){
		length++;
	}

	for (int i = 0; i < length; i++){
		unsigned int x = key.at(i) - '0';
		unsigned int a = pow(base, length - (i+1));
		h += x*a;
	}

	return h%num_buckets;
}
