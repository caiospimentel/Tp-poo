#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
#include "Graph.h"
#include <fstream>
#include <string.h>

using namespace std;

int main(int argc, char const *argv[]) {
/* main de teste do MST
  Edge A(0,1,1);
  Edge B(0,2,3);
  Edge C(1,2,1);
  Edge D(1,3,1);
  Edge E(1,4,4);
  Edge F(2,3,3);
  Edge G(2,4,2);
  Edge H(3,4,-2);
  Edge I(3,5,1);
  Edge J(4,5,2);







  Graph teste(6);//grafo com 3 vétices(0,1,2..6)
  cout << '\n';
  teste.insert(A);
  teste.insert(B);
  teste.insert(C);
  teste.insert(D);
  teste.insert(E);
  teste.insert(F);
  teste.insert(G);
  teste.insert(H);
  teste.insert(I);
  teste.insert(J);


  teste.print();



Graph boulos(6);

cout << "antes do mst";

boulos = teste.mst();

cout << "terras expropriadas";

boulos.print(); //teste bsf/dsf
*/
  Edge A(0,1,1);
  Edge B(0,2,1);
  Edge C(1,2,1);
  Edge D(2,3,1);
  Edge E(3,4,1);
  Edge F(2,4,1);
  Edge G(2,5,1);
  Edge H(2,6,1);







  Graph teste(7);
  cout << '\n';
  teste.insert(A);
  teste.insert(B);
  teste.insert(C);
  teste.insert(D);
  teste.insert(E);
  teste.insert(F);
  teste.insert(G);
  teste.insert(H);


  teste.print();

cout<<"antes de chamar dfs";
  vector<int> v = teste.dfs();

  for(int i = 0; i<7; i++){
    cout << v.at(i) << endl;
  }



/* //teste dijkstra

Graph teste(10);

Edge um(0,1,60);
Edge dois(0,2,54);
Edge tres(0,3,42);
Edge quatro(1,3,71);
Edge cinco(1,5,29);
Edge seis(2,3,56);
Edge sete(2,4,67);
Edge oito(3,4,26);
Edge nove(3,5,52);
Edge dez(3,6,87);
Edge onze(4,6,70);
Edge doze(4,8,73);
Edge faltou(5,6,20);
Edge treze(5,7,25);
Edge quatorze(6,7,36);
Edge quinze(6,8,59);
Edge dezesseis(6,9,32);
Edge dezessete(7,9,25);
Edge dezoito(8,9,26);

teste.insert(um);
teste.insert(dois);
teste.insert(tres);
teste.insert(quatro);
teste.insert(cinco);
teste.insert(seis);
teste.insert(sete);
teste.insert(oito);
teste.insert(nove);
teste.insert(dez);
teste.insert(onze);
teste.insert(doze);
teste.insert(treze);
teste.insert(quatorze);
teste.insert(quinze);
teste.insert(dezesseis);
teste.insert(dezessete);
teste.insert(dezoito);
teste.insert(faltou);


teste.print();

vector<int> v;
v = teste.dijkstra(0,9);

for(int i = 0; i<v.size(); i++){
  cout << v.at(i)<<endl;
}

cout<<endl;


*/

/*
//teste Caixeiro


Graph teste(4);



Edge A(0,1,10);
Edge B(0,2,15);
Edge C(0,3,20);
Edge D(1,2,35);
Edge E(1,3,25);
Edge F(2,3,30);

teste.insert(A);
teste.insert(B);
teste.insert(C);
teste.insert(D);
teste.insert(E);
teste.insert(F);

teste.print();

vector<int> v;
cout <<"Chanou caixeiro" << endl;
v = teste.travSales(3);
for(int i = 0; i<v.size(); i++){
  cout << v.at(i)<<endl;
}




*/



/*

ifstream in ("Grafo.txt");
string buff;
getline(in,buff);
Graph a(atoi(buff.c_str()));
string v1, v2, w;
do{

  in >> v1 >> v2 >> w;
  cout << w << endl;

  Edge aresta(atoi(v1.c_str()), atoi(v2.c_str()), atoi(w.c_str()));
  a.insert(aresta);

}while(getline(in,buff));
a.print();
in.close();

Edge p(2,3,30);
a.remove(p);

a.print();

a.insert(p);

int vertices = a.numberVertices();
cout << "Número de vértices:" << vertices << endl;

int arestas = a.numberEdges();
cout <<"Número de arestas:" << arestas << endl;

Edge k(1,1,1);
bool m;
if( m == a.edge(k)){
  cout << "A aresta está presente" << endl;
}
else{
  cout << "A aresta não está presente";
}

a.complete();

a.print();

cout << "Árvore geradora mínima" << endl;
Graph mst = a.mst();

mst.print();
cout << "Busca em lagura" << endl;

vector<int> bfs = a.bfs();
for(int i = 0; i<bfs.size(); i++){
  cout << bfs.at(i)<<endl;
}

cout << "Busca em profundidade" << endl;

/*vector<int> dsf = a.dsf();

for(int i = 0; i<dsf.size(); i++){
  cout << dsf.at(i)<<endl;
} 

cout << "Algoritmo de Dijktra" << endl;

vector<int> dij = a.dijkstra(0,3);

for(int i = 0; i<dij.size(); i++){
  cout << dij.at(i)<<endl;
}

cout << "Problema do caixeiro viajante" << endl;

vector<int> tr = a.travSales();
for(int i = 0; i<tr.size(); i++){
  cout << tr.at(i)<<endl;
}

*/















return 1;
}
