#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
#include "Graph.h"

using namespace std;

int main(int argc, char const *argv[]) {

  Edge A(0,1,1);
  Edge B(0,2,1);
  Edge C(1,2,1);
  Edge D(2,3,1);
  Edge E(3,4,1);
  Edge F(2,4,1);
  Edge G(2,5,1);
  Edge H(2,6,1);







  Graph teste(7);//grafo com 3 vétices(0,1,2..6)
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

  vector<int> v = teste.bfs();
  for(int i = 0; i<7; i++){
    cout << v.at(i) << endl;
  }

























  return 1;
}
