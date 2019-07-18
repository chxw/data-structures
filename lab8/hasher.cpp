#include <string>
#include "hasher.hpp"
#include <iostream>

unsigned int generateHashCodeOf(const std::string& key){
	int index = 0;
	char c = key.at(index);
	int push = 1;
	int h = 0;

	for (std::string::size_type i = 0; i < key.size(); i++){
		h += pusher(key.at(i));
	}

	return h % 16384;
}

int pusher(char c){
	int partition = 630;
	int push = 0;

	if (c == 'a' or c == 'A'){
		push = partition*1;
	}
	else if (c == 'b' or c == 'B'){
		push = partition*2;
	}
	else if (c == 'c' or c == 'C'){
		push = partition*3;
	}
	else if (c == 'd' or c == 'D'){
		push = partition*4;
	}
	else if (c == 'e' or c == 'E'){
		push = partition*5;
	}
	else if (c == 'f' or c == 'F'){
		push = partition*6;
	}
	else if (c == 'g' or c == 'G'){
		push = partition*7;
	}
	else if (c == 'h' or c == 'H'){
		push = partition*8;
	}
	else if (c == 'i' or c == 'I'){
		push = partition*9;
	}
	else if (c == 'j' or c == 'J'){
		push = partition*10;
	}
	else if (c == 'k' or c == 'K'){
		push = partition*11;
	}
	else if (c == 'l' or c == 'L'){
		push = partition*12;
	}
	else if (c == 'm' or c == 'M'){
		push = partition*13;
	}
	else if (c == 'n' or c == 'N'){
		push = partition*14;
	}
	else if (c == 'o' or c == 'O'){
		push = partition*15;
	}
	else if (c == 'p' or c == 'P'){
		push = partition*16;
	}
	else if (c == 'q' or c == 'Q'){
		push = partition*17;
	}
	else if (c == 'r' or c == 'R'){
		push = partition*18;
	}
	else if (c == 's' or c == 'S'){
		push = partition*19;
	}
	else if (c == 't' or c == 'T'){
		push = partition*20;
	}
	else if (c == 'u' or c == 'U'){
		push = partition*21;
	}
	else if (c == 'v' or c == 'V'){
		push = partition*22;
	}
	else if (c == 'w' or c == 'W'){
		push = partition*23;
	}
	else if (c == 'x' or c == 'X'){
		push = partition*24;
	}
	else if (c == 'y' or c == 'Y'){
		push = partition*25;
	}
	else if (c == 'z' or c == 'Z'){
		push = partition*26;
	}

	return push;
}
