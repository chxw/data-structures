#include <string>
#include "hasher.hpp"
#include <iostream>

unsigned int generateHashCodeOf(const std::string& key){
	int index = 0;
	char c = key.at(index);
	int push = 1;
	int h = pusher(c);

	for (std::string::size_type i = 1; i < key.size(); i++){
		h = h*pusher(key.at(i));
	}

	return h % 16384;
}

int pusher(char c){
	int partition = 630;
	int push = 0;

	if (c == 'a' or c == 'A'){
		push = 1;
	}
	else if (c == 'b' or c == 'B'){
		push = 2;
	}
	else if (c == 'c' or c == 'C'){
		push = 3;
	}
	else if (c == 'd' or c == 'D'){
		push = 4;
	}
	else if (c == 'e' or c == 'E'){
		push = 5;
	}
	else if (c == 'f' or c == 'F'){
		push = 6;
	}
	else if (c == 'g' or c == 'G'){
		push = 7;
	}
	else if (c == 'h' or c == 'H'){
		push = 8;
	}
	else if (c == 'i' or c == 'I'){
		push = 9;
	}
	else if (c == 'j' or c == 'J'){
		push = 10;
	}
	else if (c == 'k' or c == 'K'){
		push = 11;
	}
	else if (c == 'l' or c == 'L'){
		push = 12;
	}
	else if (c == 'm' or c == 'M'){
		push = 13;
	}
	else if (c == 'n' or c == 'N'){
		push = 14;
	}
	else if (c == 'o' or c == 'O'){
		push = 15;
	}
	else if (c == 'p' or c == 'P'){
		push = 16;
	}
	else if (c == 'q' or c == 'Q'){
		push = 17;
	}
	else if (c == 'r' or c == 'R'){
		push = 18;
	}
	else if (c == 's' or c == 'S'){
		push = 19;
	}
	else if (c == 't' or c == 'T'){
		push = 20;
	}
	else if (c == 'u' or c == 'U'){
		push = 21;
	}
	else if (c == 'v' or c == 'V'){
		push = 22;
	}
	else if (c == 'w' or c == 'W'){
		push = 23;
	}
	else if (c == 'x' or c == 'X'){
		push = 24;
	}
	else if (c == 'y' or c == 'Y'){
		push = 25;
	}
	else if (c == 'z' or c == 'Z'){
		push = 26;
	}

	return push;
}
