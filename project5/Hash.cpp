#include <iostream>
#include <math.h>

#include "Hash.hpp"

Hash::Hash(){
	num_words = 0;
	num_buckets = 199;
	threshold = 0.75f;

	table = new Entries*[num_buckets];

	for (int i = 0; i < num_buckets; i++){
		table[i] = nullptr;
	}
}

Hash::Hash(int buckets){
	num_words = 0;
	num_buckets = buckets;
	threshold = 0.75f;

	table = new Entries*[num_buckets];

	for (int i = 0; i < num_buckets; i++){
		table[i] = nullptr;
	}
}

// Hash::Hash(const Hash& other);
// Hash::Hash& operator=(const Hash& other);
Hash::~Hash(){
	for (int i = 0; i < num_buckets; i++){
		if (table[i] != nullptr){
			delete table[i];
			table[i] = nullptr;
		}
	}
	delete[] table;
	table = nullptr;
}

void Hash::resize(){
	// capture old
	int old_size = num_buckets;
	Entries** old = table;

	// initialize new table
	num_buckets = nextPrime(2*num_buckets);
	num_words = 0;
	table = new Entries*[num_buckets];
	for (int i = 0; i < num_buckets; i++){
		table[i] = nullptr;
	}

	// copy over everything from old to new & delete along the way
	for (int i = 0; i < old_size; i++){
		if (old[i] != nullptr){
			Node* to_delete;
			Node* current = old[i]->top();
			// traverse through overfill entries
			while (current != nullptr){
				// rehash
				put(current->getWord(), current->getFreq());
				to_delete = current;
				current = current->getNext();
				delete to_delete;
				to_delete = nullptr;
			}
		}
	}
	
	// discard old
	delete[] old;
	old = nullptr;
}

bool Hash::isPrime(int number){
	for (int i = 2; i <= number / 2; ++i){
		if (number % i == 0){
			return false;
		}
	}
	return true;
}

int Hash::nextPrime(int number){
	while (!isPrime(++number)){

	}
	return number;
}

void Hash::put(std::string word, int freq){
	if (getLoadFactor() > threshold){
		resize();
	}

	// update freq if word already exists in table
	if (setNewFreq(word, freq)){
		return;
	}

	unsigned int index = hasher(word);

	// empty
	if (table[index] == nullptr){
		Entries* newbie = new Entries(word, freq);
		table[index] = newbie;
	}
	// not empty
	else{
		table[index]->add(word, freq);
	}
	num_words++;
}

// if this returns -1, means not found
int Hash::get(std::string word){
	unsigned int index = hasher(word);

	if (table[index] == nullptr){
		return -1;
	}

	return table[index]->findFreq(word);
}

// update freq of word
bool Hash::setNewFreq(std::string word, int newFreq){
	unsigned int index = hasher(word);

	if (table[index] == nullptr){
		return false;
	}
	else if (table[index]->findFreq(word) == -1){
		return false;
	}

	table[index]->updateFreq(word, newFreq);
	return true;
}

float Hash::getLoadFactor(){
	return num_words/num_buckets;
}

// use Entries->remove() to take out entry
bool Hash::remove(std::string word){
	unsigned int index = hasher(word);
	if(table[index]->remove(word)){
		num_words--;
		return true;
	}
	return false;
}

// hashing function
unsigned int Hash::hasher(std::string word){
	unsigned int h = 0;
	unsigned int base = 33;

	for (std::string::size_type i = 0; i < word.size(); i++){
		h += (word.at(i) - '0') * pow(base, word.size() - (i+1));
	}

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
