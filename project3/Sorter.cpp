#include "Sorter.hpp"
#include <iostream>
#include <stdio.h>

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

	// MERGE_SORT
	divide(array, 0, size-1);

	// QUICK_SORT
	// quicksort(array, 0, size - 1);

}

void Sorter::quicksort(int* const array, int left, int right) const{
	if (left >= right){
		return;
	}

	int p = (left+right)/2;
	int partition = pivot(array, left, right, p);

	// pivot again for {left, partition-1}
	quicksort(array, left, partition - 1);
	// pivot again for {partition, right}
	quicksort(array, partition, right);
}

int Sorter::pivot(int* const array, int low, int high, int p) const{
	int left = low;
	int right = high;

	// if (p == low){
	// 	left = p+1;
	// 	right = high;
	// }
	// else if (p == high){
	// 	left = low;
	// 	right = p-1;
	// }
	// else {
	// 	left = low;
	// 	right = high;
	// }

	int pivot = array[p];

	while (left <= right){
		while(array[left] < pivot){
			left++;
		}
		while(array[right] > pivot){
			right--;
		}
		if(left <= right){
			swap(array[left], array[right]);
			left++;
			right--;
		}
	}

	return left;

}

int Sorter::find_pivot(int* const array, int l, int r) const{
	int m = (l+r)/2;

	if (l == m or m == r){
		return l;
	}

	int med = median(array[l], array[m], array[r]);
	int p;

	if (med == array[l]){
		p = l;
	}
	else if (med == array[m]){
		p = m;
	}
	else{
		p = r;
	}
	return p;
}

int Sorter::median(int a, int b, int c) const{ 
	if ((a < b and b < c) or (c < b and b < a)){
		return b;
	}
	else if ((b < a and a < c) or (c < a and a < b)){
		return a;
	}
	else
		return c;
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
		int mid = (front+end)/2;
		divide(array, front, mid);
		divide(array, mid+1, end);
		merge(array, front, mid, end);
	}
}

void Sorter::merge(int* const array, int front, int mid, int end) const {
	// loop through {front, mid}
	int top = front;

	// loop through {mid + 1, end}
	int point = mid + 1;

	// index for appending to merged
	int i = 0;

	// we know end = array size -1
	int merged[end+1];

	// merge front->mid of array with mid+1->end of array
	while (top <= mid and point <= end){
		if(array[top] <= array[point]){
			merged[i] = array[top];
			top++;
		}
		else{
			merged[i] = array[point];
			point++;
		}
		i++;
	}

	// catch all front and end elements
	while (top <= mid){
		merged[i] = array[top];
		top++;
		i++;
	}

	while (point <= end){
		merged[i] = array[point];
		point++;
		i++;
	}

	// array = merged
	for (i = front; i <= end; i++){
		array[i] = merged[i-front];
	}

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