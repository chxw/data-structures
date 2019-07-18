## Name:
Chelsea 

## Date:
07/18/19

## Summary:
Write a function that generates a hash code, which, in this case, serves as the index in the array to add a value. 

## Files:
`hasher.cpp hasher.hpp HashTable.o Item.o LinkedList.o main.o SLLNode.o`

## Instructions:
`clang++ -std=c++11 hasher.cpp *.o`
`./a.out`
After running executable, program waits for input either from standard input (typing) or redirection. The executable will take lines of words until it is presented with empty line.

## References:
Prof. Shibata and TA Matt

## Score: 
2252

The best possible score would be 30?

## Strategy: 
I tried assigning each letter to an int value, so that each word is the sum of a sequence of int values. I thought this would create different sums (hashcodes) for different words. But I think in reality, it is more common for words that are totally different to have a sequence of letters that can equate the same thing. Ex: not specific to my example, but say a = 1, b = 2, e = 5, l = 12. babel = 22.  m = 13, a = 1, h = 8. mah = 22. 
