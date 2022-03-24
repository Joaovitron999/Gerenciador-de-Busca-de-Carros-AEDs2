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
  int ano;
  float km;
  float potencia;
  string combustivel;
  string cambio;
  string direcao;
  string cor;
  int portas;
  string placa;
};

//funcao q exibe carro
void exibeCarro(Carro c1){
  cout << c1.modelo <<endl;
  cout << c1.marca <<endl;
  cout << c1.tipo <<endl;
  cout << c1.ano <<endl;
  cout << c1.km <<endl;
  cout << c1.potencia <<endl;
  cout << c1.combustivel <<endl;
  cout << c1.cambio <<endl;
  cout << c1.direcao <<endl;
  cout << c1.cor <<endl;
  cout << c1.portas <<endl;
  cout << c1.placa <<endl;
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
	}
};
//Exibir elementos de uma lista
void exibeLista(Lista* lista){
  No* no;
  if(lista->cabeca!=NULL){
    no = lista->cabeca;
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
  //system("clear||cls"); //Limpar a tela (Funciona tanto   em linux ou windows)
  cout << "\n\n\n\t\t\t______________[Menu]________________"<<endl;
        cout << "\t\t\t|                                  |"<<endl;
        cout << "\t\t\t|  Exibir Lista de veículos --- 1  |"<<endl;
        cout << "\t\t\t|  Opção 2 -------------------- 2  |"<<endl;
        cout << "\t\t\t|  Opção 3 -------------------- 3  |"<<endl;
        cout << "\t\t\t|  Opção 4 -------------------- 4  |"<<endl;
        cout << "\t\t\t|  Opção 5 -------------------- 5  |"<<endl;
        cout << "\t\t\t|  Opção 6 -------------------- 6  |"<<endl;
        cout << "\t\t\t|  Sair ----------------------- 0  |"<<endl;
        cout << "\t\t\t|__________________________________|\n\n"<<endl;


  cout << "\nEscolha uma opção"<<endl;
  
  cin >> resposta;
  if(resposta<0||resposta>6){
    return menu();
  }
  else
  {
    return resposta; 
  }

}

//Main

int main(){
  int resposta;
  Lista mainLista;
  
  lerParaLista(&mainLista);
  
  do{
      resposta = menu(); //Loop comentado 
      switch (resposta)
      {
       case 1:
           exibeLista(&mainLista);
       break;
    
       case 2:
         //
       break;
      }
  }while(resposta!=0);

  return 0;
}