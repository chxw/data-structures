#ifndef SORTER_HPP
#define SORTER_HPP

enum class Mode{
  INSERTION_SORT,
  MERGE_SORT,
  QUICK_SORT
};

class Sorter{
public:
  Sorter();
  Sorter(Mode mode);
  Sorter(const Sorter& other);
  Sorter& operator=(const Sorter& other);
  ~Sorter();

  void sort(int* const array, int size) const;
  void sort(int* const array, int size, Mode mode) const;

  void set(Mode mode);
  Mode getMode() const;

private:
  //your design
  Mode mode;

  void insertion_sort(int* const array, int size) const;
  void quick_sort(int* const array, int low, int high) const;
  int pivot(int* const array, int low, int high, int p) const;
  int find_pivot(int* const array, int l, int h) const;
  int median(int a, int b, int c) const;
  void traverse(int* const array, int key) const;
  void swap(int &a, int &b) const;
  void print_array(int* const array, int size) const;
  void divide(int* const array, int front, int end) const;
  void merge(int* const array, int front, int mid, int end) const;
  
};

#endif
