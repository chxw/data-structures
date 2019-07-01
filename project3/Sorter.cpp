#include "Sorter.hpp"
#include <iostream>
#include <stdio.h>

Sorter::Sorter(){
	mode = Mode::INSERTION_SORT;
}

Sorter::Sorter(Mode m){
	switch(m)
	{
		case Mode::INSERTION_SORT: mode = Mode::INSERTION_SORT;
		case Mode::MERGE_SORT: mode = Mode::MERGE_SORT;
		case Mode::QUICK_SORT: mode = Mode::QUICK_SORT;
	}
}

Sorter::Sorter(const Sorter& other){
	mode = other.mode;
}

Sorter& Sorter::operator=(const Sorter& other){
	if(&other != this){
		mode = other.mode;
	}
	return(*this);
}

Sorter::~Sorter(){

}

void Sorter::sort(int* const array, int size) const{
	if(array == nullptr or size < 1){
		throw std::range_error("Invalid Argument");
	}
	if (mode == Mode::INSERTION_SORT){
		insertion_sort(array, size);
	}

	if (mode == Mode::MERGE_SORT){
		divide(array, 0, size-1);
	}

	if (mode == Mode::QUICK_SORT){
		quick_sort(array, 0, size - 1);
	}
}

void Sorter::sort(int* const array, int size, Mode m) const{
	if(array == nullptr or size < 1){
		throw std::range_error("Invalid Argument");
	}
	if (m == Mode::INSERTION_SORT){
		insertion_sort(array, size);
	}

	if (m == Mode::MERGE_SORT){
		divide(array, 0, size-1);
	}

	if (m == Mode::QUICK_SORT){
		quick_sort(array, 0, size - 1);
	}
}

void Sorter::set(Mode m) {
	mode = m;
}

Mode Sorter::getMode() const{
	return mode;
}

void Sorter::insertion_sort(int* const array, int size) const{
	int key; 

	for (int i = 0; i < size; i++){
		key = i+1;
		if (key == size){
			return;
		}
		if(array[key] < array[i]){
			traverse(array, key);
		}
	}
}

void Sorter::traverse(int* const array, int key) const{
	int i = key - 1;

	while(array[key] < array[i] and i > 0){
		if(array[key] < array[i]){
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
		int mid = (front+end)/2;
		// divide 1st half of array
		divide(array, front, mid);
		// divide 2nd half of array
		divide(array, mid+1, end);
		// go back up contiously merging
		merge(array, front, mid, end);
	}
}

void Sorter::merge(int* const array, int front, int mid, int end) const {
	// loop through {front, mid}, top goes toward mid
	int top = front;

	// loop through {mid + 1, end}, point goes toward end
	int point = mid + 1;

	// index for appending to merged
	int i = 0;

	// we know end = array size -1
	int merged[end+1];

	// merge front->mid of array with mid+1->end of array
	while (top <= mid and point <= end){
		// compare first elements of front arr and end arr and append lesser to front of merged arr
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

	// catch all elements that remain in front arr or end arr
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

void Sorter::quick_sort(int* const array, int left, int right) const{
	if (left >= right){
		return;
	}

	// int p = (left+right)/2;

	int p = find_pivot(array, left, right);
	int partition = pivot(array, left, right, p);

	// pivot again for {left, partition-1}
	quick_sort(array, left, partition - 1);
	// pivot again for {partition, right}
	quick_sort(array, partition, right);
}

int Sorter::pivot(int* const array, int low, int high, int p) const{
	int left = low;
	int right = high;

	int pivot = array[p];

	// swap wherever pivot it is with mid elem in array
	swap(array[p], array[(low+high)/2]);

	while (left <= right){
		// move left until you find next elem that needs to swap
		while(array[left] < pivot){
			left++;
		}
		// move right until you find next elem that needs to swap
		while(array[right] > pivot){
			right--;
		}
		// check if left and right have crossed partition, otherwise swap
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