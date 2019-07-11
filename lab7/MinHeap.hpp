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
  void toString() const;

private:
  //your design
  int get_parent(int node);
  int get_left(int node);
  int get_right(int node);
  void swap(int &a, int &b);
  void bubble_up(int start);
  void bubble_down(int start);
  
  int* array;
  int size;
  int capacity;
};

#endif
