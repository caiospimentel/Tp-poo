#include <vector>
#include <iostream>
#include "Graph.h"

using namespace std;

int main(int argc, char const *argv[]) {

  Edge A(2,1,3);//passa vértice 0,1, peso 1
  Graph teste(3);//grafo com 3 vétices(0,1,2)

  teste.insert(A);

  teste.print();

  teste.insert(A);

  bool a = teste.isComplete();
  cout <<"Completo?:"<< a << endl;
  Edge C(1,0,1);
  a = teste.edge(A);
  cout<<"Tem aresta A:" << a << endl;

  teste.complete();

  teste.complete();

  teste.print();

  Edge B(2,0,1);

  teste.remove(B);

  teste.print();






















  return 1;
}
