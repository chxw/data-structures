#ifndef VERTEX_HPP
#define VERTEX_HPP

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
  void setColor(Color color);
  void addEdge(Vertex* to);
  int getNumberOfAdjacentVertices() const;
  Vertex* getAdjacentVertexAt(int index) const;

private:
  //your design
};

#endif
