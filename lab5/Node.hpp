#ifndef NODE_HPP
#define NODE_HPP

class Node{
public:
  //  Node();
  Node(char data);
  //  Node(const Node& other);
  //  Node& operator=(const Node& other);
  //  ~Node();

  char getData() const;
  Node* getNext() const;
  void setNext(Node* next);

private:
  char data;
  Node* next;
};

#endif
