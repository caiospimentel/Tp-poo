#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
#include "Graph.h"
#include <fstream>
#include <string.h>

using namespace std;

int main(int argc, char const *argv[]) {

ifstream in ("Grafo.txt");
string buff;
getline(in,buff);
Graph a(atoi(buff.c_str()));
string v1, v2, w;
do{

  in >> v1 >> v2 >> w;

  Edge aresta(atoi(v1.c_str()), atoi(v2.c_str()), atoi(w.c_str()));
  a.insert(aresta);

}while(getline(in,buff));
a.print();
in.close();

Edge p(2,3,53);
a.remove(p);

a.print();

a.insert(p);

int vertices = a.numberVertices();
cout << "Numero de vertices:" << vertices << endl;

int arestas = a.numberEdges();
cout <<"Numero de arestas:" << arestas << endl;

Edge k(1,1,1);
bool m;
if( m == a.edge(k)){
  cout << "A aresta esta presente" << endl;
}
else{
  cout << "A aresta não esta presente";
}

a.complete();

a.print();

cout << "Arvore geradora minima" << endl;
Graph mst = a.mst();

mst.print();
cout << "Busca em lagura" << endl;

vector<int> bfs = a.bfs();
for(int i = 0; i<bfs.size(); i++){
  cout << bfs.at(i)<<endl;
}

cout << "Busca em profundidade" << endl;

vector<int> dfs = a.dfs();

for(int i = 0; i<dfs.size(); i++){
  cout << dfs.at(i)<<endl;
}

cout << "Algoritmo de Dijkstra" << endl;

vector<int> dij = a.dijkstra(0,3);

for(int i = 0; i<dij.size(); i++){
  cout << dij.at(i)<<endl;
}

cout << "Problema do caixeiro viajante" << endl;

vector<int> tr = a.travSales();
for(int i = 0; i<tr.size(); i++){
  cout << tr.at(i)<<endl;
}

cout << "Componentes conexas" << endl;
 int componentes = a.connected();
 cout << "Numero de componentes conexas :" << componentes << endl;















return 1;
}
