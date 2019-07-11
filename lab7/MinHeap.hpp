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
  void swap(int &a, int &b);
  void bubble_up(int start);
  void bubble_down(int start);
  int find_min(int a, int b, int c);

  int* array;
  int size;
  int capacity;
};

#endif
