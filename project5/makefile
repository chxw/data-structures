test: Node.cpp Hash.cpp Entries.cpp test.cpp
	clang++ -std=c++11 -Wall -Wextra -g -O0 Entries.cpp Node.cpp Hash.cpp test.cpp -o test
cleant: test test.dSYM/
	rm -r test.dSYM/ 
	rm test
cleanb: database database.dSYM/
	rm -r database.dSYM/
	rm database
build: Node.cpp Hash.cpp main.cpp
	clang++ -std=c++11 -Wall -Wextra -g -O0 Entries.cpp Node.cpp Hash.cpp main.cpp -o database
