#include <iostream>
#include <bits/stdc++.h>
#include <cstdlib>
#include <fstream>

using namespace std;

using std::cout; using std::cerr;
using std::endl; using std::string;

//estrutura de dados dos carros
struct Carro{  
  string modelo;  
  string marca;  
  string tipo;
  string ano;
  string km;
  string potencia;
  string combustivel;
  string cambio;
  string direcao;
  string cor;
  string portas;
  string placa;

  bool comparacaoTotal(Carro* c){
    return  (c->placa == placa);
  }
  bool comparacaoParcial(Carro* c){
    return  (c->modelo == modelo ||
             c->marca == marca ||
             c->tipo == tipo ||
             c->ano == ano ||
             c->km == km ||
             c->potencia == potencia ||
             c->combustivel == combustivel ||
             c->cambio == cambio ||
             c->direcao == direcao ||
             c->cor == cor ||
             c->portas == portas ||
             c->placa == placa);
  }
};

//funcao q exibe carro
void exibeCarro(Carro c1){
  if(c1.placa !=""){
    cout <<"\n\t-----------------------------------------------------------------------------------------------------------\n";
  cout <<"\tModelo: ["<< c1.modelo <<"] | ";
  cout <<"Marca: [" << c1.marca <<"] | ";
  cout <<"Tipo: [" << c1.tipo <<"] | ";
  cout <<"Ano: [" << c1.ano <<"] | ";
  cout <<"Km: [" << c1.km <<"] | ";
  cout <<"Potência: [" << c1.potencia <<"] | "<<endl;
  cout <<"\tCombustível: [" << c1.combustivel <<"] | ";
  cout <<"Câmbio: [" << c1.cambio <<"] | ";
  cout <<"Direção: [" << c1.direcao <<"] | ";
  cout <<"Cor: [" << c1.cor <<"] | ";
  cout <<"Portas: [" << c1.portas <<"] | ";
  cout <<"Placa: [" << c1.placa <<"] | ";
  cout <<"\n\t-----------------------------------------------------------------------------------------------------------\n";
    }
}

//Estrutura dos nós da lista principal
class No
{
  public:
    Carro carro;
    No* proxNo;
};
//Estrurura da lista principal 

class Lista
{
public:
	No* cabeca; // primeiro elemento
	No* cauda; // último elemento
  int tamanho = 0;//apenas para registrar qntdd de nós na lista

  Lista()
  {
    // se não passar elemento, então cabeca e cauda são NULL
    cabeca = NULL;
    cauda = NULL;

  }

  void inserir(Carro c)
	{
		No* novo_no; 
    novo_no = new No();
    novo_no->carro = c;

		if(cabeca==NULL)
		{
			cabeca = novo_no;
			cauda = novo_no;
		}
		else
		{
			novo_no->proxNo = cabeca;
			cabeca = novo_no;
		}
    tamanho++;
    
    //Ordenar
    No* no;
    No* auxNo;
    no = cabeca;
    
    while(no!=NULL && no->proxNo != NULL){
      if(no->carro.placa > no->proxNo->carro.placa){
        auxNo->carro = no->proxNo->carro;
        no->proxNo->carro = no->carro;
        no->carro = auxNo->carro;
      }
      no = no->proxNo;
    }
	}
};

void removeEspecifico(Carro c, Lista* lista)
	{
    No* no;
    No* anterior;
    
    if(lista->cabeca!=NULL){
    no = lista->cabeca;
    anterior = no;
    
    while(no!=NULL){
        if(no->carro.comparacaoTotal(&c)){
          if (no==lista->cabeca){
            lista->cabeca = no->proxNo;
            free(no);
          }else{
            anterior->proxNo = no->proxNo;
            free(no);
          }
          lista->tamanho--;
        }
        anterior = no;
        no = no->proxNo;
      }
    }
  }

void removeColetivo(Carro c, Lista* lista)
	{
    No* no;
    No* anterior;
    

    
    if(lista->cabeca!=NULL){
    no = lista->cabeca;
    anterior = no;
    
    while(no!=NULL){
        if(no->carro.comparacaoParcial(&c)){
          if (no==lista->cabeca){
            lista->cabeca = no->proxNo;
            free(no);
          }else{
            anterior->proxNo = no->proxNo;
            free(no);
          }
          lista->tamanho--;
        }
        anterior = no;
        no = no->proxNo;
      }
    }
  }

//Pilha de busca
class Pilha
{
public:
	No* cabeca; // primeiro elemento
	No* cauda; // último elemento
  int tamanho = 0;//apenas para registrar qntdd de nós na lista

  Pilha()
  {
    // se não passar elemento, então cabeca e cauda são NULL
    cabeca = NULL;
    cauda = NULL;

  }
  void inserir(Carro c)
	{
		No* novo_no;
    novo_no = new No();
    novo_no->carro = c;

    if(cabeca==NULL){
      cabeca = novo_no;
      cauda = novo_no; //23
    }
    else{
     // novo_no->proxNo = cabeca->proxNo;
		  //cabeca = novo_no;
      novo_no->proxNo = cabeca;
      cabeca = novo_no;
    }
	}
  void remover(){
    //desalocar memória
    cabeca = cabeca->proxNo;
  }
};

//Pilha de busca
class Fila
{
public:
	No* cabeca; // primeiro elemento
	No* cauda; // último elemento
  int tamanho = 0; //apenas para registrar qntdd de nós na lista

