## Name:
chxw

## Date:
07/21/2019

## Summary:
The program is an implementation of an "enrollment manager", a class that contains a "student database" and "course manager". The enrollment manager controls (un)registering students to the database, adding/cancelling courses, (un)enrolling students to courses, and (de)allocating memory. The student database is a binary search tree of student data (pointers). A course holds an array of student IDS. A course maanger holds an array of course data (pointers). All instances of the student class sent to a student database live in heap memory space, and after they're added ot the student database, the student database is responsible for them. All instance of course class sent to a course manager live in heap memory space, and after they're held by the course manager, the course manager is responsible for them. 

## Files:
`test.cpp StudentDatabase.hpp StudentDatabase.cpp Student.hpp Student.cpp EnrollmentManager.hpp EnrollmentManager.cpp CourseManager.hpp CourseManager.cpp Course.hpp Course.cpp BSTNode.hpp BSTNode.cpp`

## Instructions:
`clang++ -std=c++11 *.cpp -o test`
`./test`

## References:
- N.A. (N.A.). *Deleting a node from a BST -- Part 2 (the hard case)*. Retrieved from [http://www.mathcs.emory.edu/~cheung/Courses/171/Syllabus/9-BinTree/BST-delete2.html](http://www.mathcs.emory.edu/~cheung/Courses/171/Syllabus/9-BinTree/BST-delete2.html).
- N.A. (N.A.). *Binary search tree. Removing a node.* Retrieved from [http://www.algolist.net/Data_structures/Binary_search_tree/Removal](http://www.algolist.net/Data_structures/Binary_search_tree/Removal).
- N.A. (N.A.). *Deletion from BST (Binary Search Tree).* Retrieved from [https://www.techiedelight.com/deletion-from-bst/](https://www.techiedelight.com/deletion-from-bst/).
- N.A. (N.A.). *Binary Search Tree | Set 1 (Search and Insertion)*. Retrieved from [https://www.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/](https://www.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/).
- N.A. (N.A.). *10.2.6. Balanced Binary Search Trees*. Retrieved from [http://www.cs.ecu.edu/karl/3300/spr16/Notes/DataStructure/Tree/balance.html](http://www.cs.ecu.edu/karl/3300/spr16/Notes/DataStructure/Tree/balance.html).
- N.A. (N.A.). *Data Structure - Binary Search Tree*. Retreived from [https://www.tutorialspoint.com/data_structures_algorithms/binary_search_tree](https://www.tutorialspoint.com/data_structures_algorithms/binary_search_tree).
- N.A. (N.A.). *Binary Search Tree*. Retrieved from [https://www.hackerearth.com/practice/data-structures/trees/binary-search-tree/tutorial/](https://www.hackerearth.com/practice/data-structures/trees/binary-search-tree/tutorial/).
- AnT and Smi. (12 November 2014). *Difference: std::runtime_error vs std::exception()*. Retrieved from [https://stackoverflow.com/questions/1569726/difference-stdruntime-error-vs-stdexception
](https://stackoverflow.com/questions/1569726/difference-stdruntime-error-vs-stdexception
).
- interjay. (30 April 2011). *Valgrind yells about an uninitialised bytes*. Retrieved from [https://stackoverflow.com/questions/5844242/valgrind-yells-about-an-uninitialised-bytes](https://stackoverflow.com/questions/5844242/valgrind-yells-about-an-uninitialised-bytes).
- Mats Petersson. (29 October 2013). *What's the meaning of exception code "EXC_I386_GPFLT"?*. Retrieved from [https://stackoverflow.com/questions/19651788/whats-the-meaning-of-exception-code-exc-i386-gpflt](https://stackoverflow.com/questions/19651788/whats-the-meaning-of-exception-code-exc-i386-gpflt).
- Quentin F. Stout and Bette L. Warren. (September 1986). *Tree Rebalancing in Optimal Time and Space*. Retrieved from [http://web.eecs.umich.edu/~qstout/pap/CACM86.pdf](http://web.eecs.umich.edu/~qstout/pap/CACM86.pdf).
- Wikipedia contributors. (2019, May 19). *Binary search tree*. In Wikipedia, The Free Encyclopedia. Retrieved 16:36, July 21, 2019, from [https://en.wikipedia.org/w/index.php?title=Binary_search_tree&oldid=897760028](https://en.wikipedia.org/w/index.php?title=Binary_search_tree&oldid=897760028).
- Robert Sedgewick and Kevin Wayne. (2016 August 26). *Binary Search Trees* Retrieved from [https://algs4.cs.princeton.edu/32bst/](https://algs4.cs.princeton.edu/32bst/).

## Post evalution on planning:
1. *Testing*. I thought I've tested every hedge case for each of my modules, and yet I'm failing all the preliminary autograder tests for EnrollmentManager... It feels really frustrating because I thought I was on track/completed all the functions and have tested all of them rigorously on time/according to plan and yet I feel like my first submit for P4 will be less than 50... And I still can't figure out which hedge cases I'm failing? I guess, next time I'll try writing test cases before implementing functions. Here is a list of tests that I performed one enrollment manager in an attempt to find what's causing me to fail the preliminary autograder tests:
	- Register a large amount of students (10000)
	- Unregister all students except for student 0 (root)
	- Add a large amount of courses (10000)
	- Cancel all courses except for course 0 (index 0)
	- Enroll that 1 student to that 1 course (student 0 to course 0)
	- Unregister all students except for last student 9999 (max node)
	- Enroll all students (10000) to all courses (10000)  -- this took 3+ hours, but I tested it and it works. It's commented out in the test.cpp

3. *Learned (kind of) about lldb*:
Some notes from debugging valgrind errors...
```
Process 85704 stopped
* thread #1, queue = 'com.apple.main-thread', stop reason = EXC_BAD_ACCESS (code=1, address=0x0)
    frame #0: 0x000000010000283c test`Student::getID() const + 12
test`Student::getID:
->  0x10000283c <+12>: movl   (%rdi), %eax
    0x10000283e <+14>: popq   %rbp
    0x10000283f <+15>: retq   

test`Student::getFirstName:
    0x100002840 <+0>:  pushq  %rbp
Target 0: (test) stopped.
```
