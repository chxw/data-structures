#ifndef MINHEAP_HPP
#define MINHEAP_HPP

class MinHeap{
public:
  MinHeap();
  //  MinHeap(const MinHeap& other);
  //  MinHeap& operator=(const MinHeap& other);
  ~MinHeap();

  void insert(int number);
  int extractMin();
  bool isEmpty() const;

private:
  //your design
};

#endif
