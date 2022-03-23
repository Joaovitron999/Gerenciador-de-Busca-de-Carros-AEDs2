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

using namespace std;

//estrutura de dados dos carros
struct Carro{  
  char modelo[30];  
  char marca[30];  
  char tipo;
  int ano;
  float km;
  float potencia;
  char combustivel[30];
  char cambio[30];
  char direcao[30];
  char cor[30];
  int portas;
  char placa[10];
};

//Estrutura dos nós da lista principal
class No{
  public:
    Carro carro;
    No* proxNo;
    private:
  	int v;
  	No* prox;
  
  	No(Carro c) // construtor
  	{
  		this->carro = c;
  		this->proxNo = NULL;
  	}
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

};
//Ler Arquivos
void ler(){
  cout << "lendo";
  
}

//funçoes
int menu(){
  Lista mainLista;
  int resposta;
  system("clear||cls"); //Limpar a tela (Funciona tanto   em linux ou windows)
  cout << "Opção 1 -------------------- 1"<<endl;
  cout << "Opção 2 -------------------- 2"<<endl;
  cout << "Opção 3 -------------------- 3"<<endl;
  cout << "Opção 4 -------------------- 4"<<endl;
  cout << "Opção 5 -------------------- 5"<<endl;
  cout << "Opção 6 -------------------- 6"<<endl;
  cout << "Sair ----------------------- 0"<<endl;

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

int main(){
  int resposta;
  ler();
  
  do
  {
    resposta = menu();

  }
  while(resposta!=0&&false);

  
  return 0;
}