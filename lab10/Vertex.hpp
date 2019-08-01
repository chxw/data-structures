#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <vector>
#include "Pair.hpp"

class Vertex{
public:
  Vertex();
  Vertex(int id);
  //  Vertex(const Vertex& other);
  //  Vertex& operator=(const Vertex& other);
  ~Vertex();

  int getID() const;
  void addOutgoingEdge(Pair<Vertex*, int>* edge);
  int getNumberOfOutgoingEdges() const;
  Pair<Vertex*, int>* getOutgoingEdgeAt(int index) const;
  int getDistance() const;
  void setDistance(int distance);
  Vertex* getPrevious() const;
  void setPrevious(Vertex* previous);

private:
  //your design
};

#endif
