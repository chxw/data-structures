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

N.A. (N.A.) *sizeof operator*. Retrieved from [https://en.cppreference.com/w/cpp/language/sizeof](ttps://en.cppreference.com/w/cpp/language/sizeof).

N.A. (N.A.) *Data Structures - Merge Sort Algorithm*. Retrieved from [https://www.tutorialspoint.com/data_structures_algorithms/merge_sort_algorithm.htm](https://www.tutorialspoint.com/data_structures_algorithms/merge_sort_algorithm.htm).

N.A. (N.A.) *Merge Sort*. Retrieved from [https://www.geeksforgeeks.org/merge-sort/](https://www.geeksforgeeks.org/merge-sort/).

N.A. (N.A.) *QuickSort*. Retrieved from [https://www.geeksforgeeks.org/quick-sort/](https://www.geeksforgeeks.org/quick-sort/).

N.A. (N.A.) *How Insertion Sort Works?*. Retrieved from [https://www.tutorialspoint.com/data_structures_algorithms/insertion_sort_algorithm.htm](https://www.tutorialspoint.com/data_structures_algorithms/insertion_sort_algorithm.htm).

John Zwinkc. (2014 March 22). *Is it possible to store 10 million numbers in array?*. Retrieved from [https://stackoverflow.com/questions/22578879/is-it-possible-to-store-10-million-numbers-in-array](https://stackoverflow.com/questions/22578879/is-it-possible-to-store-10-million-numbers-in-array).

aichao. (2016 July 5). *C++ insertion sort not working for large arrays*. Retrieved from [https://stackoverflow.com/questions/38193980/c-insertion-sort-not-working-for-large-arrays](https://stackoverflow.com/questions/38193980/c-insertion-sort-not-working-for-large-arrays).

Alex. (2019 April 23). *Enum classes*. Retrieved [https://www.learncpp.com/cpp-tutorial/4-5a-enum-classes/](https://www.learncpp.com/cpp-tutorial/4-5a-enum-classes/).

AlgoRythmics. (2011 April 23). *Merge-sort with Transylvanian-saxon (German) folk dance* [Video file]. Retrieved from [https://www.youtube.com/watch?v=XaqR3G_NVoo](https://www.youtube.com/watch?v=XaqR3G_NVoo).

AlgoRythmics. (2011 May 2). *Quick-sort with Hungarian (Küküllőmenti legényes) folk dance)*. [Video file]. Retrieved from [https://www.youtube.com/watch?v=ywWBy6J5gz8](https://www.youtube.com/watch?v=ywWBy6J5gz8).

Ankit Lathiya. (2019 April 30). *Merge Sort in C++ Tutorial With Example*. Retrieved from [https://appdividend.com/2019/04/30/merge-sort-in-cpp-tutorial-with-example-cpp-merge-sort-program/](https://appdividend.com/2019/04/30/merge-sort-in-cpp-tutorial-with-example-cpp-merge-sort-program/).

CSRocks. (2017 April 6). *Insertion Sort Explained in 2 Minutes*. Retrieved from [https://www.youtube.com/watch?v=pmDnM9gUxNc](https://www.youtube.com/watch?v=pmDnM9gUxNc).

dirkgently. (2010 August 30). *What is the behavior of integer division?*. Retrieved from [https://stackoverflow.com/questions/3602827/what-is-the-behavior-of-integer-division](https://stackoverflow.com/questions/3602827/what-is-the-behavior-of-integer-division).

Dylan Sallee.(2017 March 24). *mergeSort(): A Graphical, Recursive, C++ Explanation* [Video file]. Retrieved from [https://www.youtube.com/watch?v=RZK6KVpaT3I](https://www.youtube.com/watch?v=RZK6KVpaT3I).

KC Ang. (2014 October 16). *Quicksort: Partitioning an array*. [Video file]. Retrieved from [https://www.youtube.com/watch?v=MZaf_9IZCrc](https://www.youtube.com/watch?v=MZaf_9IZCrc).

RobEdwardsSDSU. (2016 December 6). *Sorts 8 Quick Sort*. [Video file]. Retrieved from [https://www.youtube.com/watch?v=ZHVk2blR45Q](https://www.youtube.com/watch?v=ZHVk2blR45Q).

rolfl. (2014 October 2). *Insert sort not working for large arrays*. Retrieved from [https://codereview.stackexchange.com/questions/64508/insert-sort-not-working-for-large-arrays](https://codereview.stackexchange.com/questions/64508/insert-sort-not-working-for-large-arrays).

Wikipedia contributors. (2019, June 11). *Insertion sort*. Retrieved from [https://en.wikipedia.org/wiki/Insertion_sort](https://en.wikipedia.org/wiki/Insertion_sort).

Wikipedia contributors. (2019, June 11). *Time complexity. In Wikipedia, The Free Encyclopedia*. Retrieved from [https://en.wikipedia.org/wiki/Time_complexity](https://en.wikipedia.org/wiki/Time_complexity).

Wikipedia contributors. (2019, June 11). *Merge sort. In Wikipedia, The Free Encyclopedia*. Retrieved from [https://en.wikipedia.org/wiki/Merge_sort](https://en.wikipedia.org/wiki/Merge_sort).

Wikipedia contributors. (2019, June 30). Quicksort. In Wikipedia, The Free Encyclopedia. Retrieved from [https://en.wikipedia.org/wiki/Quicksort](https://en.wikipedia.org/wiki/Quicksort).


## Post evaluation on planning:
This project was really difficult. I'd say it took me 3.5x more time than the first 2 projects. Fell behind schedule because the testing for the different sorting algorithms took way longer than planned (2/3+ days longer). Spent many a late night drawing out what's happening in the different sorting algorithms. Made multiple attempts/versions of the different sorts before finding a version that worked. I kept notes of all the versions that failed. Had to reference many resources to understand why what I implemented wasn't working. The sorting concepts itself and implementing them are less intuitive than I thought. A lot of bugs came down to not understanding the hedge cases or finding more hedge cases I hadn't thought of. (i.e. should pivot go to the left or right subarray? how to pivot and divide arrays of even vs. odd sizes? accidentally accessing outside of an array, but the bug only shows up in large N arrays). Wished I had more time for the report / time complexity analysis, but spent so much time debugging the sorting algorithms. Will definitely come back to this before the midterm.