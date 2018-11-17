#include "Graph.h"

using namespace std;

//Métodos relativos às arestas
Edge::Edge(int a, int b, int c){//Construtor
  if(b<a){ //caso o segundo vértice seja menor que o primeiro, coloca ele antes na aresta
    v1 = b;
    v2 = a;
  }
  else{ //caso contrário, adiciona os vértices em ordem
    v1 = a;
    v2 = b;
  }
  w = c;
} //Construtor
vector<int> Edge::getPoints() const { // Método para acessaros vértices da aresta
  vector<int> v;
  v.push_back(v1);
  v.push_back(v2);
  return v;
}
int Edge::getWeight() const{// Método para acessar o peso da aresta
  return w;
}
int Edge::modifiyEdge(int a, int b, int c){//Método para modificar os atributos da aresta
  v1 = a;
  v2 = b;
  w = c;
}

//Construtor e Destrutor
Graph::Graph(int v){ //Construtor
  if(v<=0){ //caso o número de vértices não seja um inteiro maior que zero
    cout << "Quantidade de vértices invalida" << endl;
    return;
  }
    vertices = v;
    visited = new bool[v];
    adjMatrix.resize(vertices, vector<int>(vertices,0)); //Inicialização da matriz de adjacência com zeros
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
    adjMatrix.clear(); //limpeza de memória
  }

//Métodos de Manipulação da estrutura de dados
bool Graph::insert(const Edge& a){//Método para adicionar uma aresta no grafo

    vector<int> v = a.getPoints(); // vetor v recebe os vértices inicial e final da areata
    int w = a.getWeight(); // w receve o peso da aresta

    if ((v[0]> vertices) || (v[1]> vertices)){//verifica se colocar uma aresta num vértice não presente no grafo
      cout<< "Vértice não está presente no grafo" << endl;
      return false;
    }
    if(v[0] == v[1]){//Verifica se tenta inserir um auto-ciclo, não permitido
      cout << "Inserção inválida: vértice para ele mesmo" << endl;
      return false;
    }
    if(adjMatrix[v[0]][v[1]]!=w){ // nova aresta
      //altera os valores na matriz de adjacencia de forma simétrica
      adjMatrix.at(v[0]).at(v[1]) = w;
      adjMatrix.at(v[1]).at(v[0]) = w;

      if(adjMatrix[v[0]][v[1]] == 0){//caso seja uma aresta nova, não somente uma alteração de peso, incrementa a quantidade de arestas
        edges++;}
      return true;
    }
    else{ //aresta já se econtra no grafo
      return false;
    }
  }
bool Graph::remove(const Edge& a){//Método para remover uma aresta do grafo
    vector<int> v = a.getPoints(); // vetor v recebe os vértices inicial e final da areata
    int w = a.getWeight(); // w receve o peso da aresta
    if ((v[0]> vertices) || (v[1]> vertices)){//verifica se tenta utilizar um vétice não presente no grafo
      cout<<"Vertice não presente no grafo" << endl;
      return false;
    }
    if(v[0] == v[1]){ //tenta remover um auto-ciclo, sempre inexistente
      cout << "Remoção inválida: vértice para ele mesmo" << endl;
      return false;
    }
    if(adjMatrix[v[0]][v[1]]==w){
      //coloca zero simetricamente na matriz de adjacencia
      adjMatrix.at(v[0]).at(v[1]) = 0;
      adjMatrix.at(v[1]).at(v[0]) = 0;
      edges--; //decrementa a quantidade de arestas
      return true;
    }
    else{ //aresta não se encontra no grafo
      return false;
    }
  }
int Graph::numberVertices(){//Método para acessar a quantidade de vértices
    return vertices;
  }
int Graph::numberEdges(){//Método para acessar a quantidade de arestas
    return edges;
  }
bool Graph::edge(const Edge& a){ //Método para verificar se uma aresta está presente num grafo
    vector<int> v = a.getPoints(); // vetor v recebe os vértices inicial e final da areata
    int w = a.getWeight();// w receve o peso da aresta
    if ((v[0]> vertices) || (v[1]> vertices)){//verifica se tenta utilizar um vértice não presente no grafo
      return false;
    }
    if(adjMatrix[v[0]][v[1]]!=w){ // caso o peso seja diferente de w, a aresta não está presente
      return false;
    }
    else{ // se o peso é igual a w, a aresta está presente
      return true;
    }



  }
