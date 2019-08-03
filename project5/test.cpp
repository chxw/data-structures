#include <cassert>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "Hash.hpp"
#include "Entries.hpp"

#include <sys/stat.h>

void Hash_basics(){
	Hash h;

	h.put("chelsea", 1);
	h.put("tomoki", 2);
	h.put("matt", 3);
	h.put("test", 4);

	std::cout << "\n Hash basics testing ******" << std::endl;
	h.print();
	std::cout << "done with hash basics" << std::endl;
}

void Entries_basics(){
	Node* n = new Node();

	n->setWord("james earl carter");
	assert(n->getWord() == "james earl carter");
	n->setFreq(1);
	assert(n->getFreq() == 1);

	Node* n1 = new Node("alex turner", 2);

	assert(n1->getWord() == "alex turner");
	assert(n1->getFreq() == 2);

	n1->setNext(n);

	assert(n1->getNext()->getWord() == "james earl carter");
	assert(n1->getNext()->getFreq() == 1);

	n1->setNext(n1);
	assert(n1->getNext()->getWord() == "alex turner");
	assert(n1->getNext()->getFreq() == 2);

	n1->setNext(nullptr);

	assert(n->getNext() == nullptr);
	assert(n1->getNext() == nullptr);

	Entries* e = new Entries();
	e->add(n);
	e->add(n1);
	e->add("chelsea", 6);
	e->add("johnny", 3);

	assert(e->top()->getWord() == "james earl carter");

	if (e->top() == nullptr){
		std::cout << "e is empty" << std::endl;
	}
	else{
		assert(e->top()->getWord() == "james earl carter");
	}

	assert(e->top()->getWord() == n->getWord());
	assert(e->bottom()->getWord() == "johnny");

	assert(e->toString() == "james earl carter<->alex turner<->chelsea<->johnny");

	delete e;
}

void Integration_basics(){
	Hash h(5);

	std::cout << "\n Integration basics testing ******" << std::endl;

	h.put("chelsea", 1);
	h.put("tomoki", 2);
	h.put("matt", 3);
	h.put("test", 4);
	h.put("johnny", 5);
	h.put("britneysbackbetch", 6);
	h.put("dixiechicksandbeyonce", 7);

	assert(h.get("chelsea") == 1);
	assert(h.get("tomoki") == 2);
	assert(h.get("matt") == 3);
	assert(h.get("test") == 4);
	assert(h.get("johnny") == 5);
	assert(h.get("britneysbackbetch") == 6);
	assert(h.get("dixiechicksandbeyonce") == 7);

	std::cout << "\n add everything" << std::endl;
	h.print();

	assert(h.remove("chelsea") == true);
	assert(h.remove("tomoki") == true);
	assert(h.remove("matt") == true);
	assert(h.remove("test") == true);
	assert(h.remove("johnny") == true);
	assert(h.remove("britneysbackbetch") == true);
	assert(h.remove("dixiechicksandbeyonce") == true);

	std::cout << "\n remove everything" << std::endl;
	h.print();
}

void Resizing(){
	Hash h(3);

	h.put("chelsea", 1);
	h.put("tomoki", 2);
	std::cout << "2 words" << std::endl;
	h.print();
	h.put("matt", 3);
	h.put("test", 4);
	std::cout << "4 words" << std::endl;
	h.print();
	h.put("johnny", 5);
	h.put("britneysbackbetch", 6);
	std::cout << "6 words" << std::endl;
	h.print();
	h.put("dixiechicksandbeyonce", 7);
}

inline bool exists (const std::string& name){
  struct stat buffer;
  return (stat (name.c_str(), &buffer) == 0);
}

int main(int argc, char* argv[]){
	// Hash_basics();
	// Entries_basics();
	// Integration_basics();
	// Resizing();

	// requires 2 arguments (i.e. ./database /path/to/input/file) && requires /path/to/input/file to exist
	if(argc != 2 or !exists(argv[1])){
		std::cout << "Error" << std::endl;
	}

	// open file (2nd arg)
	std::ifstream file;
	file.open(argv[1], std::ios::in);

	Hash* h = new Hash();

	std::string line;
	// store (word, freq) in hash table
	while(std::getline(file, line)){
		std::stringstream ss(line);
		std::string cell;
		std::string row[2];

		int i = 0;
		while(getline(ss, cell, '\t')){
			row[i] = cell;
			i++;
		}
		
		std::string word = row[0];
	  	int freq = std::stoi(row[1]);

	  	h->put(word, freq);
	  	assert(h->get(word) == freq);
	}
	line = "";

	while(std::getline(file, line)){
		std::stringstream ss(line);
		std::string cell;
		std::string row[2];

		int i = 0;
		while(getline(ss, cell, '\t')){
			row[i] = cell;
			i++;
		}

		std::string word = row[0];
	  	assert(h->remove(word));
	}

	while(std::getline(file, line)){
		std::stringstream ss(line);
		std::string cell;
		std::string row[2];

		int i = 0;
		while(getline(ss, cell, '\t')){
			row[i] = cell;
			i++;
		}

		std::string word = row[0];
	  	assert(h->get(word) == -1);
	}


	return 0;
}
