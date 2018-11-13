#include "Graph.h"

using namespace std;




//Métodos relativos às arestas
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
int Edge::modifiyEdge(int a, int b, int c){
  v1 = a;
  v2 = b;
  w = c;
}

//Métodos para a implementação de Dijsktra


//Construtor e Destrutor
//TODO: Considerar caso de entradas de vértices negativos
Graph::Graph(int v){ //Construtor
    vertices = v;
    visited = new bool[v];
    adjMatrix.resize(vertices, vector<int>(vertices,0));
    for(int i=0; i<vertices;i++){//print de teste só pra ver se tamo safe
      visited[v] = false;
      for(int j=0; j<vertices; j++){
        cout << "Elemento"<< i << j << ":";
        cout  << " " << adjMatrix[i][j] <<" "<<endl;
      }
    }

    neighbors = 0;


  }
Graph::~Graph(){//Destrutor
  cout <<"Destrutor chamado";
    adjMatrix.clear();
  }


//Métodos de Manipulação da estrutura de dados
//TODO: Considerar caso de entradas de vértices negativos
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


//Algoritmos
Graph Graph::mst(int start){


  int current = start; // inicia a montagem da árvore pelo valor passado
  vector<int> mstBeen, mstLack;//estruturar para guardar os vértices percorridos, não percorridos
  Graph mst(vertices);
  for(int i = 0; i< vertices; i++){mstLack.push_back(i);} // inicialização dos não percorridos

  mstLack.erase(mstLack.begin()+start);//remove start dos não percorridos
  mstBeen.push_back(start);//inicialização dos percorridos


  Edge menorAresta(0,0,INT_MAX); //VALORES ARBITRÁTIOS PARA INICIALIZAR



  vector<int> vaux; //vetor auxiliar para receber os vértices da menor aresta, atributos privados da classe Edge
  while(!mstLack.empty()){ // fica preso infinitamente, precisa resolver

      //erro está muito provavelmente aqui
      for(int iterator = 0; iterator<mstBeen.size();iterator++){ // procura a menor aresta que sai do conjunto
        current = mstBeen.at(iterator); //passa por todos os vértices em que já esteve
        cout << "o vértcies que está sendo olhado " << current << endl;

        for(int j=0;j<vertices;j++){
          if(adjMatrix[current][j] == 0){
            cout<< "continue do peso igual a zero" << endl;
            continue;}
          if (find(mstBeen.begin(), mstBeen.end(), j) != mstBeen.end() ){//encontrou o valor de j(destino) nos vértices já percorridos e ignora
            cout<< "continue de j já dentro de been" << endl;
            continue;}
          if(adjMatrix[current][j] < menorAresta.getWeight()){
              menorAresta.modifiyEdge(current, j, adjMatrix.at(current).at(j));//coloca o valor da menor aresta encontrada no conjunto, saindo do atual até um destino j
              cout<< "Menor aresta atual, peso: "<< menorAresta.getWeight() << endl;
              cout<< "Origem :" << current<< "Destino :" << j << endl;
            }
          }

        }

        //Nesse momento, menorAresta contem a menor aresta que sai do conjunto

      vaux = menorAresta.getPoints();
      mstBeen.push_back(vaux.at(1)); //inclui nos vértices já visitados o vértice incluso

      for(int m = 0;   m<mstLack.size(); m++){//remove dos vertices que faltam o vértice incluso
          if(mstLack.at(m)==vaux.at(1)){
            mstLack.erase(mstLack.begin()+m);//lack nunca está esvaziando
            break;
          }

        }

        mst.insert(menorAresta);
        menorAresta.modifiyEdge(0,0,INT_MAX);
      }





      return mst;

}

vector<int> Graph::bfs(int start){
  vector<int> bfs;

  queue<int> queue; //lista de controle
  vector<int> adjacents;//vetor de adjacentes do vértice atual
	bool visited[vertices]; //vértices visitados
	bool explored[vertices][vertices]; //arestas exploradas

	visited[start] = true;//inicialização necessária
	queue.push(start);

	int current;
	int neighbor;

	while(!queue.empty()){
		current = queue.front();//pega o primeiro valor da fila para explorar os vizinhos

		queue.pop();// remove da fila
		bfs.push_back(current); // adiciona no vetor de retorno da busca


		for(int i = 0; i< vertices; i++){
			if(adjMatrix[current][i] != 0){

				adjacents.push_back(i);//conjunto dos vértices adjacentes ao vértices atual.
			}

		}
		while(!adjacents.empty()){

      neighbor = adjacents.back();//pega o vizinho do atual

      adjacents.pop_back();//remove o vizinho do conjunto de adjacentes para fins de loop
			if(visited[neighbor] == false){
			     explored[current][neighbor] = true;//Explora a aresta entre os dois nós.
				explored[neighbor][current] = true;
				queue.push(neighbor); // coloca o visinho na fila
				visited[neighbor] = true; // marca o visinho
			}
			else
				if(explored[current][neighbor] == false){
					explored[current][neighbor];
					explored[neighbor][current];
				}



		}

	}

	return bfs;
}

