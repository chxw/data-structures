#include "cassert"

#include "Graph.hpp"
#include "Vertex.hpp"
#include <iostream>

void vertex_test(){
	Vertex v = Vertex(0);
	// Vertex* vptr = &v;

	Vertex e = Vertex(1);
	Vertex* eptr = &e;

	v.addEdge(eptr);
	v.setColor(Color::GRAY);
	for (int i = 0; i < v.getNumberOfAdjacentVertices(); i++){
		if (v.getAdjacentVertexAt(i)->getColor() == Color::WHITE){
			std::cout << "Adjacent Vertex white" << std::endl;
		}
	}
}

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

void test3(){
	Graph graph;
	graph.addVertex(0);
	graph.addVertex(1);
	graph.addVertex(2);
	graph.addVertex(3);
	graph.addVertex(4);
	graph.addVertex(5);

	graph.addEdge(0, 1);
	graph.addEdge(0, 2);
	graph.addEdge(1, 3);
	graph.addEdge(2, 4);
	graph.addEdge(4, 5);
	graph.addEdge(5, 2);

	assert(graph.isCyclic() == true);
}

void test4(){
	Graph graph;
	graph.addVertex(0);
	graph.addVertex(1);
	graph.addVertex(2);
	graph.addVertex(3);
	graph.addVertex(4);
	graph.addVertex(5);

	graph.addEdge(0, 1);
	graph.addEdge(0, 2);
	graph.addEdge(1, 3);
	graph.addEdge(2, 4);
	graph.addEdge(4, 5);

	assert(graph.isCyclic() == false);
}

void test5(){
	Graph graph;
	graph.addVertex(0);
	graph.addVertex(1);
	graph.addVertex(2);
	graph.addVertex(3);
	graph.addVertex(4);
	graph.addVertex(5);

	graph.addEdge(0, 1);
	graph.addEdge(1, 2);
	graph.addEdge(2, 3);
	graph.addEdge(3, 4);
	graph.addEdge(4, 5);

	assert(graph.isCyclic() == false);
}

void test6(){
	Graph graph;

	assert(graph.isCyclic() == false);
}

void test7(){
	Graph graph;

	graph.addVertex(0);
	graph.addVertex(1);

	assert(graph.isCyclic() == false);
}

int main(){
	// vertex_test();
  test1();
  test2();
  test3();
  test4();
  test5();
  test6();
  test7();
  return 0;
}
