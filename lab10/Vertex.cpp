#include <vector>

#include "Vertex.hpp"
#include "Pair.hpp"

Vertex::Vertex(){
	id = 0;
	num_edges = 0;
}

Vertex::Vertex(int given_id){
	id = given_id;
	num_edges = 0;
}

Vertex::~Vertex(){
	edges.clear();
}

int Vertex::getID() const{
	return id;
}

void Vertex::addOutgoingEdge(Pair<Vertex*, int>* edge){
	edges.push_back(edge);
	num_edges++;
}

int Vertex::getNumberOfOutgoingEdges() const{
	return num_edges;
}

Pair<Vertex*, int>* Vertex::getOutgoingEdgeAt(int index) const{
	return edges[index];
}

int Vertex::getDistance() const{
	return distance;
}

void Vertex::setDistance(int dist){
	distance = dist;
}

Vertex* Vertex::getPrevious() const{
	return previous;
}

void Vertex::setPrevious(Vertex* prev){
	previous = prev;
}