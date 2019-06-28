#include "Sorter.hpp"
#include <iostream>

// Sorter();
// Sorter(Mode mode);
// Sorter(const Sorter& other);
// Sorter& operator=(const Sorter& other);
// ~Sorter();

void Sorter::sort(int* const array, int size) const{
	// INSERTION_SORT
	// int key; 

	// for (int i = 0; i < size; i++){
	// 	key = i+1;
	// 	if (key == size){
	// 		return;
	// 	}
	// 	if(array[key] < array[i]){
	// 		traverse(array, key);
	// 	}
	// }

	// // MERGE_SORT
	divide(array, 0, size-1);
}

void Sorter::traverse(int* const array, int key) const{
	int i = key - 1;

	while(array[key] < array[i]){
		if(array[key] < array[i]){
			swap(array[i], array[key]);
		}
		key--;
		i--;
		if(i < 0){
			return;
		}
	}
}

void Sorter::swap(int &a, int &b) const{
	int hold = a;
	a = b;
	b = hold;
}


void Sorter::divide(int* const array, int front, int end) const{
	if (front < end){
		int mid = front + (end - front)/2;
		divide(array, front, mid);
		divide(array, mid+1, end);
		merge(array, front, mid, end);
	}
}

void Sorter::merge(int* const array, int front, int mid, int end) const {
	// merge front->mid of array with mid->end of array
	// we know end = array size -1

	int front_arr[mid+1];
	int end_arr[end-mid+1];

	for (int i = 0; i < mid; i++){
		front_arr[i] = array[i];
	}

	for (int i = mid; i < end; i++){
		end_arr[i-mid] = array[i];
	}

	std::cout << "front int: ";
	std::cout << front << s;

	std::cout << "front: ";
	print_array(array, end+1);

	std::cout << "end: ";
	print_array(array, end+1);

	std::cout << "before: ";
	print_array(array, end+1);


	// std::cout << "after: ";
	// print_array(array, end+1);

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