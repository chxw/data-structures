#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <string>
#include <vector>

#include "Vertex.hpp"
#include "Pair.hpp"

class Graph{
public:
  Graph();
  //  Graph(const Graph& other);
  //  Graph& operator=(const Graph& other);
  ~Graph();

  void addVertex(int id);
  void addEdge(int fromID, int toID, int weight);

  void setShortestPathsFrom(int startID);
  std::string getShortestPath(int fromID, int toID);

private:
  //your design
	std::vector<Vertex*> vertices;
	int num_vertices;
};

#endif
