#include "Graph.h"

using namespace std;

//Métodos relativos às arestas
Edge::Edge(int a, int b, int c){//Construtor
  if(b<a){ //caso o segundo vertice seja menor que o primeiro, coloca ele antes na aresta
    v1 = b;
    v2 = a;
  }
  else{ //caso contrário, adiciona os vertices em ordem
    v1 = a;
    v2 = b;
  }
  w = c;
}
vector<int> Edge::getPoints() const { // Método para acessaros vertices da aresta
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
  if(v<=0){ //caso o número de vertices nao seja um inteiro maior que zero
    cout << "Quantidade de vertices invalida" << endl;
    return;
  }
    vertices = v;
    edges = 0;
    visited = new bool[v];
    adjMatrix.resize(vertices, vector<int>(vertices,0)); //Inicializaçao da matriz de adjacência com zeros
    for(int i=0; i<vertices;i++){//print de teste só pra ver se tamo safe
      visited[v] = false;
    }

    neighbors = 0;
  }
Graph::~Graph(){//Destrutor
  cout <<"Destrutor chamado";
    adjMatrix.clear(); //limpeza de memória
  }

//Métodos de Manipulaçao da estrutura de dados
bool Graph::insert(const Edge& a){//Método para adicionar uma aresta no grafo

    vector<int> v = a.getPoints(); // vetor v recebe os vertices inicial e final da areata
    int w = a.getWeight(); // w receve o peso da aresta

    if ((v[0]> vertices) || (v[1]> vertices)){//verifica se colocar uma aresta num vertice nao presente no grafo
      cout<< "Vertice nao esta presente no grafo" << endl;
      return false;
    }
    if(v[0] == v[1]){//Verifica se tenta inserir um auto-ciclo, nao permitido
      cout << "Inserçao inválida: vertice para ele mesmo" << endl;
      return false;
    }
    if(adjMatrix[v[0]][v[1]]!=w){ // nova aresta
      if(adjMatrix[v[0]][v[1]] == 0){//caso seja uma aresta nova, nao somente uma alteraçao de peso, incrementa a quantidade de arestas
        edges++;
      }

      //altera os valores na matriz de adjacencia de forma simétrica
      adjMatrix.at(v[0]).at(v[1]) = w;
      adjMatrix.at(v[1]).at(v[0]) = w;


      return true;
    }
    else{ //aresta já se econtra no grafo
      return false;
    }
  }
bool Graph::remove(const Edge& a){//Método para remover uma aresta do grafo
    vector<int> v = a.getPoints(); // vetor v recebe os vertices inicial e final da areata
    int w = a.getWeight(); // w receve o peso da aresta
    if ((v[0]> vertices) || (v[1]> vertices)){//verifica se tenta utilizar um vétice nao presente no grafo
      cout<<"Vertice nao presente no grafo" << endl;
      return false;
    }
    if(v[0] == v[1]){ //tenta remover um auto-ciclo, sempre inexistente
      cout << "Remoçao invalida: vertice para ele mesmo" << endl;
      return false;
    }
    if(adjMatrix[v[0]][v[1]]==w){
      //coloca zero simetricamente na matriz de adjacencia
      adjMatrix.at(v[0]).at(v[1]) = 0;
      adjMatrix.at(v[1]).at(v[0]) = 0;
      edges--; //decrementa a quantidade de arestas
      return true;
    }
    else{ //aresta nao se encontra no grafo
      return false;
    }
  }
int Graph::numberVertices(){//Método para acessar a quantidade de vertices
    return vertices;
  }
int Graph::numberEdges(){//Método para acessar a quantidade de arestas
    return edges;
  }
bool Graph::edge(const Edge& a){ //Método para verificar se uma aresta está presente num grafo
    vector<int> v = a.getPoints(); // vetor v recebe os vertices inicial e final da areata
    int w = a.getWeight();// w receve o peso da aresta
    if ((v[0]> vertices) || (v[1]> vertices)){//verifica se tenta utilizar um vertice nao presente no grafo
      return false;
    }
    if(adjMatrix[v[0]][v[1]]!=w){ // caso o peso seja diferente de w, a aresta nao está presente
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
        if(adjMatrix[i][j]==0) //quando o peso é zero, significa que nao há aresta, logo, o grafo nao é completo
          return false;
      }
    }
    return true; // caso percorra toda a matriz sem encontrar zeros em i!=j, o grafo é completo
  }
void Graph::complete(){ //Método para completar um grafo
    if(isComplete()){//caso o grafo já esteja completo, nao faz nada
      return;
    }
    //percorre a matriz de adjacencia
    for(int i = 0; i < vertices; i++){
      for(int j = 0; j < vertices; j++){
        if(adjMatrix[i][j]==0){ //caso nao exista aresta, coloca 1, assume-se uma aresta de valor mínimo
          if(i == j){ continue;} //para todos os valores em que i==j, está num vétice, o peso deve sempre ser zero
          adjMatrix.at(i).at(j) = 1;
        }
      }
    }


  }
