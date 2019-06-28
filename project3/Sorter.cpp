#include "Sorter.hpp"
#include <iostream>

// Sorter();
// Sorter(Mode mode);
// Sorter(const Sorter& other);
// Sorter& operator=(const Sorter& other);
// ~Sorter();

void Sorter::sort(int* const array, int size) const{
	// INSERTION_SORT
	int key = 1;

	for (int i = 0; i < size; i++){
		if(array[key] < array[i]){
			traverse(array, key);
		}
		key++;
	}
	std::cout << "here" << std::endl;

	// // MERGE_SORT
	// divide(array, 0, size-1);
}

void Sorter::traverse(int* const array, int key) const{
	int i = key - 1;
	while(array[key] < array[i]){
		std::cout << "key = ";
		std::cout << key << std::endl;

		std::cout << "i = ";
		std::cout << i << std::endl;

		if(key == 0){
			return;
		}
		else if(array[key] < array[i]){
			swap(array[i], array[key]);
		}
		key--;
		i--;
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

	// int temp[end+1];

	// for (int i = 0; i < end; i++){
	// 	temp[i] = array[i];
	// }

	std::cout << "before: ";
	print_array(array, end+1);

	int top = front;
	int point = mid;

	for (int i = mid; i < end; i++){
		top = front;
		while (top <= mid){
			if (array[top] > array[point]){
				swap(array[top], array[point]);
				top++;
			}
			top++;
		}
	}

	for (int i = 0; i < mid; i++){
		point = mid;
		while (point <= end){
			if (array[top] > array[point]){
				swap(array[top], array[point]);
				point++;
			}
			point++;
		}
	}

	std::cout << "after: ";
	print_array(array, end+1);

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