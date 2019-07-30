#include <iostream>

#include "Hash.hpp"

Hash::Hash(){
	num_words = 0;
	num_buckets = 5;

	table = new Node*[num_buckets];

	for (int i = 0; i < num_buckets; i++){
		table[i] = nullptr;
	}
}

Hash::Hash(std::string word, int freq){
	num_words = 0;
	num_buckets = 5;

	table = new Node*[num_buckets];

	Node* newbie = new Node(word, freq);

	int index = hasher(word);

	table[index] = newbie;
}

// Hash::Hash(const Hash& other);
// Hash::Hash& operator=(const Hash& other);
// Hash::~Hash();

void Hash::put(std::string word, int freq){
	Node* newbie = new Node(word, freq);

	int index = hasher(word);
	
	table[index] = newbie;
}

int Hash::get(std::string word){
	int index = hasher(word);

	return table[index]->getFreq();
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
	int partition = 3;

	for (std::string::size_type i = 0; i < word.size(); i++){
		h += (word.at(i) - '0')*partition;
	}

	std::cout << word << " hash code: " << h%num_buckets << std::endl;

	return h % num_buckets;
}

void Hash::print(){
	for (int i = 0; i < num_buckets; i++){
		if (table[i] != nullptr){
			std::cout << i << ": " << table[i]->getWord() << " " << table[i]->getFreq() << std::endl;
		}
		else{
			std::cout << i << ": nullptr " << std::endl;
		}
	}
}