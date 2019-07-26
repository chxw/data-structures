#include "Graph.hpp"
#include "Vertex.hpp"
#include <iostream>

Graph::Graph(){

}

Graph::~Graph(){
	vertices.clear();
}

void Graph::addVertex(int id){
	Vertex v = Vertex(id);
	Vertex* vertex = &v;

	vertices.push_back(vertex);
}

void Graph::addEdge(int fromID, int toID){
	Vertex* to;

	for (size_t i = 0; i < vertices.size(); i++){
		if (vertices[i]->getID() == toID){
			to = vertices[i];
		}
	}

	for (size_t i = 0; i < vertices.size(); i++){
		if (vertices[i]->getID() == fromID){
			vertices[i]->addEdge(to);
		}
	}
}

bool Graph::isCyclic(){
	for (size_t i = 0; i < vertices.size(); i++){
		vertices[i]->setColor(Color::WHITE);
	}

	for (size_t i = 0; i < vertices.size(); i++){
		if (DFS(vertices[i])){
			return true;
		}
	}

	return false;
}

bool Graph::DFS(Vertex* v){
	v->setColor(Color::GRAY);
	for (int i = 0; v->getNumberOfAdjacentVertices(); i++){
		Vertex* adj = v->getAdjacentVertexAt(i);
		if (adj->getColor() == Color::WHITE){
			DFS(adj);
		}
		else if (adj->getColor() == Color::GRAY){
			return true;
		}
	}
	v->setColor(Color::BLACK);
	return false;
}
