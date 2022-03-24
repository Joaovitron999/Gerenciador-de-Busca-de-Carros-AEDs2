#include "biblioteca.h"
#include <iostream>
#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

int fmenu(){        ///NAO FUNCIONOU
  int resposta;
  cout << "------------------------------"<<endl;
  cout << "Opção 1 -------------------- 1"<<endl;
  cout << "Opção 2 -------------------- 2"<<endl;
  cout << "Opção 3 -------------------- 3"<<endl;
  cout << "Opção 4 -------------------- 4"<<endl;
  cout << "Opção 5 -------------------- 5"<<endl;
  cout << "Opção 6 -------------------- 6"<<endl;
  cout << "Sair ----------------------- 0"<<endl;

  cout << "\nEscolha uma opção\n"<<endl;
  cin >> resposta;

  return resposta;
}