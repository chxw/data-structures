## Name:
Chelsea Wang

## Date:
5/30/19

## Summary:
An implementation of a Card Deck using 2 classes: `Card` and `CardDeck`. The Card class represents a Card by holding a string to represent suit and holding an int to represent rank. The CardDeck holds Card objects, keeps order of Card objects, and is able to add, insert at(index), replace, remove, swap cards as well as check to see if it has a card, count how many of a certain card it has, and take away n number of cards and return those cards.

## Files:
- Card.cpp
- Card.hpp
- CardDeck.cpp
- CardDeck.hpp
- test.cpp

## Instructions:
After downloading all files to a directory, compile using: `clang++ test.cpp -o test`.

Then, run using: `./test`

Look in test.cpp to play around with written test functions to test different functionalities of Card and CardDeck classes. 

## References:
N.A. (N.A.) *4.3 Resizing arrays*. Retrieved from [https://www.whitman.edu/](https://www.whitman.edu/mathematics/c++_online/).

N.A. (N.A.) *Arrays*. Retrieved from [https://www.cplusplus.com](http://www.cplusplus.com/).

N.A. (N.A.) *Array initialization*. Retrieved from [https://en.cppreference.com](https://en.cppreference.com).

N.A. Simple Snippets. (2 December 2017) *Constructors & Destructors in C++ Programming | Object Oriented Programming Concepts*. Retrieved from [https://www.youtube.com/](https://www.youtube.com/).

Disch (13742) (2 May 2009). *Headers and Includes: Why and How*. Retrieved from [https://www.cplusplus.com](http://www.cplusplus.com/).

N.A. (N.A.) *Pointers*. Retrieved from [https://www.cplusplus.com](http://www.cplusplus.com/).

N.A. (N.A.) *std::map*. Retrieved from [http://www.cplusplus.com](http://www.cplusplus.com).

N.A. (N.A.) *std::map: The C++ dictionary class*. Retrieved from [https://www.moderncplusplus.com/](https://www.moderncplusplus.com/).

N.A. (N.A.) *std::operator+ (string)*. Retrieved from [https://www.cplusplus.com](http://www.cplusplus.com/).

## Post evalution on planning:
- Did your project go smooth, as planned? If not, which parts? What were causes?

1. DEBUGGING: Going back to C++ after using Python. Much harder to go Python -> C++ than go C++ -> Python. Debugging in C++ is much harder than Python... error messages require deciphering and only *sometimes* points you to where the issue is. (ex. I was stuck with an error that was pointing to an issue with a string for \~ half a day, but after many `std::cout`s I realized I was trying to access beyond the range of an array).

2. ARRAYS: Keeping track of pointers, elements in array, accidentally accessing outside the range of an array, receiving random information when accessing outside the range of an array. Keeping track of what size is, what capacity, where index is at any given time when looping through an array. All things I had the luxury of not totally dealing with in Python.

3. TESTING: Some errors that I thought were in `Card.cpp` or `CardDeck.cpp` were actually errors in my `test.cpp` file. For future projects, I will work harder to keep my testing more organized, readable, and efficient. The `test.cpp` in this project I tried to keep extensive and neat, but I think is actually, instead, overwhelming and inefficient.

- How will you improve your planning for future assignments?

I definitely will plan out how to write every method before even beginning to type anything out. I definitely will plan out how to write a `test.cpp` file before just starting. 