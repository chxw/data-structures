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
	int* final;
	final = divide(array, size);
	std::cout << "final" << std::endl;
	print_array(final, 600);
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
	if (size <= 1){
		return array;
	}

	int mid = size/2;

	int a[mid];
	int* a_ptr = a;
	int b[mid];
	int* b_ptr = b;

	for (int i = 0; i < mid; i++){
		a[i] = array[i];
	}

	for (int i = mid; i < size; i++){
		b[i-mid] = array[i];
	}

	// delete array;

	a_ptr = divide(a_ptr, mid);
	b_ptr = divide(b_ptr, mid);

	int a_size = sizeof(a)/sizeof(a[0]);
	int b_size = sizeof(a)/sizeof(a[0]);
	
	return merge(a_ptr, a_size, b_ptr, b_size);
}

int* Sorter::merge(int* a, int a_size, int* b, int b_size) const{
	int merged_size = 0;
	int merged_capacity = a_size + b_size;
	int* merged = new int[merged_capacity];

	while (a_size != 0 and b_size != 0){
		if(a[0] <= b[0]){
			if(merged_size == merged_capacity)
			{
				// dynamically expand merged array
				merged_capacity++;
				int* temp = new int[merged_capacity];
				delete[] merged;
				merged = temp;
				temp = nullptr;
			}

			// add a[0] to merged
			merged[merged_size] = a[0];
			merged_size++;

			// remove a[0] from a
			a_size--;
			int* temp = new int[a_size];
			for (int i = 0; i < a_size; i++){
				temp[i] = a[i+1];
			}
			// delete[] a;
			a = temp;
			temp = nullptr;
			std::cout << "merged (0): ";
			print_array(merged, merged_size);
		}
		else{
			if(merged_size == merged_capacity)
			{
				// dynamically expand merged array
				merged_capacity++;
				int* temp = new int[merged_capacity];
				delete[] merged;
				merged = temp;
				temp = nullptr;
			}

			// add b[0] to merged
			merged[merged_size] = b[0];
			merged_size++;

			//remove b[0] from b
			b_size--;
			int* temp = new int[b_size];
			for (int i = 0; i < b_size; i++){
				temp[i] = b[i+1];
			}
			// delete[] b;
			b = temp;
			temp = nullptr;
			std::cout << "merged (1): ";
			print_array(merged, merged_size);
		}
	}
	
	while (a_size != 0){
		if(merged_size == merged_capacity)
			{
				// dynamically expand merged array
				merged_capacity++;
				int* temp = new int[merged_capacity];
				delete[] merged;
				merged = temp;
				temp = nullptr;
			}

		// add a[0] to merged
		merged[merged_size] = a[0];
		merged_size++;

		// remove a[0] from a
		a_size--;
		int* temp = new int[a_size];
		for (int i = 0; i < a_size; i++){
			temp[i] = a[i+1];
		}
		// delete[] a;
		a = temp;
		temp = nullptr;
		std::cout << "merged (2): ";
		print_array(merged, merged_size);
	}
	while (b_size != 0){
		if(merged_size == merged_capacity)
			{
				// dynamically expand merged array
				merged_capacity++;
				int* temp = new int[merged_capacity];
				delete[] merged;
				merged = temp;
				temp = nullptr;
			}

		// add b[0] to merged
		merged[merged_size] = b[0];
		merged_size++;

		//remove b[0] from b
		b_size--;
		int* temp = new int[b_size];
		for (int i = 0; i < b_size; i++){
			temp[i] = b[i+1];
		}
		// delete[] b;
		b = temp;
		temp = nullptr;

		std::cout << "merged (3): ";
		print_array(merged, merged_size);
	}

	std::cout << "merged (4): ";
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