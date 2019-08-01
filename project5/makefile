test: Node.cpp Hash.cpp Entries.cpp test.cpp
	clang++ -std=c++11 -Wall -Wextra -g -O0 Entries.cpp Node.cpp Hash.cpp test.cpp -o test
clean: database database.dSYM/ test test.dSYM/
	rm -r test.dSYM/ database.dSYM/
	rm test database
build: Node.cpp Hash.cpp main.cpp
	clang++ -std=c++11 -Wall -Wextra -g -O0 Entries.cpp Node.cpp Hash.cpp main.cpp -o database
