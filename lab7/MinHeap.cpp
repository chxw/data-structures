#include "MinHeap.hpp"
#include <string>
#include <iostream>

MinHeap::MinHeap(){
	size = 0;
	capacity = 15;
	array = new int[capacity];
}

//  MinHeap(const MinHeap& other);
//  MinHeap& operator=(const MinHeap& other);

MinHeap::~MinHeap(){
	delete array;
}

void MinHeap::insert(int number){
	if(isEmpty()){
		array[0] = number;
		size++;
		return;
	}
	if (size == capacity){
		expand();
	}

	array[size] = number;
	bubble_up(size);
	size++;

	return;

}

void MinHeap::expand(){
	capacity += 15;
	int* temp = new int[capacity];
	for (int i = 0; i < capacity; i++){
		temp[i] = array[i];
	}
	delete array;
	array = temp;
	temp = nullptr;
}

void MinHeap::fit(){
	capacity = size;
	int* temp = new int[capacity];
	for (int i = 0; i < capacity; i++){
		temp[i] = array[i];
	}
	delete array;
	array = temp;
	temp = nullptr;
}

void MinHeap::swap(int &a, int &b){
	int hold = a;
	a = b;
	b = hold;
}

int MinHeap::extractMin(){
	if(isEmpty()){
		throw std::runtime_error("Not Valid");
	}
	else if(size == 1){
		return array[0];
	}

	int min = array[0];

	swap(array[0], array[size]);
	size--;
	// fit();
	bubble_down(0);

	return min;
}

void MinHeap::bubble_up(int start){
	int child = start;
	int parent = (child - 1)/2;

	while (array[child] < array[parent]){
		swap(array[child], array[parent]);
		child = parent;
		parent = (child - 1)/2;
		if (parent < 0){
			break;
		}
	}
}

void MinHeap::bubble_down(int start){
	int parent = start;
	int left = (2*parent)+1;
	int right = (2*parent)+2;

	while (true){
		int min = find_min(array[parent], array[left], array[right]);
		if (min == array[parent]){
			break;
		}
		else if(min == array[left]){
			swap(array[left], array[parent]);
			parent = left;
			left = (2*parent)+1;
			right = (2*parent)+2;
		}
		else{
			swap(array[right], array[parent]);
			parent = right;
			left = (2*parent)+1;
			right = (2*parent)+2;
		}
	}
}

int MinHeap::find_min(int a, int b, int c){
	if (a < b and a < c){
		return a;
	}
	else if (b < a and b < c){
		return b;
	}
	return c;
}

bool MinHeap::isEmpty() const{
	if (size > 0){
		return false;
	}
	return true;
}

void MinHeap::toString() const{
	if (isEmpty()){
		return;
	}
	for (int i = 0; i < size; i++){
		std::cout << array[i];
		if (i != size - 1){
			std::cout << ", ";
		}
	}
}