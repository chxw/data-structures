#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "Vertex.hpp"
#include <stack>
#include <queue>

class Graph{
public:
  Graph();
  //  Graph(const Graph& other);
  //  Graph& operator=(const Graph& other);
  ~Graph();

  void addVertex(int id);
  void addEdge(int fromID, int toID);

  bool isCyclic();

private:
  //your design
	std::vector <Vertex*> vertices;

	bool DFS(Vertex* v);
};

#endif
