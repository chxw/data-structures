#include <cassert>
#include <iostream>

int power(int base, int exponent){
	if (exponent == 0){
		return 1;
	}
	else if (exponent > 0){
		return base * power(base, exponent-1);
	}
	else {
		return 1/(base * power(base, exponent+1));
	}
}

int main() {
	int r = power(3,4);
	assert(r == 81);

	std::cout << power(3, -4) << std::endl;
	return 0;
}