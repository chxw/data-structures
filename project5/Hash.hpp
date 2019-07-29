#ifndef HASH_HPP
#define HASH_HPP

#include <string>

class Hash{
public:
	Hash();
	Hash(std::string word, int freq);
	// Hash(const Hash& other);
	// Hash& operator=(const Hash& other);
	// ~Hash();

	void put(std::string word, int freq);
	int get(std::string word);
	void remove(std::string word);

	void print();

private:
	int* table;

	int hasher(std::string word);

	int num_words;
	int num_buckets;
	int load_factor;
};

#endif