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

//funçoes
int menu(){
  int resposta;
  cout << "------------------------------"<<endl;
  cout << "Opção 1 -------------------- 1"<<endl;
  cout << "Opção 2 -------------------- 2"<<endl;
  cout << "Opção 3 -------------------- 3"<<endl;
  cout << "Opção 4 -------------------- 4"<<endl;
  cout << "Opção 5 -------------------- 5"<<endl;
  cout << "Opção 6 -------------------- 6"<<endl;
  cout << "Sair ----------------------- 0"<<endl;

  cout << "\nEscolha uma opção"<<endl;
  cin >> resposta;

  return resposta;
}

int main(){
 
  cout<<"TESTEEE"<<endl;
  int x = menu();
  return 0;
}