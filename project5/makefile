test: Node.cpp Hash.cpp Entries.cpp test.cpp
	clang++ -std=c++11 -Wall -Wextra -g -O0 Entries.cpp Node.cpp Hash.cpp test.cpp -o test
time: Node.cpp Hash.cpp Entries.cpp time_test.cpp
	clang++ -std=c++11 -Wall -Wextra -g -O0 Entries.cpp Node.cpp Hash.cpp time_test.cpp -o time
clean: 
	rm -r test.dSYM/ 
	rm -r time.dSYM/
	rm -r database.dSYM/
	rm test
	rm database
	rm time
build: Node.cpp Hash.cpp Entries.cpp main.cpp
	clang++ -std=c++11 -Wall -Wextra -g -O0 Entries.cpp Node.cpp Hash.cpp main.cpp -o database
