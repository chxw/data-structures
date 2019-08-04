#ifndef NODE_HPP
#define NODE_HPP

#include <string>

class Node{
public:
	Node();
	Node(std::string given_word, int given_freq);
	Node(const Node& other);
	Node& operator=(const Node& other);
	~Node();

	std::string getWord() const;
	void setWord(std::string w);
	int getFreq() const;
	void setFreq(int f);

	Node* getNext() const;
	void setNext(Node* node);
	Node* getPrev() const;
	void setPrev(Node* node);

private:
	std::string word;
	int freq;

	Node* next;
	Node* prev;
};

#endif