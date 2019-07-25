#include "cassert"

#include "Graph.hpp"
#include "Vertex.hpp"

void test1(){
  Graph graph;
  graph.addVertex(0);
  graph.addVertex(1);
  graph.addVertex(2);
  graph.addEdge(0, 1);
  graph.addEdge(1, 2);
  graph.addEdge(2, 0);

  assert(graph.isCyclic() == true);
}

void test2(){
  Graph graph;
  graph.addVertex(0);
  graph.addVertex(1);
  graph.addVertex(2);
  graph.addEdge(0, 1);
  graph.addEdge(0, 2);
  graph.addEdge(1, 2);

  assert(graph.isCyclic() == false);
}

int main(){
  test1();
  test2();
  return 0;
}
