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

//Criar Fila

//Ler Arquivos
void ler(){

  
}

//funçoes
int menu(){
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
  while(resposta!=0);

  
  return 0;
}