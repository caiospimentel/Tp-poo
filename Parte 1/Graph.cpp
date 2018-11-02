#include "Graph.h"

using namespace std;

Edge::Edge(int a, int b, int c){
  v1 = a;
  v2 = b;
  w = c;
}
vector<int> Edge::getPoints(){ // função de interfaceamento dos vértices da aresta
  return vector<int> v[2] = [v1,v2]; //** não sei se vai dar certo **
}
int Edge::getWeight(){// Função de interfaceamento do peso da aresta
  return w;
}



Graph::Graph(int v){ //Construtor
    vertices = v;
    v.resize(vertices, vector<float>(vertices,0));
  }
Graph::~Graph(){//Destrutor
    adjMatrix.clear();
  }

bool Graph::insert(const Edge& a){ // não sei se a passagem por referencia deixa chamar métodos dessa forma
    vector<int> v = a.getPoints(); //Não sei se vai dar certo
    //TODO: tratar fora do range o valor do vértice
    int w = a.getWeight();
    if ((v[0]> vetices) || (v[1]> vetices)){//verifica se tenta utilizar um vétice não presente no grafo
      return false;
    }
    if(adjMatrix[v[0],v[1]]==0){ // nova aresta
      adjMatrix[v[0],v[1]] = w;
      adjMatrix[v[1],v[0]] = w;
      edges++;
      return true;
    }
    else if(adjMatrix[v[0],v[1]]!=w){//alteração do peso da aresta presente no grafo
      adjMatrix[v[0],v[1]] = w;
      adjMatrix[v[1],v[0]] = w;
      return true;
    }
else //aresta já se econtra no grafo
      return false;
  }
bool Graph::remove(const Edge& a){
    vector<int> v = a.getPoints(); //Não sei se vai dar certo
    int w = a.getWeight();
    if ((v[0]> vetices) || (v[1]> vetices)){//verifica se tenta utilizar um vétice não presente no grafo
      return false;
    }
    if(adjMatrix[v[0],v[1]]==w){
      adjMatrix[v[0],v[1]] = 0;
      adjMatrix[v[1],v[0]] = 0;
      egdes--;
      return true;
    }
    else
      return false;
  }
int Graph::numberVertices(){
    return vertices;
  }
int Graph::numberEdges(){
    return edges;
  }
bool Graph::edge(const Edge& A){
    vector<int> v = a.getPoints(); //Não sei se vai dar certo
    int w = a.getWeight();
    if ((v[0]> vetices) || (v[1]> vetices)){//verifica se tenta utilizar um vétice não presente no grafo
      return false;
    }
    if(adjMatrix[v[0],v[1]]!=w){
      return false;
    }
    else{
      return true;
    }



  }
bool Graph::isComplete(){
    for(int i = 0; i < vetices; i++){
      for(int j = 0; j < vertices; j++){
        if(adjMatrix[i][j]==0)
          return false;
      }
    }
    return true;
  }
void Graph::complete(){
    if(isComplete){
      return;
    }
    for(int i = 0; i < vetices; i++){
      for(int j = 0; j < vertices; j++){
        if(adjMatrix[i][j]==0)
          adjMatrix[i][j]==1;
      }
    }


  }
void Graph::print(){
  for(int i=0; i<vetices;i++){
    for(int j=0; j<vetices; j++){
      cout << adjMatrix[i][j];
    }
    cout << endl;
  }

}
