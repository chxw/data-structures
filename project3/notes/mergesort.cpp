#include "Sorter.hpp"
#include <iostream>

int* Sorter::divide(int* const array, int size) const{
	if (size <= 1){
		return array;
	}

	int mid = size/2;
	std::cout << "mid: ";
	std::cout << mid << std::endl;

	int* a = new int[mid];
	int* b = new int[mid];

	for (int i = 0; i < mid; i++){
		a[i] = array[i];
	}

	for (int i = mid; i < size; i++){
		b[i-mid] = array[i];
	}

	a = divide(a, mid);
	b = divide(b, mid);

	int a_size = mid/2;
	int b_size = mid/2;

	if (mid/2 < 1){
		a_size = 1;
		b_size = 1;
	}
	
	return merge(a, a_size, b, b_size);
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
			delete[] a;
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
			delete[] b;
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
		delete[] a;
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
		delete[] b;
		b = temp;
		temp = nullptr;

		std::cout << "merged (3): ";
		print_array(merged, merged_size);
	}

	std::cout << "merged (4): ";
	print_array(merged, merged_size);

	return merged;
}

/////////////////////////
void Sorter::merge(int* const array, int front, int mid, int end) const {
	// merge front->mid of array with mid->end of array

	// // front->mid size
	// int front_size = mid + 1;
	// // front->mid size
	// int end_size = (end + 1) - front_size;

	// we know end = array size -1
	int* temp = new int[end+1];

	for (int i = 0; i < end; i++){
		temp[i] = array[i];
	}

	int point = mid;

	while (front <= mid and point <= end){
		if (temp[front] > temp[point]){
			swap(array[front], array[point]);
		}
		front++;
		point++;
	}

	while (front <= mid){
		if (temp[front] > temp[point]){
			swap(array[front], array[point]);
		}
		front++;
	}
	while (point <= end){
		if (temp[front] > temp[point]){
			swap(array[front], array[point]);
		}
		point++;
	}

	print_array(array, end+1);


}

///////////////////////////
void Sorter::merge(int* const array, int mid, int end) const {
	// merge front->mid of array with mid->end of array

	// // {front, mid} size
	int a_size = mid + 1;
	// // {mid, end} size
	int b_size = (end + 1) - a_size;

	int* a = new int[a_size];
	int* b = new int[b_size];

	for(int i = 0; i < mid; i++){
		a[i] = array[i];
	}
	for(int i = mid; i <= end; i++){
		b[i-mid] = array[i];
	}

	int i = 0;
	while (a_size != 0 and b_size != 0){
		if(a[0] <= b[0]){
			array[i] = a[0];
			i++;

			a_size--;
			int* temp = new int[a_size];
			for (int i = 0; i < a_size; i++){
				temp[i] = a[i+1];
			}
			delete[] a;
			a = temp;
			temp = nullptr;
		}
		else{
			array[i] = b[0];
			i++;

			b_size--;
			int* temp = new int[b_size];
			for (int i = 0; i < b_size; i++){
				temp[i] = b[i+1];
			}
			delete[] b;
			b = temp;
			temp = nullptr;
		}
	}

	while (a_size != 0){
		array[i] = a[0];
		i++;

		a_size--;
		int* temp = new int[a_size];
		for (int i = 0; i < a_size; i++){
			temp[i] = a[i+1];
		}
		delete[] a;
		a = temp;
		temp = nullptr;
	}

	while (b_size != 0){
		array[i] = b[0];
		i++;

		b_size--;
		int* temp = new int[b_size];
		for (int i = 0; i < b_size; i++){
			temp[i] = b[i+1];
		}
		delete[] b;
		b = temp;
		temp = nullptr;
	}
}