void Graph::print(){//funçao para impressao da matriz de adjacência
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
  vector<int> mstBeen, mstLack;//estruturar para guardar os vertices percorridos, nao percorridos
  Graph mst(vertices);//grafo a ser retornado como a árvore geradora mínima
  for(int i = 0; i< vertices; i++){mstLack.push_back(i);} // inicializaçao dos nao percorridos

  mstLack.erase(mstLack.begin()+start);//remove start dos nao percorridos
  mstBeen.push_back(start);//inicializaçao dos percorridos


  Edge menorAresta(0,0,INT_MAX); //Valores arbitrários para inicializaçao e inteiro máximo para a comparaçao funcionar

  vector<int> vaux; //vetor auxiliar para receber os vertices da menor aresta, atributos privados da classe Edge
  while(!mstLack.empty()){

      for(int iterator = 0; iterator<mstBeen.size();iterator++){ // procura a menor aresta que sai do conjunto
        current = mstBeen.at(iterator); //passa por todos os vertices em que já esteve
        for(int j=0;j<vertices;j++){
          if(adjMatrix[current][j] == 0){ //caso o peso seja igual a zero, nao há aresta
            continue;}
          if (find(mstBeen.begin(), mstBeen.end(), j) != mstBeen.end() ){//encontrou o valor de j(destino) nos vertices já percorridos e ignora
            continue;}
          if(adjMatrix[current][j] < menorAresta.getWeight()){ // caso o valor atual seja menor que o salvo na menor aresta
              menorAresta.modifiyEdge(current, j, adjMatrix.at(current).at(j));//coloca o valor da menor aresta encontrada no conjunto, saindo do atual até um destino j
            }
          }

        }

        //Nesse momento, menorAresta contem a menor aresta que sai do conjunto

      vaux = menorAresta.getPoints(); // utiliza o vetor auxiliar para receber os vertices da menor aresta
      mstBeen.push_back(vaux.at(1)); //inclui nos vertices já visitados o vertice incluso

      for(int m = 0; m<mstLack.size(); m++){//remove dos vertices que faltam o vertice incluso
          if(mstLack.at(m)==vaux.at(1)){
            mstLack.erase(mstLack.begin()+m);
            break;
          }
        }
        mst.insert(menorAresta); //insere a menor aresta na árvore mínima
        menorAresta.modifiyEdge(0,0,INT_MAX);//reseta o valor da menor aresta para que possa ser feita a comparaçao novamente no novo loop do while
      }

      return mst;
}
vector<int> Graph::bfs(int start){ //Método para realizar a busca em largura no grafo;
  vector<int> bfs; // vetor que retorna a busca em largura
  queue<int> queue; //lista de controle
  vector<int> adjacents;//vetor de adjacentes do vertice atual
	bool visited[vertices]; //vertices visitados
	bool explored[vertices][vertices]; //arestas exploradas

	visited[start] = true;//inicializaçao necessária
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
				adjacents.push_back(i);//conjunto dos vertices adjacentes ao vertices atual.
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
				if(explored[current][neighbor] == false){ //mas a aresta nao
          //explora a aresta simetricamente
					explored[current][neighbor];
					explored[neighbor][current];
				}
		}
	}
	return bfs; //retorna o vetor com os vertices na ordem da busca
}
vector<int> Graph::dfs(int v){//Método para realizar a busca em proundidade no grafo


    visited[v]=true;



    neighbors = 0;
    for(int k = 0; k<vertices; k++){ //encontrou os vizinhos do vertice V nao marcados
      if(adjMatrix[v][k]!=0 && (!visited[k])){
        neighbors++;
      }
    }

    dfsVec.push_back(v);
    for(int i=0;i<vertices;i++){
        if((!visited[i])&&(adjMatrix[v][i]!=0)){


          for(int t = 0; t<dfsVec.size(); t++){
          }

          this->dfs(i);

      }
    }


    if(dfsVec.size() == vertices && v == *dfsVec.begin()){
      vector<int> v = dfsVec;
      dfsVec.clear();
      return v;
    }
}