  Fila()
  {
    // se não passar elemento, então cabeca e cauda são NULL
    cabeca = NULL;
    cauda = NULL;
  }

  void inserir(Carro c)
  {
    No* novoNo = new No;

    novoNo->carro = c;

    if (tamanho <= 0) {
        novoNo->proxNo = NULL;
        cabeca = novoNo;
        cauda = novoNo;
    } else {
        novoNo->proxNo = NULL;
        cauda->proxNo = novoNo;
        cauda = novoNo;
    }
    tamanho++;
  }
};

//buscar em pilha
void buscaPilha(Carro c1,Carro c2,No* cabecaLista,Pilha* pilha){
  No* no = cabecaLista;
  do{
      if(no->carro.comparacaoParcial(&c1) && no->carro.comparacaoParcial(&c2)){
        pilha->inserir(no->carro);
      }
      no = no->proxNo;
  }
    while(no!=NULL);
}

//buscar em fila
void buscaFila(Carro c1,Carro c2,No* cabecaLista,Fila* fila){
  No* no = cabecaLista;
  do{
      if(no->carro.comparacaoParcial(&c1) && no->carro.comparacaoParcial(&c2)){
        fila->inserir(no->carro);
        no=NULL;
      }
      no = no->proxNo;
  }
    while(no!=NULL);
}


//Exibir elementos de uma lista
void exibeLista(No* cabeca){
  No* no;
  if(cabeca!=NULL){
    no = cabeca;
    system("clear||cls"); //Limpar a tela (Funciona tanto   em linux ou windows)
    while(no!=NULL){
      exibeCarro(no->carro);
      no = no->proxNo;
    }
  }
}
//Ler Arquivos
void lerParaLista(Lista *lista){
    string word;
    Carro c1; 
     
    ifstream arquivo("BD_veiculo.txt");
    if (!arquivo.is_open()) {
      cout << "ERRO ao abrir arquivo";
    }

    //Ignorar cabeçalho arquivo---
    for(int i = 0;i<13;i++){
      arquivo >> word;
    }
    word = "";                
    //----------------------------

    //Ler carros
    while(!arquivo.eof()){
    
    arquivo >> c1.modelo;
    arquivo >> c1.marca;
    arquivo >> c1.tipo;
    arquivo >> c1.ano;
    arquivo >> c1.km;
    arquivo >> c1.potencia;
    arquivo >> c1.combustivel;
    arquivo >> c1.cambio;
    arquivo >> c1.direcao;
    arquivo >> c1.cor;
    arquivo >> c1.portas;
    arquivo >> c1.placa;
    //Add na lista
    lista->inserir(c1);
  }
  arquivo.close();
}

//funçoes
int menu(){
  int resposta;
  //system("clear||cls"); //Limpar a tela (Funciona tanto em linux ou windows

  //inclusão, exclusão, buscas e relatório;
  cout << "\n\n\n\t\t\t ______________[Menu]_______________ "<<endl;
        cout << "\t\t\t|                                   |"<<endl;
        cout << "\t\t\t|  Exibir Lista de veículos ---- 1  |"<<endl;
        cout << "\t\t\t|  Incluir veículo ------------- 2  |"<<endl;
        cout << "\t\t\t|  Remover veículo COLETIVAMENTE 3  |"<<endl;
        cout << "\t\t\t|  Remover veículo ESPECÍFICO -- 4  |"<<endl;
        cout << "\t\t\t|  BUSCA EM PILHA -------------- 5  |"<<endl;
        cout << "\t\t\t|  BUSCA EM FILA --------------- 6  |"<<endl;
        cout << "\t\t\t|  Mostrar Relatório ----------- 7  |"<<endl;
        cout << "\t\t\t|  Sair ------------------------ 0  |"<<endl;
        cout << "\t\t\t|___________________________________|\n\n"<<endl;

  cout << "\nEscolha uma opção"<<endl;
  
  cin >> resposta;
  if(resposta<0||resposta>7){
    return menu();
  }
  else
  {
    return resposta; 
  }
}

//Incluir veiculo
void incluirVeiculo(Lista* lista){
  Carro c1;
  cout << "\n\t\t\tInforme os dados: (sem espaços)"<<endl;

  cout << "\n\t\t\tModelo: ";
  cin >> c1.modelo;

  cout << "\n\t\t\tTipo: ";
  cin >> c1.tipo;

  cout << "\n\t\t\tAno: ";
  cin >> c1.ano;

  cout << "\n\t\t\tMarca: ";
  cin >> c1.marca;

  cout << "\n\t\t\tQuilometragem: ";
  cin >> c1.km;

  cout << "\n\t\t\tPotencia: ";
  cin >> c1.potencia;
  
  cout << "\n\t\t\tCombustível: ";
  cin >> c1.combustivel;
  cout << "\n\t\t\tCambio: ";
  cin >> c1.cambio;

  cout << "\n\t\t\tDireção: ";
  cin >> c1.direcao;
  cout << "\n\t\t\tCor: ";
  cin >> c1.cor;

  cout << "\n\t\t\tPortas: ";
  cin >> c1.portas;
  cout << "\n\t\t\tPlaca: ";
  cin >> c1.placa;

  system("clear||cls"); //Limpar a tela (Funciona tanto em linux ou windows

  cout <<  "\n\t\t\tCARRO ADICIONADO! "<<endl;
  exibeCarro(c1);
  lista->inserir(c1);
  
}