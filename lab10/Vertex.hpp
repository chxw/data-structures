#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <vector>
#include "Pair.hpp"

class Vertex{
public:
  Vertex();
  Vertex(int given_id);
  //  Vertex(const Vertex& other);
  //  Vertex& operator=(const Vertex& other);
  ~Vertex();

  int getID() const;
  void addOutgoingEdge(Pair<Vertex*, int>* edge);
  int getNumberOfOutgoingEdges() const;
  Pair<Vertex*, int>* getOutgoingEdgeAt(int index) const;
  int getDistance() const;
  void setDistance(int dist);
  Vertex* getPrevious() const;
  void setPrevious(Vertex* prev);

private:
  //your design
  int id;
  int num_edges;
  int distance;

  std::vector<Pair<Vertex*, int>*> edges;
  Vertex* previous;
};

#endif
