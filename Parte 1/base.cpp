#include <vector>
#include <iostream>
#include "Graph.h"

using namespace std;

int main(int argc, char const *argv[]) {

  Edge A(0,1,1);//passa vértice 0,1, peso 1
  Graph teste(3);//grafo com 3 vétices(0,1,2)

  teste.print();

  teste.insert(A);
  teste.print();
















  return 1;
}
