## Name:
Chelsea
## Date: 
07/26/19
## Summary:
An implementation of a graph using 2 classes: Graph and Vertex. The Graph class hold vertices in a vector (from STL) and has the ability to add directed edges between 2 vertices. The Graph class can check whether there exists a cycle in the graph. The Vertex class holds int id, int number of vertices, and enum class Color color. The enum class Color is used for detecting a cycle (Black = "done", White = "not visited", Gray = "visited"). The isCyclic() fcn in the Graph class is implemented using a depth-first search. This is the algorithm:

isCyclic():
1. For every vertex V in graph:
	- Set V to "not visited"
2. For every vertex V in graph:
	- If (DFS(V))
		- return true

DFS(v):
1. Mark v as "visited" 
2. For every adjacent vertex A of v
	- If A is "not visited"
		DFS(A)
	- Else if A is "visited" (not "done")
		return true (there is cycle)
3. Mark v as "done"

## Files:
`Graph.cpp Graph.hpp Vertex.cpp Vertex.hpp test.cpp`

## Instructions: 
`clang++ -std=c++11 -Wall -Wextra -O0 -g *.cpp -o test`
`./test`

## References:
- N.A. (N.A.). *std::vector*. Retrieved from [http://www.cplusplus.com/reference/vector/vector/](http://www.cplusplus.com/reference/vector/vector/).
- Alok Save. (3 October 2012). *Iterate through a C++ Vector using a 'for' loop*. Retrieved from [https://stackoverflow.com/questions/12702561/iterate-through-a-c-vector-using-a-for-loop](https://stackoverflow.com/questions/12702561/iterate-through-a-c-vector-using-a-for-loop).
- Petr. (21 July 2015). *Detecting a cycle in a directed graph using DFS?*. Retrieved from [https://stackoverflow.com/questions/31542031/detecting-a-cycle-in-a-directed-graph-using-dfs](https://stackoverflow.com/questions/31542031/detecting-a-cycle-in-a-directed-graph-using-dfs).