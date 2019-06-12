#include <iostream>
#include <string>

//function call stack

int add2(int to){
	return to + 2;
}

int add1(int to){
	return to + 1;
}

int addx(int to){
	int r1 = add1(to);
	int r2 = add2(to);
	int r3 = r1 = r2;
	return r3;
}

int main(){
	int r = addX(i);

	std::cout << r << std::endl;

	return 0;
}