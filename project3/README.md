## Name:
Chelsea Wang

## Date:
6/30/2019

## Summary:
Sorter class contains 3 sorting algorithms: insertion sort, merge sort, and quick sort. The class has functionality for setting the Mode of the class to one of the 3 sorting algorithms. Mode is an enum class that contains 3 options for the various sorting algorithms. The default Mode for an instance of Sorter is insertion sort. It also has functionality for sorting with a given Mode. The `test.cpp` file tests the 3 sorting algorithms with arrays that are: already ordered, almost ordered, reverse ordered, randomly ordered, of large sizes, of odd sizes, and of even sizes.

**Insertion sort**: loops through array (going toward end) comparing side-by-side elements, if 2 elements need to be swapped, this triggers a helper function that traverses down the array (going toward beginning) comparing the swapped element with each element to find it's place in the array.

**Merge sort**: recursively divides array in 2 until it is no longer divisible. Then, begins to merge arrays together. It merges by comparing the first element of each array and putting the smaller of the 2 elements into a `merged` array and simultaneously removing that element from the subarray (as to not place duplicates into the `merged` array. It continues to do this until it's finished going up the queue created by dividing recursively.

**Quick sort**: recursively splits array by everything less than pivot and everything greater than pivot. Pivot is chosen using median-of-3 technique (choose median of array[0], array[mid], and array[size-1]) to improve time complexity. 

## Files:
`Sorter.cpp` `Sorter.hpp` `test.cpp`

## Instructions:
Run `clang++ -std=c++11 -Wall -Wextra -g Sorter.cpp Sorter.hpp test.cpp`.

## References:

## Post evaluation on planning:
Definitely a tough project. 

N.A. (N.A.) *sizeof operator*. Retrieved from [https://en.cppreference.com/w/cpp/language/sizeof](ttps://en.cppreference.com/w/cpp/language/sizeof).

dirkgently. (2010 August 30). *What is the behavior of integer division?*. Retrieved from [https://stackoverflow.com/questions/3602827/what-is-the-behavior-of-integer-division](https://stackoverflow.com/questions/3602827/what-is-the-behavior-of-integer-division).

John Zwinkc. (2014 March 22). *Is it possible to store 10 million numbers in array?*. Retrieved from [https://stackoverflow.com/questions/22578879/is-it-possible-to-store-10-million-numbers-in-array](https://stackoverflow.com/questions/22578879/is-it-possible-to-store-10-million-numbers-in-array).

Alex. (2019 April 23). *Enum classes*. Retrieved [https://www.learncpp.com/cpp-tutorial/4-5a-enum-classes/](https://www.learncpp.com/cpp-tutorial/4-5a-enum-classes/).

Wikipedia contributors. (2019, June 11). Time complexity. In Wikipedia, The Free Encyclopedia. Retrieved from [https://en.wikipedia.org/wiki/Time_complexity](https://en.wikipedia.org/wiki/Time_complexity).

https://en.wikipedia.org/wiki/Merge_sort
https://www.youtube.com/watch?v=XaqR3G_NVoo
https://www.youtube.com/watch?v=RZK6KVpaT3I
https://appdividend.com/2019/04/30/merge-sort-in-cpp-tutorial-with-example-cpp-merge-sort-program/
https://www.tutorialspoint.com/data_structures_algorithms/merge_sort_algorithm.htm
https://www.geeksforgeeks.org/merge-sort/

https://en.wikipedia.org/wiki/Quicksort
https://www.youtube.com/watch?v=ywWBy6J5gz8
https://www.youtube.com/watch?v=MZaf_9IZCrc
https://www.youtube.com/watch?v=ZHVk2blR45Q
https://www.geeksforgeeks.org/quick-sort/

https://en.wikipedia.org/wiki/Insertion_sort
https://www.youtube.com/watch?v=pmDnM9gUxNc
https://www.tutorialspoint.com/data_structures_algorithms/insertion_sort_algorithm.htm
https://codereview.stackexchange.com/questions/64508/insert-sort-not-working-for-large-arrays
https://stackoverflow.com/questions/38193980/c-insertion-sort-not-working-for-large-arrays