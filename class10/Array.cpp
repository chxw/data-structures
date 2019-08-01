#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

class Array{
public:
	Array();
	Array(int capacity);
	Array(const Array& other);
	Array& operator=(const Array& other);
	~Array();

	void add(int number);
	int at(int index) const;
	int& operator[](int index);

	int getCapacity() const;
	int getSize() const;

private:
	int* numbers;
	int size;
	int capacity;
};

bool operator==(const Array& left, const Array& right);

bool operator!=(const Array& left, const Array& right);

std::ostream& operator<<(std::ostream& out, const Array& array);
#endif

#include "Array.hpp"

bool operator==(const Array& left, cosnt Array& right){
	bool isEqual == true;
	if (left.getSize() != right.getSize()){
		isEqual = false;
	}
	if (left.getCapacity() != right.getCapacity()){
		isEqual = false;
	}
	if (isEqual == true){
		for(int i = 0; i < left.getSize(); i++){
			if (left.at(i) != right.at(i)){
				isEqual = false;
				break;
			}
		}
	}
	return isEqual;
}

bool operator!=(const Array& left, const Array& right){
	return (!left==right);
}


int main(){
	Array a;
	a.add(0);
	a.add(1);

	assert(a.at(0) == 0);
	assert(a.at(1) == 1);

	a[0] = 10;
	assert(a.at(0) != 0);
	assert(a.at(0) == 10);

	assert(a[0] != 0);
	assert(a[0] == 10);

	a.operator[](0) = 20;
	assert(a.at(0) != 10);
	assert(a.at(0) == 20);
	assert(a[0] != 10);
	assert(a[0] == 20);
}