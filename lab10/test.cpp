#include <cassert>

#include "Graph.hpp"

void test1(){
  Graph graph;
  graph.addVertex(0);
  graph.addVertex(1);
  graph.addVertex(2);

  graph.addEdge(0, 1, 1);
  graph.addEdge(1, 2, 1);
  graph.addEdge(2, 0, 1);

 graph.setShortestPathsFrom(0);

 assert(graph.getShortestPath(0, 0) == "0 (0)");
//  assert(graph.getShortestPath(0, 1) == "0->1 (1)");
//  assert(graph.getShortestPath(0, 2) == "0->1->2 (2)");
}

void test2(){
  Graph graph;
  graph.addVertex(0);
  graph.addVertex(1);
  graph.addVertex(2);

  graph.addEdge(0, 1, 1);
  graph.addEdge(0, 2, 1);
  graph.addEdge(1, 2, 1);

//  graph.setShortestPathsFrom(0);

//  assert(graph.getShortestPath(0, 0) == "0 (0)");
//  assert(graph.getShortestPath(0, 1) == "0->1 (1)");
//  assert(graph.getShortestPath(0, 2) == "0->2 (1)");
}

void test3(){
  Graph graph;
  graph.addVertex(0);
  graph.addVertex(1);
  graph.addVertex(2);
  graph.addVertex(3);
  graph.addVertex(4);
  graph.addVertex(5);
  graph.addVertex(6);
  graph.addVertex(7);

  graph.addEdge(0, 1, 1);
  graph.addEdge(0, 2, 4);
  graph.addEdge(1, 3, 2);
  graph.addEdge(2, 4, 3);
  graph.addEdge(2, 5, 4);
  graph.addEdge(3, 7, 9);
  graph.addEdge(4, 6, 2);
  graph.addEdge(5, 4, 3);
  graph.addEdge(5, 6, 6);
  graph.addEdge(5, 7, 2);
  graph.addEdge(6, 7, 3);

//  graph.setShortestPathsFrom(0);

//  assert(graph.getShortestPath(0, 0) == "0 (0)");
//  assert(graph.getShortestPath(0, 1) == "0->1 (1)");
//  assert(graph.getShortestPath(0, 2) == "0->2 (4)");
//  assert(graph.getShortestPath(0, 3) == "0->1->3 (3)");
//  assert(graph.getShortestPath(0, 4) == "0->2->4 (7)");
//  assert(graph.getShortestPath(0, 5) == "0->2->5 (8)");
//  assert(graph.getShortestPath(0, 6) == "0->2->4->6 (9)");
//  assert(graph.getShortestPath(0, 7) == "0->2->5->7 (10)");
}

int main(){
  test1();
  test2();
  test3();
  return 0;
}
