#include "Hash.hpp"

#include <iostream>

Hash::Hash(){
	num_words = 0;
	num_buckets = 5;
	table = new int[num_buckets];
	load_factor = num_words/num_buckets;

	for (int i = 0; i < num_buckets; i++){
		table[i] = -1;
	}
}

Hash::Hash(std::string word, int freq){
	num_words = 0;
	num_buckets = 5;
	table = new int[num_buckets];
	load_factor = num_words/num_buckets;

	for (int i = 0; i < num_buckets; i++){
		table[i] = -1;
	}

	int index = hasher(word);

	//table[index] = tuple(word, freq)
	table[index] = freq;
}

// Hash::Hash(const Hash& other);
// Hash::Hash& operator=(const Hash& other);
// Hash::~Hash();

void Hash::put(std::string word, int freq){
	int index = hasher(word);

	//table[index] = tuple(word, freq)
	table[index] = freq;
}

int Hash::get(std::string word){
	int index = hasher(word);

	// return table[index]->getFrequency()
	return table[index];
}

void Hash::remove(std::string word){
	int index = hasher(word);

	// return table[index]->getFrequency()
	table[index] = -1;
}

int Hash::hasher(std::string word){
	int h = 0;
	int partition = 3;

	for (std::string::size_type i = 0; i < word.size(); i++){
		h += (word.at(i) - '0')*partition;
	}

	std::cout << word << " hash code: " << h%num_buckets << std::endl;

	return h % num_buckets;
}

void Hash::print(){
	for (int i = 0; i < num_buckets; i++){
		std::cout << table[i] << " ";
	}
}