bool Graph::isComplete(){//Método para testa se um grafo é completo
  //percorre a matriz de adjacencia
    for(int i = 0; i < vertices; i++){
      for(int j = 0; j < vertices; j++){
        if(i == j){continue;} //para todos os valores em que i==j, está num vétice, o peso deve sempre ser zero
        if(adjMatrix[i][j]==0) //quando o peso é zero, significa que não há aresta, logo, o grafo não é completo
          return false;
      }
    }
    return true; // caso percorra toda a matriz sem encontrar zeros em i!=j, o grafo é completo
  }
void Graph::complete(){ //Método para completar um grafo
    if(isComplete()){//caso o grafo já esteja completo, não faz nada
      return;
    }
    //percorre a matriz de adjacencia
    for(int i = 0; i < vertices; i++){
      for(int j = 0; j < vertices; j++){
        if(adjMatrix[i][j]==0){ //caso não exista aresta, coloca 1, assume-se uma aresta de valor mínimo
          if(i == j){ continue;} //para todos os valores em que i==j, está num vétice, o peso deve sempre ser zero
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
Graph Graph::mst(int start){ //Método para criar uma árore geradora mínima para o grafo

  int current = start; // inicia a montagem da árvore pelo valor passado
  vector<int> mstBeen, mstLack;//estruturar para guardar os vértices percorridos, não percorridos
  Graph mst(vertices);//grafo a ser retornado como a árvore geradora mínima
  for(int i = 0; i< vertices; i++){mstLack.push_back(i);} // inicialização dos não percorridos

  mstLack.erase(mstLack.begin()+start);//remove start dos não percorridos
  mstBeen.push_back(start);//inicialização dos percorridos


  Edge menorAresta(0,0,INT_MAX); //Valores arbitrários para inicialização e inteiro máximo para a comparação funcionar

  vector<int> vaux; //vetor auxiliar para receber os vértices da menor aresta, atributos privados da classe Edge
  while(!mstLack.empty()){ // fica preso infinitamente, precisa resolver

      for(int iterator = 0; iterator<mstBeen.size();iterator++){ // procura a menor aresta que sai do conjunto
        current = mstBeen.at(iterator); //passa por todos os vértices em que já esteve
        cout << "o vértcies que está sendo olhado " << current << endl;

        for(int j=0;j<vertices;j++){
          if(adjMatrix[current][j] == 0){ //caso o peso seja igual a zero, não há aresta
            cout<< "continue do peso igual a zero" << endl;
            continue;}
          if (find(mstBeen.begin(), mstBeen.end(), j) != mstBeen.end() ){//encontrou o valor de j(destino) nos vértices já percorridos e ignora
            cout<< "continue de j já dentro de been" << endl;
            continue;}
          if(adjMatrix[current][j] < menorAresta.getWeight()){ // caso o valor atual seja menor que o salvo na menor aresta
              menorAresta.modifiyEdge(current, j, adjMatrix.at(current).at(j));//coloca o valor da menor aresta encontrada no conjunto, saindo do atual até um destino j
              cout<< "Menor aresta atual, peso: "<< menorAresta.getWeight() << endl;
              cout<< "Origem :" << current<< "Destino :" << j << endl;
            }
          }

        }

        //Nesse momento, menorAresta contem a menor aresta que sai do conjunto

      vaux = menorAresta.getPoints(); // utiliza o vetor auxiliar para receber os vértices da menor aresta
      mstBeen.push_back(vaux.at(1)); //inclui nos vértices já visitados o vértice incluso

      for(int m = 0; m<mstLack.size(); m++){//remove dos vertices que faltam o vértice incluso
          if(mstLack.at(m)==vaux.at(1)){
            mstLack.erase(mstLack.begin()+m);
            break;
          }
        }
        mst.insert(menorAresta); //insere a menor aresta na árvore mínima
        menorAresta.modifiyEdge(0,0,INT_MAX);//reseta o valor da menor aresta para que possa ser feita a comparação novamente no novo loop do while
      }

      return mst;
}
vector<int> Graph::bfs(){ //Método para realizar a busca em largura no grafo
  int start = 0;
  vector<int> bfs; // vetor que retorna a busca em largura
  queue<int> queue; //lista de controle
  vector<int> adjacents;//vetor de adjacentes do vértice atual
	bool visited[vertices]; //vértices visitados
	bool explored[vertices][vertices]; //arestas exploradas

	visited[start] = true;//inicialização necessária
	queue.push(start);

  //estruturas para guardar o valor atual e seu vizinho
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

		while(!adjacents.empty()){//enquanto existirem viz
      neighbor = adjacents.back();//pega o vizinho do atual
      adjacents.pop_back();//remove o vizinho do conjunto de adjacentes para fins de loop
			if(visited[neighbor] == false){
			     explored[current][neighbor] = true;//Explora a aresta entre os dois nós.
				explored[neighbor][current] = true;
				queue.push(neighbor); // coloca o visinho na fila
				visited[neighbor] = true; // marca o visinho
			}
			else //caso o visinho esteja explorado
				if(explored[current][neighbor] == false){ //mas a aresta não
          //explora a aresta simetricamente
					explored[current][neighbor];
					explored[neighbor][current];
				}
		}
	}
	return bfs; //retorna o vetor com os vértices na ordem da busca
}
vector<int> Graph::dfs(int v){//Método para realizar a busca em proundidade no grafo
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


    if(dfsVec.size() == vertices && v == *dfsVec.begin()){
      cout << "Entrou no retorno";
      vector<int> v = dfsVec;
      
      return v;
    }
}
vector<int> Graph::dijkstra(int start, int end){ //Método para encontrar o menor caminho entre dois vértices pelo algoritmo de dijkstra
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
        if(mindt > dt[j]){ //caso o menor seja maior que o atual, salva o atual como menor
          mindt = dt[j];
          minVert = j; // guarda o vértice do menor
        }
      }
    }
    cout<<"Encontrou o mínimo:" << mindt << " No vértice " << minVert << endl;

    open[minVert] = true; //removido de open
    closed[minVert] = true; //incluído em closed, true por facilidade de inicialização

    for(int k = start; k< vertices; k++){ //Examina todos os adjacentes que não estão em closed
			if((adjMatrix[minVert][k] != 0)&&(closed[k]==false)){
        minFinal = min(dt[k], dt[minVert]+adjMatrix[minVert][k]); //compara o valor do caminho direto com o valor do menor caminho+menor caminho até o atual
        if(minFinal < dt[k]){
          dt[k] = minFinal;
          rot[k] = minVert;
        }
			 }
  		}
      cout<<"Comparou o mínimo com o valor de dt/rot"<<endl;

    whileCond = 0; // reset da variável de teste do while
    mindt = INT_MAX; //reset da variável de teste
    for(int l = start; l<vertices; l++){ //Condição para saída do while
      if(open[l]==true){
        cout<<"Incrementou whileCond"<<endl;
        whileCond++;
      }
    }
  }

  //preenchimento do vetor de retorno
  int aux = end;
  toReturn.push_back(aux);
  while(aux != start){
    aux = rot[aux];
    cout<<"Valor no rot " << aux << endl;
    toReturn.push_back(aux);
  }
  reverse(toReturn.begin(),toReturn.end()); //coloca os valores dos vértices em ordem crescente
  toReturn.push_back(dt[end]); //adiciona o comprimento do caminho no final do vetor
  return toReturn;
}
vector<int> Graph::travSales(int start){ //Método para resolver o problema do caixeiro viajante à partir de um vértice inicial
  //completa o grafo caso ele não seja completo
  this->complete();



  vector<int> vert; //Vértices a serem olhados
  vector<int> path; //Menor caminho atual
  vector<int> minPath; //Menor caminho global

  for(int i = 0; i<vertices; i++){ //coloca todos os vértices menos o inicial no vetor
    if(i != start){
      vert.push_back(i);
    }
  }

  int minRt= INT_MAX; //cria uma variável de teste para a menor rota(soma dos pesos) inicializada com o maior inteirom  para comparação
  int currentRt;
  int next;

  do {
        currentRt = 0; // rota atual;
        path.clear(); //limpa o caminho atual

        next = start; //inicializa o próximo com o inicial para começar a passar pelo grafo
        path.push_back(start); // coloca no caminho o inicial
        for (int i = 0; i < vert.size(); i++) { //percorre os vértices

            currentRt = currentRt + adjMatrix[next][vert[i]]; //adiciona a rota atual percorrendo a matriz de adjacencia
            next = vert.at(i); // coloca o pŕoximo valor da matriz em next
            path.push_back(next); // adiciona o vértice no caminho
        }
        currentRt = currentRt + adjMatrix[next][start]; // adiciona na rota a distância do ponto final ao inicial
        path.push_back(start); // coloca o inicial no caminho após completar a volta



        if(minRt > currentRt){ //caso a rota calculada seja menor que a salva, troca
          cout <<" minimo maior que o atual" << endl;
          minRt = currentRt;
          minPath = path;

        }


    } while (next_permutation(vert.begin(), vert.end())); //modifica o vetor de vertices para serem observadas todas as suas permutações, olhando toda as combinações possíveis de vértices


    minPath.push_back(minRt); //coloca no final do vetor de caminho mínimo a rota mínima
    return minPath; // retorna a solução do probl


}
