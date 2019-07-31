#include <iostream>
#include <math.h>

#include "Hash.hpp"

Hash::Hash(){
	num_words = 0;
	num_buckets = 5;

	table = new Entries*[num_buckets];

	for (int i = 0; i < num_buckets; i++){
		table[i] = nullptr;
	}
}

Hash::Hash(int buckets){
	num_words = 0;
	num_buckets = buckets;

	table = new Entries*[num_buckets];

	for (int i = 0; i < num_buckets; i++){
		table[i] = nullptr;
	}
}

// Hash::Hash(const Hash& other);
// Hash::Hash& operator=(const Hash& other);
// Hash::~Hash();

void Hash::put(std::string word, int freq){
	int index = hasher(word);

	// no overfill
	if (table[index] == nullptr){
		Entries* newbie = new Entries(word, freq);
		table[index] = newbie;
	}
	// overfill exists
	else{
		table[index]->add(word, freq);
	}
	
}

int Hash::get(std::string word){
	int index = hasher(word);

	if (table[index] == nullptr){
		throw std::runtime_error("Entry does not exist");
	}

	return table[index]->findFreq(word);
}

int Hash::getLoadFactor(){
	return num_words/num_buckets;
}

void Hash::remove(std::string word){
	int index = hasher(word);

	delete table[index];
	table[index] = nullptr;
}

int Hash::hasher(std::string word){
	int h = 0;
	int base = 33;

	for (std::string::size_type i = 0; i < word.size(); i++){
		h += (word.at(i) - '0')* pow(base, word.size()-i);
	}

	std::cout << word << " hash code: " << h%num_buckets << std::endl;

	return h % num_buckets;
}

void Hash::print(){
	for (int i = 0; i < num_buckets; i++){
		if (table[i] != nullptr){
			std::cout << i << ": " << table[i]->toString() << std::endl;
		}
		else{
			std::cout << i << ": nullptr " << std::endl;
		}
	}
}