#ifndef GRAPH_H
#define GRAPH_H


#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
#include <queue>


using namespace std;

class Edge{ // classe das arestas do grafo
  int v1, v2;
  int w;

  public:
  Edge(int a, int b, int c); //Construtor

  vector<int> getPoints() const; // Método para acessaros vértices da aresta
  int getWeight() const;// Método para acessar o peso da aresta
  int modifiyEdge(int a, int b, int c);//Método para modificar os atributos da aresta
};

class Graph{ // Classe do grafo
  int vertices;
  int edges;
  vector < vector < int > > adjMatrix;

  //esrtuturas para dfs
  bool * visited; //para dfs
  vector<int> dfsVec; // retorno de dfs
  int neighbors;


  public:

  Graph(int v); //Construtor
  ~Graph();//Destrutor


  bool insert(const Edge& a); //Método para adicionar uma aresta no grafo
  bool remove(const Edge& a); //Método para remover uma aresta do grafo
  int numberVertices(); //Método para acessar a quantidade de vértices
  int numberEdges(); //Método para acessar a quantidade de arestas
  bool edge(const Edge& A); //Método para verificar se uma aresta está presente num grafo
  bool isComplete(); //Método para testa se um grafo é completo
  void complete(); //Método para completar um grafo
  void print(); //função para impressão da matriz de adjacência
  Graph mst(int start = 0); //Método para criar uma árore geradora mínima para o grafo
  vector<int> bfs(); //Método para realizar a busca em largura no grafo
  vector<int> dfs(int v = 0); //Método para realizar a busca em proundidade no grafo
  void dfsAux(int v, bool ** explored, bool * visited, vector<int> &adjacents);
  vector<int> dijkstra(int start, int end); //Método para encontrar o menor caminho entre dois vértices pelo algoritmo de dijkstra
  vector<int> travSales(int start=0); //Método para resolver o problema do caixeiro viajante à partir de um vértice inicial

  };



#endif