int Graph::connected(){

  vector<int> v = this->dfs(); //chama dfs
  bool marked[vertices]; //gera a estrutura de marcaçao
  int cntAmt = 1; //variável para contar quantas componentes conexas há
  bool aux; //variável auxiliar
  if(v.size() != vertices){ // testa se o vetor de dfs tem o mesmo tamanho de vertices. Se tiver, pode retortar 1 diretamente
    int start = 0;

    while(aux){ //loop para percorrer o grafo

      for(int i = start; i<vertices; i++){
        if(find(v.begin(), v.end(), i) != v.end()){ //verifica se o vertice já foi buscado por dfs
          marked[i] = true; // se sim, marca o vertice
        }
        else{ // se nao
            v.clear();
            cntAmt++; //adiciona uma nova componente nao conectada
            v = this->dfs(i); //chama dfs novamente
            //manutençao do while
            start = i;
            aux = marked[0];
            for(int j=1; j < vertices; j++){
              aux = (marked[j] |= marked [j-1]); //seta a variáel aux para ser verdadeira somente quando todos os vertices tiverem sido buscados

            }
        }

      }


    }
    return cntAmt; //retorno das componentes conexas
  }
  else{ // o grafo só tem uma componente conexa, pode retornar 1
    return 1;
  }

}
vector<int> Graph::dijkstra(int start, int end){ //Método para encontrar o menor caminho entre dois vertices pelo algoritmo de dijkstra
  int dt[vertices]; //vetor com os menores caminhos até o vertice de cada elemento
  int rot[vertices]; // vetor com o antecessor no menor caminho até ele
  vector<int> toReturn;
  //inicializaçao dos vetores acima
  dt[start] = 0;
  rot[start] = INT_MAX;
  for(int i = start+1; i<vertices; i++){
    dt[i] = INT_MAX;
    rot[i] = 0;
  }

  //ESTRUTURAS DE MARCAÇao
  bool open[vertices];//valores nao olhados
  bool closed[vertices];//valores olhados

  int mindt = INT_MAX; //variável auxiliar para encontrar o menor dt
  int minVert; //variável auxiliar para guardar o menor vertice
  int whileCond = 0; // variável auxiliar para testar o while
  int minFinal; // variável auxiliar para decidir modificar o dt atual

  while (whileCond != vertices-start) {

    for(int j=start;j<vertices;j++){ //encontra o menor dt dentre os valores presentes em A.
      if(open[j] == false){ // j existe em open(considera-se falso por facilidade de incializaçao)
        if(mindt > dt[j]){ //caso o menor seja maior que o atual, salva o atual como menor
          mindt = dt[j];
          minVert = j; // guarda o vertice do menor
        }
      }
    }

    open[minVert] = true; //removido de open
    closed[minVert] = true; //incluído em closed, true por facilidade de inicializaçao

    for(int k = start; k< vertices; k++){ //Examina todos os adjacentes que nao estao em closed
			if((adjMatrix[minVert][k] != 0)&&(closed[k]==false)){
        minFinal = min(dt[k], dt[minVert]+adjMatrix[minVert][k]); //compara o valor do caminho direto com o valor do menor caminho+menor caminho até o atual
        if(minFinal < dt[k]){
          dt[k] = minFinal;
          rot[k] = minVert;
        }
			 }
  		}

    whileCond = 0; // reset da variável de teste do while
    mindt = INT_MAX; //reset da variável de teste
    for(int l = start; l<vertices; l++){ //Condiçao para saída do while
      if(open[l]==true){
        whileCond++;
      }
    }
  }

  //preenchimento do vetor de retorno
  int aux = end;
  toReturn.push_back(aux);
  while(aux != start){
    aux = rot[aux];
    toReturn.push_back(aux);
  }
  reverse(toReturn.begin(),toReturn.end()); //coloca os valores dos vertices em ordem crescente
  toReturn.push_back(dt[end]); //adiciona o comprimento do caminho no final do vetor
  return toReturn;
}
vector<int> Graph::travSales(int start){ //Método para resolver o problema do caixeiro viajante à partir de um vertice inicial
  //completa o grafo caso ele nao seja completo
  this->complete();



  vector<int> vert; //Vertices a serem   olhados
  vector<int> path; //Menor caminho atual
  vector<int> minPath; //Menor caminho global

  for(int i = 0; i<vertices; i++){ //coloca todos os vertices menos o inicial no vetor
    if(i != start){
      vert.push_back(i);
    }
  }

  int minRt= INT_MAX; //cria uma variável de teste para a menor rota(soma dos pesos) inicializada com o maior inteirom  para comparaçao
  int currentRt;
  int next;

  do {
        currentRt = 0; // rota atual;
        path.clear(); //limpa o caminho atual

        next = start; //inicializa o próximo com o inicial para começar a passar pelo grafo
        path.push_back(start); // coloca no caminho o inicial
        for (int i = 0; i < vert.size(); i++) { //percorre os vertices

            currentRt = currentRt + adjMatrix[next][vert[i]]; //adiciona a rota atual percorrendo a matriz de adjacencia
            next = vert.at(i); // coloca o pŕoximo valor da matriz em next
            path.push_back(next); // adiciona o vertice no caminho
        }
        currentRt = currentRt + adjMatrix[next][start]; // adiciona na rota a distância do ponto final ao inicial
        path.push_back(start); // coloca o inicial no caminho após completar a volta



        if(minRt > currentRt){ //caso a rota calculada seja menor que a salva, troca
          minRt = currentRt;
          minPath = path;

        }


    } while (next_permutation(vert.begin(), vert.end())); //modifica o vetor de vertices para serem observadas todas as suas permutações, olhando toda as combinações possíveis de vertices


    minPath.push_back(minRt); //coloca no final do vetor de caminho mínimo a rota mínima
    return minPath; // retorna a soluçao do probl


}
