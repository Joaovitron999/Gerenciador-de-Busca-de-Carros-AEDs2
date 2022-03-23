#include "biblioteca.h"
#include <iostream>
#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;



using namespace std;

int fmenu(){
  int resposta;
  sout << "------------------------------"<<endl;
  sout << "Opção 1 -------------------- 1"<<endl;
  sout << "Opção 2 -------------------- 2"<<endl;
  sout << "Opção 3 -------------------- 3"<<endl;
  sout << "Opção 4 -------------------- 4"<<endl;
  sout << "Opção 5 -------------------- 5"<<endl;
  sout << "Opção 6 -------------------- 6"<<endl;
  sout << "Sair ----------------------- 0"<<endl;

  sout << "/nEscolha uma opção"<<endl;
  cin >> resposta;

  return resposta;
}