#include "Vertex.hpp"

Vertex::Vertex(int given_id){
	id = given_id;
	color = Color::WHITE;
	num_vertices = 0;
}

Vertex::~Vertex(){
	adjacent.clear();
}

int Vertex::getID() const{
	return id;
}

Color Vertex::getColor() const{
	return color;
}

void Vertex::setColor(Color c){
	color = c;
}

void Vertex::addEdge(Vertex* to){
	adjacent.push_back(to);
	num_vertices++;
}

int Vertex::getNumberOfAdjacentVertices() const{
	return num_vertices;
}

Vertex* Vertex::getAdjacentVertexAt(int index) const{
	return adjacent[index];
}