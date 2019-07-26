#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <vector>

enum class Color{
  WHITE,
  GRAY,
  BLACK,
  UNKNOWN
};

class Vertex{
public:
  //  Vertex();
  Vertex(int id);
  //  Vertex(const Vertex& other);
  //  Vertex& operator=(const Vertex& other);
  ~Vertex();

  int getID() const;
  Color getColor() const;
  void setColor(Color c);
  void addEdge(Vertex* to);
  int getNumberOfAdjacentVertices() const;
  Vertex* getAdjacentVertexAt(int index) const;

private:
  //your design
	int id;
	Color color;
	int num_vertices;
	std::vector<Vertex*> adjacent;
};

#endif
