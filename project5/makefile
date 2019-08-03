test: Node.cpp Hash.cpp Entries.cpp test.cpp
	clang++ -std=c++11 -Wall -Wextra -g -O0 Entries.cpp Node.cpp Hash.cpp test.cpp -o test
time: Node.cpp Hash.cpp Entries.cpp time_test.cpp
	clang++ -std=c++11 -Wall -Wextra -g -O0 Entries.cpp Node.cpp Hash.cpp time_test.cpp -o time
cleantest: test test.dSYM/	
	rm test
	rm -r test.dSYM/ 
cleantime: time time.dSYM/
	rm time
	rm -r time.dSYM/
cleanbuild: database database.dSYM/
	rm database
	rm -r database.dSYM/
build: Node.cpp Hash.cpp Entries.cpp main.cpp
	clang++ -std=c++11 -Wall -Wextra -g -O0 Entries.cpp Node.cpp Hash.cpp main.cpp -o database
