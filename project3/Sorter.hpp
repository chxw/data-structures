#ifndef SORTER_HPP
#define SORTER_HPP

enum class Mode{
  INSERTION_SORT,
  MERGE_SORT,
  QUICK_SORT
};

class Sorter{
public:
  // Sorter();
  // Sorter(Mode mode);
  // Sorter(const Sorter& other);
  // Sorter& operator=(const Sorter& other);
  // ~Sorter();

  void sort(int* const array, int size) const;
  // void sort(int* const array, int size, Mode mode) const;

  // void set(Mode mode);
  // Mode getMode() const;

private:
  //your design
  void traverse(int* const array, int key) const;
  void print_array(int* const array, int size) const;
  int* divide(int* const array, int size) const;
  int* merge(int* a, int* b) const;
  
};

#endif
