#ifndef GRAPH_H
#define GRAPH_H


#include <vector>
#include <iostream>

using namespace std;

class Edge{ // classe das arestas do grafo
int v1, v2;
int w;
public:
  Edge(int a, int b, int c);
  vector<int> getPoints() const; // função de interfaceamento dos vértices da aresta
  int getWeight() const;// Função de interfaceamento do peso da aresta
};


class Graph{ // Classe do grafo
  int vertices;
  int edges;
  vector < vector < int > > adjMatrix;
public:

  Graph(int v); //Construtor
  ~Graph();//Destrutor


  bool insert(const Edge& a); // não sei se a passagem por referencia deixa chamar métodos dessa forma
  bool remove(const Edge& a);
  int numberVertices();
  int numberEdges();
  bool edge(const Edge& A);
  bool isComplete();
  void complete();
  void print();


  };

#endif
