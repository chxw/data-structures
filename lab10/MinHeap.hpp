#ifndef MINHEAP_HPP
#define MINHEAP_HPP

#include <vector>

#include "Vertex.hpp"

class MinHeap{
public:
  MinHeap();
  MinHeap(const std::vector<Vertex*>& vertices);
  MinHeap(const MinHeap& other);
  MinHeap& operator=(const MinHeap& other);
  ~MinHeap();

  void insert(Vertex* vertex);
  Vertex* findMin() const;
  Vertex* extractMin();
  bool isEmpty() const;
  void rebuild();

private:
  Vertex** array;
  int capacity;
  int size;

  void minHeapify(int index);
};

#endif
