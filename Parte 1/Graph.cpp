#include "Graph.h"

using namespace std;

Edge::Edge(int a, int b, int c){
  v1 = a;
  v2 = b;
  w = c;
}
vector<int> Edge::getPoints() const { // função de interfaceamento dos vértices da aresta

  vector<int> v;
  v.push_back(v1);
  v.push_back(v2);

  return v; //** não sei se vai dar certo **
}
int Edge::getWeight() const{// Função de interfaceamento do peso da aresta
  return w;
}

Graph::Graph(int v){ //Construtor
    vertices = v;
    adjMatrix.resize(vertices, vector<int>(vertices,0));
    for(int i=0; i<vertices;i++){//print de teste só pra ver se tamo safe
      for(int j=0; j<vertices; j++){
        cout << "Elemento"<< i << j << ":";
        cout  << " " << adjMatrix[i][j] <<" "<<endl;
      }
    }

  }
Graph::~Graph(){//Destrutor
  cout <<"Destrutor chamado";
    adjMatrix.clear();
  }

bool Graph::insert(const Edge& a){ // não sei se a passagem por referencia deixa chamar métodos dessa forma
    vector<int> v = a.getPoints(); //Não sei se vai dar certo

    //TODO: tratar fora do range o valor do vértice
    int w = a.getWeight();
    cout <<"Imprimindo as paradita" <<v[0] << " "<< v[1] << " ";
    cout<< w << endl;
    if ((v[0]> vertices) || (v[1]> vertices)){//verifica se tenta utilizar um vétice não presente no grafo
      cout<< "Vértice não está presente no grafo" << endl;
      return false;
    }
    if(v[0] == v[1]){
      cout << "Inserção inválida: vértice para ele mesmo" << endl;
      return false;
    }
    if(adjMatrix[v[0]][v[1]]!=w){ // nova aresta
      cout << "valor que ele quer tá testando:" << adjMatrix[v[0]][v[1]]<<endl;
      adjMatrix.at(v[0]).at(v[1]) = w;
      adjMatrix.at(v[1]).at(v[0]) = w;
      if(adjMatrix[v[0]][v[1]] == 0){
        edges++;}
      return true;
    }
    else //aresta já se econtra no grafo
    cout <<"aresta já está no grafo"<< endl;
          return false;
  }
bool Graph::remove(const Edge& a){
    vector<int> v = a.getPoints(); //Não sei se vai dar certo
    int w = a.getWeight();
    if ((v[0]> vertices) || (v[1]> vertices)){//verifica se tenta utilizar um vétice não presente no grafo
      cout<<"Vertice não presente no grafo" << endl;
      return false;
    }
    if(v[0] == v[1]){
      cout << "Remoção inválida: vértice para ele mesmo" << endl;
      return false;
    }
    if(adjMatrix[v[0]][v[1]]==w){
      adjMatrix.at(v[0]).at(v[1]) = 0;
      adjMatrix.at(v[1]).at(v[0]) = 0;
      edges--;
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
bool Graph::edge(const Edge& a){
    vector<int> v = a.getPoints(); //Não sei se vai dar certo
    int w = a.getWeight();
    if ((v[0]> vertices) || (v[1]> vertices)){//verifica se tenta utilizar um vétice não presente no grafo
      return false;
    }
    if(adjMatrix[v[0]][v[1]]!=w){
      return false;
    }
    else{
      return true;
    }



  }
bool Graph::isComplete(){
    for(int i = 0; i < vertices; i++){
      for(int j = 0; j < vertices; j++){
        if(i == j){continue;}
        if(adjMatrix[i][j]==0)
          return false;
      }
    }
    return true;
  }
void Graph::complete(){
    if(isComplete()){//caso o grafo já esteja completo, não faz nada
      return;
    }
    for(int i = 0; i < vertices; i++){
      for(int j = 0; j < vertices; j++){
        if(adjMatrix[i][j]==0){
          if(i == j){ continue;}
          adjMatrix.at(i).at(j) = 1;
        }
      }
    }


  }
void Graph::print(){//função para impressão da matriz de adjacência
  cout << endl;
  for(int i=0; i<vertices;i++){
    for(int j=0; j<vertices; j++){
      cout << adjMatrix[i][j] << " ";
    }
    cout << endl;
  }
  cout<<endl;
}
vector<int> Graph::mst(int start){
	

	
	
  int current = start; // inicia a montagem da árvore pelo valor passado
  vector<int> mstBeen, mstLack, mst;//estruturar para guardar os vértices percorridos, não percorridos e a árvore a ser retornada.
  for(int i = 0; i< vertices; i++){mstLack.push_back(i);} // inicialização dos não percorridos
  mstLack.erase(mst.begin()+start);
  mstBeen.push_back(start);//inicialização dos percorridos

  int edgeMin = INT_MAX ; //inteiro muito grande para fazer a comparação
  int aux = start;
  while(mstBeen != mstLack){

    while(aux<mstBeen.size(){//condição para andar por todos os valores de mstBeen) EStá errada pq aux não sabe "quem é" o vetor, itera sem saber o índice, em ordem crescente
      for(int j=0;j<vertices;j++){
        if(adjMatrix[current][j] == 0){continue;}
        if (find(mstBeen.begin(), mstBeen.end(), j) != mstBeen.end() ){//encontrou o valor de j nos vértices já percorridos
          continue;}
          edgeMin = min(adjMatrix.at(current).at(j), edgeMin); // encontra o menor valor das arestas
        }
    }




  }





}



vector<int> Graph::bfs(int start){
	
	queue<int> queue;
	bool visited[vetices];
	visited[start] = true;
	queue.push(start);
	
	while(queue != queue.empty(){
		
		
		
		
	}
	
	
	
	
	
	
}

