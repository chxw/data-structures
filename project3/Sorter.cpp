#include "Sorter.hpp"

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
			int hold = array[i];
			array[i] = array[key];
			array[key] = hold;
		}
		key--;
		i--;
	}
}

int Sorter::divide(int* const array, int size) const{
	if (size == 1){
		int end = array[0]
		delete array;
		return end;
	}

	int* a = new int[size/2];
	int* b = new int[size/2];

	for (int i = 0; i < size/2; i++){
		a[i] = array[i];
	}

	for (int i = 0; i < size/2; i++){
		a[i] = array[i + size/2];
	}

	delete array;

	divide(a);
	divide(b);
}

// void sort(int* const array, int size, Mode mode) const;

// void set(Mode mode);
// Mode getMode() const;