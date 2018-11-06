#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
#include "Graph.h"

using namespace std;

int main(int argc, char const *argv[]) {

  Edge A(0,1,1);
  Edge B(0,2,3);
  Edge C(1,2,1);
  Edge D(1,2,1);
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

boulos.print();























  return 1;
}
