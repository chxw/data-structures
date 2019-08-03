#ifndef HASH_HPP
#define HASH_HPP

#include <string>

#include "Entries.hpp"

class Hash{
public:
	Hash();
	Hash(int buckets);
	// Hash(const Hash& other);
	// Hash& operator=(const Hash& other);
	~Hash();

	void put(std::string word, int freq);
	int get(std::string word);
	bool remove(std::string word);

	float getLoadFactor();

	void print();

private:
	Entries** table;

	bool setNewFreq(std::string word, int newFreq);

	unsigned int hasher(std::string word);
	
	void resize();
	bool isPrime(int number);
	int nextPrime(int number);

	int num_words;
	int num_buckets;
	float threshold;
};

#endif
