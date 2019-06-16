## Name:
Chelsea Wang

## Date:
6/16/19

## Summary:
An implementation of a Scheduler using 3 classes: `Scheduler`, `Node`, and `Event`. The Scheduler is a Singly Linked List of Nodes that hold data (pointers to Events). The Nodes in the Linked List are chronologically ordered. Each Scheduler instance holds Events for 1 month in a year (e.g. "June 2019"). The Scheduler class is able to manipulate the data it holds in such ways, e.g. remove all events, get first event after this timestamp, get number of events on this day, get number of total events, check if Scheduler is empty, etc. It also has a function to return a string representation of the Scheduler, which could look like, for example, this:

2019 Jun.
[01 00:00] SAMPLE
[06 02:35] birthday
[06 09:00] get drink
[30 23:59] feed dog

## Files:
- Event.cpp
- Event.hpp
- Node.cpp
- Node.hpp
- Scheduler.cpp 
- Scheduler.hpp
- test.cpp

## Instructions:
After downloading all files to a directory, compile using: `clang++ -Wall -Wextra -g Event.cpp Scheduler.cpp Node.cpp test.cpp -o test`.

Then, run using: `./test`

## References:

N.A. (N.A.) *Standard library header <stdexcept>*. Retrieved from [https://en.cppreference.com](https://en.cppreference.com).

hmjd (30 October 2012) *What does "pointer being freed was not allocated" mean exactly?*. Retrieved from [https://www.stackoverflow.com/](https://www.stackoverflow.com/).

J. Polfer (26 October 2010) *Valgrind won't return source lines!*. Retrieved from [https://www.stackoverflow.com/](https://www.stackoverflow.com/).

Marius & Sanfer. (1 January 2016) *How do I call the class's destructor?*. Retrieved from [https://www.stackoverflow.com/](https://www.stackoverflow.com/).

schorsch312 (9 May 2018) *Valgrind doesn't see lines in -g file*. Retrieved from [https://www.stackoverflow.com/](https://www.stackoverflow.com/).

Schwartz, Fred. (2004) *OOP: Copy Constructors*. Retrieved from [https://www.fredosaurus.com](https://www.fredosaurus.com).

Schwartz, Fred. (15 February 2004) *OOP: Overloading Assignment*. Retrieved from [https://www.fredosaurus.com](https://www.fredosaurus.com).

Various authors (26 September 2015) *can I call destructor in move assignment operator?*. Retrieved from [https://www.stackoverflow.com/](https://www.stackoverflow.com/).

## Post evalution on planning:
- Did your project go smooth, as planned? If not, which parts? What were causes? How will you improve your planning for future assignments?

1. Drawing out what/how I plan on implementing my project was helpful. I think this project went more smoothly than P1. It could just be from getting back into the swing of things. The main difficulties from this project were:
	- creating a deep copy vs. a shallow copy
	- understanding memory leaks
	- understanding how to find where memory leaks are located from `valgrind`
	- learning the difference between **heap** and **stack**
	- further understanding of **copy constructor** and **assignment operator**
	- 
