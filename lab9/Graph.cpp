#include "Graph.hpp"
#include "Vertex.hpp"
#include <iostream>

Graph::Graph(){

}

Graph::~Graph(){
}

void Graph::addVertex(int id){
	Vertex v = Vertex(id);
	Vertex* vertex = &v;

	vertices.push_back(vertex);
}

void Graph::addEdge(int fromID, int toID){
	Vertex* to;

	for (int i = 0; i < vertices.size(); i++){
		if (vertices[i]->getID() == toID){
			to = vertices[i];
		}
	}

	for (int i = 0; i < vertices.size(); i++){
		if (vertices[i]->getID() == fromID){
			vertices[i]->addEdge(to);
		}
	}
}

bool Graph::isCyclic(){
	bool result = false;

	std::stack<Vertex*> dfs;

	for (int i = 0; i < vertices.size(); i++){
		if (isCyclicUtil(vertices[i], dfs)){
			result = true;
		}
	}

	return result;
}

bool Graph::isCyclicUtil(Vertex* vertex, std::stack<Vertex*> &dfs){
	// no vertices 
	if (vertex->getNumberOfAdjacentVertices() == 0){
		vertex->setColor(Color::BLACK);
		if (!dfs.empty()){
			dfs.pop();
			isCyclicUtil(dfs.top(), dfs);
		}
	}
	// not visited
	else if (vertex->getColor() == Color::WHITE){
		dfs.push(vertex);
		vertex->setColor(Color::GRAY);

		for (int i = 0; i < vertex->getNumberOfAdjacentVertices(); i++){
			Vertex* adj = vertex->getAdjacentVertexAt(i);
			if (adj->getColor() != Color::WHITE){
				std::cout << "if (adj->getColor() != Color::WHITE) " << std::endl;
				return true;
			}

			dfs.push(adj);
			adj->setColor(Color::GRAY);
			if (!dfs.empty()){
				isCyclicUtil(dfs.top(), dfs);
			}
		}
		return false;
	}
	return false;
}