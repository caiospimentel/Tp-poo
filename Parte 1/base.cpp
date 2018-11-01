#include <vector>
#include <iostream>

using namespace std;

class Edge{
int v1, v2;
int w;
public:
  Edge(int a, int b, int c){
    v1 = a;
    v2 = b;
    w = c;
  }
  vector<int> showPoints(){
    return vector<int> v[2] = [v1,v2];
  }
  int showWeight(){
    return int a = w;
  }

};

class Graph{
  int vertices;
  int edges;
  vector<vector<int>> adjMatrix;
public:
  Graph(int v){
    vertices = v;
    v.resize(vertices, vector<float>(vertices,0));
  }
  ~Graph(){
    adjMatrix.clear();
  }


};
