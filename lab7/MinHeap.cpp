#include "MinHeap.hpp"
#include <string>
#include <iostream>

MinHeap::MinHeap(){
	size = 0;
	capacity = 10000;
	array = new int[capacity];
}

//  MinHeap(const MinHeap& other);
//  MinHeap& operator=(const MinHeap& other);

MinHeap::~MinHeap(){
	delete[] array;
}

int MinHeap::get_parent(int node){
	return (node - 1)/2;
}

int MinHeap::get_left(int node){
	return 2*node+1;
}

int MinHeap::get_right(int node){
	return 2*node+2;
}

void MinHeap::swap(int &a, int &b){
	int hold = a;
	a = b;
	b = hold;
}

void MinHeap::insert(int number){
	if (size == capacity){
		throw std::runtime_error("Overflow, int not inserted");
	}

	array[size] = number;
	size++;
	bubble_up(size-1);

	return;

}

int MinHeap::extractMin(){
	if(isEmpty()){
		throw std::runtime_error("Not Valid");
	}
	else if (size == 1){
		size--;
		return array[0];
	}

	int min = array[0];
	array[0] = array[size-1];
	size--;
	bubble_down(0);

	return min;
}

void MinHeap::bubble_up(int child){
	int parent = get_parent(child);

	while (parent >= 0 and array[child] < array[parent]){
		swap(array[child], array[parent]);
		child = parent;
		parent = get_parent(child);
	}
}

void MinHeap::bubble_down(int parent){
	int left = get_left(parent);
	int right = get_right(parent);

	int min = parent;

	if (left < size and array[left] < array[parent]){
		min = left;
	}
	if (right < size and array[right] < array[min]){
		min = right;
	}
	if (min != parent){
		swap(array[parent], array[min]);
		bubble_down(min);
	}
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
	std::cout << std::endl;
}