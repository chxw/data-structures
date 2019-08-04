#include <iostream>
#include <math.h>
#include <stdexcept>

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

Hash::Hash(const Hash& other){
	num_words = other.num_words;
	num_buckets = other.num_buckets;
	threshold = other.threshold;

	table = new Entries*[num_buckets];

	for (int i = 0; i < num_buckets; i++){
		table[i] = nullptr;
	}

	// deep copy
	for (int i = 0; i < num_buckets; i++){
		if (other.table[i] != nullptr){
			Node* current = other.table[i]->top();
			// traverse through overfill entries
			while (current != nullptr){
				// add
				put(current->getWord(), current->getFreq());
				current = current->getNext();
			}
		}
	}
}

Hash& Hash::operator=(const Hash& other){
	if (&other != this){
		// free memory
		for (int i = 0; i < num_buckets; i++){
			if (table[i] != nullptr){
				delete table[i];
				table[i] = nullptr;
			}
		}
		delete[] table;
		table = nullptr;

		// get other's info
		num_words = other.num_words;
		num_buckets = other.num_buckets;
		threshold = other.threshold;

		table = new Entries*[num_buckets];

		for (int i = 0; i < num_buckets; i++){
			table[i] = nullptr;
		}

		// copy over
		num_words = other.num_words;
		num_buckets = other.num_buckets;
		threshold = other.threshold;

		table = new Entries*[num_buckets];

		// deep copy
		for (int i = 0; i < num_buckets; i++){
			if (other.table[i] != nullptr){
				Node* current = other.table[i]->top();
				// traverse through overfill entries
				while (current != nullptr){
					// add
					put(current->getWord(), current->getFreq());
					current = current->getNext();
				}
			}
		}
	}
	return (*this);
}

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

	// copy over everything from old to new
	for (int i = 0; i < old_size; i++){
		if (old[i] != nullptr){
			Node* current = old[i]->top();
			// traverse through overfill entries
			while (current != nullptr){
				// rehash
				put(current->getWord(), current->getFreq());
				current = current->getNext();
			}
		}
	}

	// free old
	for (int i = 0; i < old_size; i++){
		if (old[i] != nullptr){
			delete old[i];
			old[i] = nullptr;
		}
	}
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

	if (table[index] == nullptr){
		return false;
	}

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

std::string Hash::toString(){
	std::string s = "";

	for (int i = 0; i < num_buckets; i++){
		if (table[i] != nullptr){
			s += std::to_string(i);
			s += ": ";
			s += table[i]->toString();
		}
		else{
			s += std::to_string(i);
			s += ": nullptr";

		}
		s += "\n";
	}

	return s;
}
