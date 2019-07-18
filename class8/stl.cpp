#include <iterator>
#include <vector>
#include <string>
#include <cassert>

int main(){
	std::vector<int> numbers;

	assert(numbers.empty() == true);

	for (int i = 0; i < 100; i++){
		numbers.push_back(i);
	}

	for (int i = 0; i < 100; i++){
		// int number = numbers.at(i); 
		// operator overloading (using [] overloading .at())
		int number2 = numbers[i];
	}

	std::vector<std::string> alphabet;

	alphabet.push_back("A");
	alphabet.push_back("B");
	alphabet.push_back("C");
	alphabet.push_back("D");
	alphabet.push_back("E");
	alphabet.push_back("F");

	// instead of int i, std::vector<std::string> iterator i
	for (std::vector<std::string>iterator i = alphabet.begin(); i != alphabet.end(); i++){
		std::cout << (*i) << std::endl;
	}
	
	return 0;
}