#include <climits>
#include <stdexcept>
#include <string>
#include <vector>

#include "Graph.hpp"
#include "Vertex.hpp"
#include "Pair.hpp"
#include "MinHeap.hpp"

Graph::Graph(){
	num_vertices = 0;
}

//  Graph(const Graph& other);
//  Graph& operator=(const Graph& other);

Graph::~Graph(){

}

void Graph::addVertex(int id){
	Vertex* newbie = new Vertex(id);
	vertices.push_back(newbie);
	num_vertices++;
}

void Graph::addEdge(int fromID, int toID, int weight){
	Vertex* to;

	for (size_t i = 0; i < vertices.size(); i++){
		if (vertices[i]->getID() == toID){
			to = vertices[i];
		}
	}

	for (size_t i = 0; i < vertices.size(); i++){
		if (vertices[i]->getID() == fromID){
			Pair<Vertex*, int>* edge = new Pair<Vertex*, int>(to, weight);
			vertices[i]->addOutgoingEdge(edge);	
		}
	}
}

void Graph::setShortestPathsFrom(int startID){

}

std::string Graph::getShortestPath(int fromID, int toID){
	return "";
}