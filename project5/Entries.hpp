#ifndef ENTRIES_HPP
#define ENTRIES_HPP

#include <string>
#include "Node.hpp"

class Entries{
public:
  Entries();
  Entries(std::string word, int freq);
  // Entries(const Entries& other);
  // Entries& operator=(const Entries& other);
  // ~Entries();

  bool add(std::string w, int f);
  bool add(Node* newbie);
  int findFreq(std::string word);
  void updateFreq(std::string word, int newFreq);
  bool remove(std::string w);

  Node* top();
  Node* bottom();

  std::string toString() const;

private:
  int num_entries;

  Node* head;
  Node* tail;
};

#endif