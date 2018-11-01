#include <vector>
#include <iostream>

using namespace std;

class Edge{ // classe das arestas do grafo
int v1, v2;
int w;
public:
  Edge(int a, int b, int c){
    v1 = a;
    v2 = b;
    w = c;
  }
  vector<int> getPoints(){ // função de interfaceamento dos vértices da aresta
    return vector<int> v[2] = [v1,v2]; //** não sei se vai dar certo **
  }
  int getWeight(){// Função de interfaceamento do peso da aresta
    return w;
  }

};

class Graph{ // Classe do grafo
  int vertices;
  int edges;
  vector<vector<int>> adjMatrix;
public:
  Graph(int v){ //Construtor
    vertices = v;
    v.resize(vertices, vector<float>(vertices,0));
  }

  ~Graph(){//Destrutor
    adjMatrix.clear();
  }

  bool insert(const Edge& a){ // não sei se a passagem por referencia deixa chamar métodos dessa forma
    vector<int> v = a.getPoints(); //Não sei se vai dar certo
    //TODO: tratar fora do range o valor do vértice
    int w = a.getWeight();
    if(adjMatrix[v[0],v[1]]==0){ //caso a aresta exista, mas com peso diferente, altera o peso
      adjMatrix[v[0],v[1]] = w;
      adjMatrix[v[1],v[0]] = w;
      edges++;
      return true;
    }
    else
      return false;
  }

  bool remove(const Edge& a){
    vector<int> v = a.getPoints(); //Não sei se vai dar certo
    int w = a.getWeight();
    if(adjMatrix[v[0],v[1]]!=0){

    }


  }



  };
