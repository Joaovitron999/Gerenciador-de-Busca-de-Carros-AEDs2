/*------------------------------------------------------------------------/
/ Universidade Federal de Alfenas -Gerenciador-de-Busca-de-Carros-AEDs2  /
/ Nome: Caio Eduardo Marcondes     // Matrícula: 2020.1.08.035          /
/ Nome: João Vitor Fonseca         // Matrícula: 2020.1.08.003         /
/ Nome: Pedro Henrique Borges Luiz // Matrícula: 2020.1.08.036        /
/ Data: 2022                                                         /
-------------------------------------------------------------------*/
#include "biblioteca.h"
#include <iostream>
#include <fstream>

using std::cout; using std::cerr;
using std::endl; using std::string;

using namespace std;

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

//Estrutura dos nós da lista principal
class No{
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
		No* novo_no = new No();
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
          }else{
            anterior->proxNo = no->proxNo;
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
          }else{
            anterior->proxNo = no->proxNo;
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
		No* novo_no = new No();
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
  //cabeca = alloc();
	No* cauda; // último elemento
  int tamanho = 0;//apenas para registrar qntdd de nós na lista

  Fila()
  {
    // se não passar elemento, então cabeca e cauda são NULL
    cabeca = NULL;
    cauda = NULL;

  }
  void inserir(Carro c)
	{
		No* novo_no = new No();
    novo_no->carro = c;

    No* no;

    if(cabeca==NULL && cauda==NULL){
      cabeca = novo_no;
      cauda = novo_no; //23
    }
    else{
     // novo_no->proxNo = cabeca->proxNo;
      no = cabeca;
      while(no!=NULL){
        if(no == cauda){
          cauda->proxNo = novo_no;
          cauda = novo_no;
          cout << "A" <<endl;
        }
        no->proxNo = novo_no;
      }
    }
	}
  //remove  

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

//Main

int main(){
  int resposta;
  Lista mainLista;
  Pilha pilha;
  Fila fila;

  string relatorio = "";
  
  lerParaLista(&mainLista);
  string aux;
  Carro carroR;

  //parametros para busca em fila com 2 
  Carro carroP1;
  Carro carroP2;

  do{
      resposta = menu(); //Loop comentado 
      switch (resposta)
      {
       case 1:
          system("clear||cls"); //Limpar a tela (Funciona tanto em linux ou windows
          exibeLista(mainLista.cabeca);
          relatorio=(relatorio+"Lista exibida | ");
       break;
    
       case 2:
          system("clear||cls"); //Limpar a tela (Funciona tanto em linux ou windows
          incluirVeiculo(&mainLista);
          relatorio=(relatorio+"Carro incluído | ");
       break;
        
        case 3:
          system("clear||cls"); //Limpar a tela (Funciona tanto em linux ou windows
          cout << "\n\t\t\t Escreva o conjunto que deseja excluir\n \n\tPor exemplo - Digite 'RENAULT' para excluir todos da mesma Marca. \n (Tipo/Ano/Modelo/Combustível/Câmbio/Direção/Cor/Portas/Km/Marca/Potência)\n \nConjunto:";
          
            
            cin >> aux;
            carroR.modelo = aux;
            carroR.marca = aux;
            carroR.tipo = aux;
            carroR.ano = aux;
            carroR.km = aux;
            carroR.potencia = aux;
            carroR.combustivel = aux;
            carroR.cambio = aux;
            carroR.direcao = aux;
            carroR.cor = aux;
            carroR.portas = aux;
            carroR.placa = aux;            
            
            removeColetivo(carroR,&mainLista);
            removeColetivo(carroR,&mainLista);
            relatorio=(relatorio+"Exclusão coletiva ("+aux+")  |");  
        break;
  
        case 4:
            system("clear||cls"); //Limpar a tela (Funciona tanto em linux ou windows
            cout << "\n\t\t\tPlaca do veículo a ser excluido: ";
            
            cin >> carroR.placa;
            removeEspecifico(carroR,&mainLista);
            removeEspecifico(carroR,&mainLista);
            relatorio=(relatorio+"Exclusão de Carro ESPECÍFICO ("+carroR.placa+") | ");
        break;

        case 5:
          system("clear||cls"); //Limpar a tela (Funciona tanto em linux ou windows
          cout << "\n\t\t\t Escreva a primeira opção do conjunto que deseja Buscar\n \n\tPor exemplo - Digite 'RENAULT' para buscar todos da mesma Marca. \n (Tipo/Ano/Modelo/Combustível/Câmbio/Direção/Cor/Portas/Km/Marca/Potência)\n \nConjunto:";
          cin >> aux;
          carroP1.modelo = aux;
          carroP1.marca = aux;
          carroP1.tipo = aux;
          carroP1.ano = aux;
          carroP1.km = aux;
          carroP1.potencia = aux;
          carroP1.combustivel = aux;
          carroP1.cambio = aux;
          carroP1.direcao = aux;
          carroP1.cor = aux;
          carroP1.portas = aux;
          carroP1.placa = aux;    
          

          cout << "\n\t\t\t Adicionar mais um filtro á busca? (1)SIM,(2)Não\n \n\t";
          cin >> aux;
          if(aux=="1"){
            cout << "\n\t\t\t Escreva a segunda opção do conjunto que deseja Buscar\n \n\tPor exemplo - Digite 'RENAULT' para buscar todos da mesma Marca. \n (Tipo/Ano/Modelo/Combustível/Câmbio/Direção/Cor/Portas/Km/Marca/Potência)\n \nConjunto:";
            cin >> aux;
            carroP2.modelo = aux;
            carroP2.marca = aux;
            carroP2.tipo = aux;
            carroP2.ano = aux;
            carroP2.km = aux;
            carroP2.potencia = aux;
            carroP2.combustivel = aux;
            carroP2.cambio = aux;
            carroP2.direcao = aux;
            carroP2.cor = aux;
            carroP2.portas = aux;
            carroP2.placa = aux;    

            
            buscaPilha(carroP1,carroP2,mainLista.cabeca,&pilha);
          }else{
            buscaPilha(carroP1,carroP1,mainLista.cabeca,&pilha);            
          }

          exibeLista(pilha.cabeca);
          
        break;

        case 6:
          system("clear||cls"); //Limpar a tela (Funciona tanto em linux ou windows
          cout << "\n\t\t\t Escreva a primeira opção do conjunto que deseja Buscar\n \n\tPor exemplo - Digite 'RENAULT' para buscar todos da mesma Marca. \n (Tipo/Ano/Modelo/Combustível/Câmbio/Direção/Cor/Portas/Km/Marca/Potência)\n \nConjunto:";
          cin >> aux;
          carroP1.modelo = aux;
          carroP1.marca = aux;
          carroP1.tipo = aux;
          carroP1.ano = aux;
          carroP1.km = aux;
          carroP1.potencia = aux;
          carroP1.combustivel = aux;
          carroP1.cambio = aux;
          carroP1.direcao = aux;
          carroP1.cor = aux;
          carroP1.portas = aux;
          carroP1.placa = aux;    
          

          cout << "\n\t\t\t Adicionar mais um filtro á busca? \n\t\t\t(1)SIM, (2)Não\n \n\t";
          cin >> aux;
          if(aux=="1"){
            cout << "\n\t\t\t Escreva a segunda opção do conjunto que deseja Buscar\n \n\tPor exemplo - Digite 'RENAULT' para buscar todos da mesma Marca. \n (Tipo/Ano/Modelo/Combustível/Câmbio/Direção/Cor/Portas/Km/Marca/Potência)\n \nConjunto:";
            cin >> aux;
            carroP2.modelo = aux;
            carroP2.marca = aux;
            carroP2.tipo = aux;
            carroP2.ano = aux;
            carroP2.km = aux;
            carroP2.potencia = aux;
            carroP2.combustivel = aux;
            carroP2.cambio = aux;
            carroP2.direcao = aux;
            carroP2.cor = aux;
            carroP2.portas = aux;
            carroP2.placa = aux;    

            
            buscaFila(carroP1,carroP2,mainLista.cabeca,&fila);
          }else{
            buscaFila(carroP1,carroP1,mainLista.cabeca,&fila);            
          }

          exibeLista(fila.cabeca);
          
        break;
  
        case 7:
          system("clear||cls"); //Limpar a tela (Funciona tanto em linux ou windows
          cout << "RELATÓRIO DO USUÁRIO:  | ";
          cout <<  relatorio;
        break;
       
        
      }
  }while(resposta!=0);

  return 0;
}