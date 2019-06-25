#include "Sorter.hpp"
#include <iostream>
#include <algorithm>

// Sorter();
// Sorter(Mode mode);
// Sorter(const Sorter& other);
// Sorter& operator=(const Sorter& other);
// ~Sorter();

void Sorter::sort(int* const array, int size) const{
	// INSERTION_SORT
	// int key = 1;

	// for (int i = 0; i < size; i++){
	// 	if(array[key] < array[i]){
	// 		traverse(array, key);
	// 	}
	// 	key++;
	// }

	// MERGE_SORT	
	divide(array, size);
}

void Sorter::traverse(int* const array, int key) const{
	int i = key - 1;
	while(array[key] < array[i]){
		if(key == 0){
			return;
		}
		else if(array[key] < array[i]){
			std::swap(array[i], array[key]);
			// int hold = array[i];
			// array[i] = array[key];
			// array[key] = hold;
		}
		key--;
		i--;
	}
}

int* Sorter::divide(int* const array, int size) const{
	std::cout << "size: ";
	std::cout << size << std::endl;
	print_array(array,size); 

	if (size == 1){
		return array;
	}

	int* a = new int[size/2];
	int* b = new int[size/2];

	for (int i = 0; i < size/2; i++){
		a[i] = array[i];
	}

	for (int i = size/2; i < size; i++){
		a[i-size/2] = array[i];
	}

	delete array;

	int* a_end = divide(a, size/2);
	int* b_end = divide(b, size/2);

	// int* merged = new int[2];

	// if (a_end < b_end){
	// 	merged[0] = a_end;
	// 	merged[1] = b_end;
	// }
	// else {
	// 	merged[0] = b_end;
	// 	merged[1] = a_end;
	// }
}

void Sorter::print_array(int* const array, int size) const{
  for (int i = 0; i < size; i++){
    std::cout << array[i];
    if(i == size - 1){
      std::cout << "\n";
    }
    else{
      std::cout << ", ";
    }
  }
}

// void sort(int* const array, int size, Mode mode) const;

// void set(Mode mode);
// Mode getMode() const;