#include "Sorter.hpp"
#include <iostream>
#include <algorithm>

#include <vector>

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
	std::cout << "final" << std::endl;
	print_array(array, 600);
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

	if (size <= 1){
		return array;
	}

	int* a = new int[size/2];
	int* b = new int[size/2];

	for (int i = 0; i < size/2; i++){
		a[i] = array[i];
	}

	for (int i = size/2; i < size; i++){
		b[i-size/2] = array[i];
	}

	// delete array;

	a = divide(a, size/2);
	b = divide(b, size/2);

	return merge(a, b);
}

int* Sorter::merge(int* a, int* b) const{
	int a_size = 1;
	int b_size = 1;
	int merged_size = 0;
	int merged_capacity = a_size + b_size;

	int* merged = new int[merged_size];

	while (a_size != 0 and b_size != 0){
		if(a[0] <= b[0]){
			if(merged_size == merged_capacity)
			{
				merged_capacity++;
				int* temp = new int[merged_capacity];
				delete[] merged;
				merged = temp;
				temp = nullptr;

			}

			merged[merged_size] = a[0];
			merged_size++;

			int* temp = new int[a_size--];
			for (int i = 0; i < a_size-1; i++){
				temp[i] = a[i+1];
			}
			delete[] a;
			a = temp;
			temp = nullptr;
		}
		else{
			if(merged_size == merged_capacity)
			{
				merged_capacity++;
				int* temp = new int[merged_capacity];
				delete[] merged;
				merged = temp;
				temp = nullptr;

			}

			merged[merged_size] = b[0];
			merged_size++;

			int* temp = new int[b_size--];
			for (int i = 0; i < b_size-1; i++){
				temp[i] = b[i+1];
			}
			delete[] b;
			b = temp;
			temp = nullptr;
		}
	}

	print_array(merged, merged_size);

	return merged;
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