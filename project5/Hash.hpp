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
	// ~Hash();

	void put(std::string word, int freq);
	int get(std::string word);
	void remove(std::string word);

	int getLoadFactor();

	void print();

private:
	Entries** table;

	bool setNewFreq(std::string word, int newFreq);
	int mod(int k, int n);
	int hasher(std::string word);
	void resize();

	int num_words;
	int num_buckets;
	float threshold;
	int max;
};

#endif