vector<int> Graph::dfs(int v){
  cout <<"welcome to the function " << endl;


    visited[v]=true;
    cout<<"visitados: " << endl;
    for(int t = 0; t<vertices; t++){
      cout<<visited[t] <<" ";
    }


    neighbors = 0;
    for(int k = 0; k<vertices; k++){ //encontrou os vizinhos do vértice V não marcados
      if(adjMatrix[v][k]!=0 && (!visited[k])){

        neighbors++;
      }
    }
    cout <<"numero de visinhos não marcados " << neighbors << endl;

    cout <<"Analisando o vértice" << v << endl;
    dfsVec.push_back(v);
    for(int i=0;i<vertices;i++){
      cout<<"ponto " << i << endl;
        if((!visited[i])&&(adjMatrix[v][i]!=0)){
          cout<< "Ponteiro da matriz " <<&adjMatrix[v][i] << endl;
          cout<< "Ponteiro de visitados " <<&visited[i] << endl;


          cout<<"Arvore construída ";
          for(int t = 0; t<dfsVec.size(); t++){
             cout<<dfsVec.at(t) <<" ";
          }
          cout << endl;
          cout <<"Chamada recursiva" << endl;

          this->dfs(i);

      }
    }


    if(dfsVec.size() == vertices){
      cout << "Entrou no retorno";
      vector<int> v = dfsVec;
      dfsVec.clear();
      return v;
    }
}









vector<int> Graph::dijkstra(int start, int end){

  int dt[vertices]; //vetor com os menores caminhos até o vértice de cada elemento
  int rot[vertices]; // vetor com o antecessor no menor caminho até ele
  vector<int> toReturn;
  //inicialização dos vetores acima
  dt[start] = 0;
  rot[start] = INT_MAX;
  for(int i = start+1; i<vertices; i++){
    dt[i] = INT_MAX;
    rot[i] = 0;
  }

  //ESTRUTURAS DE MARCAÇÃO
  bool open[vertices];//valores não olhados
  bool closed[vertices];//valores olhados


  int mindt = INT_MAX; //variável auxiliar para encontrar o menor dt
  int minVert; //variável auxiliar para guardar o menor vértice
  int whileCond = 0; // variável auxiliar para testar o while
  int minFinal; // variável auxiliar para decidir modificar o dt atual




  while (whileCond != vertices-start) {
    cout<< "Entrou no while" << endl;

    for(int j=start;j<vertices;j++){ //encontra o menor dt dentre os valores presentes em A.
      if(open[j] == false){ // j existe em open(considera-se falso por facilidade de incialização)
        if(mindt > dt[j]){
          mindt = dt[j];
          minVert = j;
        }
      }
    }
    cout<<"Encontrou o mínimo:" << mindt << " No vértice " << minVert << endl;

    open[minVert] = true; //removido de open
    closed[minVert] = true; //incluído em closed, true por facilidade de inicialização

    for(int k = start; k< vertices; k++){ //Examina todos os adjacentes que não estão em closed
			if((adjMatrix[minVert][k] != 0)&&(closed[k]==false)){
        minFinal = min(dt[k], dt[minVert]+adjMatrix[minVert][k]);
        if(minFinal < dt[k]){
          dt[k] = minFinal;
          rot[k] = minVert;
        }
			 }
  		}
      cout<<"Comparou o mínimo com o valor de dt/rot"<<endl;

    whileCond = 0;
    mindt = INT_MAX; //reset da variável de teste
    for(int l = start; l<vertices; l++){ //Condição para saída do while
      if(open[l]==true){
        cout<<"Incrementou whileCond"<<endl;
        whileCond++;
      }
    }

  }

  int aux = end;
  toReturn.push_back(aux);
  while(aux != start){
    aux = rot[aux];
    cout<<"Valor no rot " << aux << endl;
    toReturn.push_back(aux);

  }
  reverse(toReturn.begin(),toReturn.end());

  toReturn.push_back(dt[end]);
  return toReturn;

}
