#include <iostream>
#include <math.h>

#include "Hash.hpp"

Hash::Hash(){
	num_words = 0;
	num_buckets = 5;
	max = (int) (num_buckets * threshold);

	table = new Entries*[num_buckets];

	for (int i = 0; i < num_buckets; i++){
		table[i] = nullptr;
	}
}

Hash::Hash(int buckets){
	num_words = 0;
	num_buckets = buckets;
	max = (int) (num_buckets * threshold);

	table = new Entries*[num_buckets];

	for (int i = 0; i < num_buckets; i++){
		table[i] = nullptr;
	}
}

// Hash::Hash(const Hash& other);
// Hash::Hash& operator=(const Hash& other);
// Hash::~Hash();

void Hash::resize(){
	int old_size = num_buckets;
	num_buckets *= 2;
	max = (int) (num_buckets * threshold);

	// capture old
	Entries** old_table = table;

	//initialize new
	num_words = 0;
	table = new Entries*[num_buckets];
	for (int i = 0; i < num_buckets; i++){
		table[i] = nullptr;
	}

	// copy over everything
	for (int i = 0; i < old_size; i++){
		if (old_table[i] != nullptr){
			Node* to_delete;
			Node* current = old_table[i]->top();
			// traverse through overfill entries
			while (current != nullptr){
				// rehash
				put(current->getWord(), current->getFreq());
				to_delete = current;
				current = current->getNext();
				delete to_delete;
			}
		}
	}

	// dicsard old
	delete[] old_table;
}

void Hash::put(std::string word, int freq){
	if (num_words == max){
		resize();
	}
	if (get(word) != -1){
		// set get(word)->freq() to new freq
	}

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
		return -1;
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

int Hash::mod(int k, int n){
	return (k%n + n)%n;
}

int Hash::hasher(std::string word){
	int h = 0;
	int length = 0;
	int base = 33;

	for (std::string::size_type i = 0; i < word.size(); i++){
		length++;
	}

	for (int i = 0; i < length; i++){
		h += (word.at(i) - '0') * pow(base, length - (i+1));
	}

	return mod(h, num_buckets);
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