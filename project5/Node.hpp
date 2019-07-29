#ifndef NODE_HPP
#define NODE_HPP

#include <string>

class Hash{
public:
	Node();
	Node(std::string word, int freq);
	Node(const Node& other);
	Node& operator=(const Node& other);
	~Node();

	std::string getWord() const;
	void setWord();
	int getFreq() const;
	void setFreq();

	Node* getNext() const;
	void setNext(Node* node);
	Node* getPrev() const;
	void setPrev(Node* node);

private:
	Node* next;
	Node* prev;

	std::string word;
	int freq;
};

#endif