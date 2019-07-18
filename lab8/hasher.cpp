#include <string>
#include "hasher.hpp"

unsigned int generateHashCodeOf(const std::string& key){
	char first = key.at(0);
	int words = 479828;
	int buckets = 16384;
	int partition = 630;

	int h = 0;

	if (first == "a" or first == "A"){
		h += partition*1;
	}
	else if (first == "b" or first == "B"){
		h += partition*2;
	}
	else if (first == "c" or first == "C"){
		h += partition*3;
	}
	else if (first == "d" or first == "D"){
		h += partition*4;
	}
	else if (first == "e" or first == "E"){
		h += partition*5;
	}
	else if (first == "f" or first == "F"){
		h += partition*6;
	}
	else if (first == "g" or first == "G"){
		h += partition*7;
	}
	else if (first == "h" or first == "H"){
		h += partition*8;
	}
	else if (first == "i" or first == "I"){
		h += partition*9;
	}
	else if (first == "j" or first == "J"){
		h += partition*10;
	}
	else if (first == "k" or first == "K"){
		h += partition*11;
	}
	else if (first == "l" or first == "L"){
		h += partition*12;
	}
	else if (first == "m" or first == "M"){
		h += partition*13;
	}
	else if (first == "n" or first == "N"){
		h += partition*14;
	}
	else if (first == "o" or first == "O"){
		h += partition*15;
	}
	else if (first == "p" or first == "P"){
		h += partition*16;
	}
	else if (first == "q" or first == "Q"){
		h += partition*17;
	}
	else if (first == "r" or first == "R"){
		h += partition*18;
	}
	else if (first == "s" or first == "S"){
		h += partition*19;
	}
	else if (first == "t" or first == "T"){
		h += partition*20;
	}
	else if (first == "u" or first == "U"){
		h += partition*21;
	}
	else if (first == "v" or first == "V"){
		h += partition*22;
	}
	else if (first == "w" or first = "W"){
		h += partition*23;
	}
	else if (first == "x" or first == "X"){
		h += partition*24;
	}
	else if (first == "y" or first == "Y"){
		h += partition*25;
	}
	else if (first == "z" or first == "Z"){
		h += partition*26
	}

	h -= abs(key.length());

	return h % 16384;
}
